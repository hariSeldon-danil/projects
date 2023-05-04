#include <sys/select.h> //select
#include <unistd.h> //stdin, null
#include <iostream> //fgetc


#include "Level.hpp"
#include "LevelScore.hpp"

Level::Level(int height, int width, int base_score, int limit): 
                        m_playing(false),
                        m_rows(height + 2), 
                        m_cols(width +3), //2 for borders and one for '\n'
                        m_base_score(base_score),
                        m_limit(limit),
                        m_board(new Board(height + 2, width +3)),
                        m_level_score(new LevelScore(base_score))
{}

Level::~Level()
{
    delete m_board;
    delete m_level_score;
}

int Level::ListenForInput()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

char Level::GetInput()
{
    char input = '\0';
    int fd_ = ListenForInput();
    if(!fd_ )
    {
        system("stty -icanon -echo");   //turn off echoing on terminal
        input = fgetc(stdin);
    }
    return input;
}

bool Level::RespondToInput(char input)
{
    bool legal_move = true;
    switch (input)
    {
        case 'q': //quit       
            m_playing = false;
            break;
        
        case 's': //go down
            //update snake position
            legal_move = m_board->GetMonster()->MoveDown();
            break;
        
        case 'w': //go up
            //update snake position
            legal_move = m_board->GetMonster()->MoveUp();
            break;


        case 'a': //go left
            //update snake position
            legal_move = m_board->GetMonster()->MoveLeft();
            break;

        case 'd': //go right
            //update snake position
            legal_move = m_board->GetMonster()->MoveRight();
            break;

        default:
            break;
    }
    return legal_move;
}



bool Level::StartLevel()
{
    bool level_success = true;
    
    m_playing = true;
    
    
    while(m_playing)    //&& destined score not reached
    {
        m_board->DrawTable();
        char input = GetInput();

        if(!RespondToInput(input))
        {
            level_success = false;
            break;
        }
        else
        {
            m_board->CheckFood();

            //check level limit
            if(m_board->GetMonster()->GetBodyLinks() == m_limit)
            {
                break;
            }
        }
        //update score
        m_level_score->SetScore((m_board->GetMonster()->GetBodyLinks() - 1) * m_base_score);
        
    }
    return level_success;
}

void Level::EndLevel()
{
    //display scores
    std::cout << "\033[00;34mLEVEL SCORE " << std::endl;
    m_level_score->DisplayScore();
}
