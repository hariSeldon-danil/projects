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
    system("stty -icanon -echo");   //turn off echoing on terminal
    return fgetc(stdin);
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

void Level::ResetLevel()
{
    m_board->GetMonster()->ResetMonster();
}

bool Level::StartLevel()
{
    bool level_success = true;

    m_playing = true;
    int fd = 0;
    m_board->DrawTable();

    //snake starts by moving up
    char input = 'w';
    m_board->DrawTable();
    usleep(99900);
    do
    {
        while(level_success = RespondToInput(input))
        {  
            m_board->DrawTable();
            fd = ListenForInput();
            usleep(200000);
            if(fd) //keyboard hit
            {
                input = GetInput();
                if(input == 'q')
                {
                    m_playing = false;
                    break;
                }
            }
            else
            {
                m_board->CheckFood();

                //check level limit
                if(m_board->GetMonster()->GetBodyLinks() == m_limit)
                {
                    m_playing = false;
                    break;
                }
            }
            m_level_score->SetScore((m_board->GetMonster()->GetBodyLinks() - 1) * m_base_score);
        }
        m_board->DrawTable();
    } while (m_playing && level_success);
    
    return level_success;
}

void Level::EndLevel()
{
    //display scores
    std::cout << "\033[00;34mLEVEL SCORE " << std::endl;
    m_level_score->DisplayScore();
}
