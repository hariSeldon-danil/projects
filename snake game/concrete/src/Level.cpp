#include "Level.hpp"
#include <sys/select.h> //select
#include <unistd.h> //stdin, null
#include <termios.h>    //termios for terminal interface
#include <iostream> //fgetc

Level::Level(int height, int width): 
                        m_playing(false),
                        m_rows(height + 2), 
                        m_cols(width +3), //2 for borders and one for '\n'
                        m_board(new Board(height + 2, width +3))
{}

Level::~Level()
{
    delete m_board;
}

int Level::ListenForInput()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void Level::SetCanonicalMode(int state) //set off input mode without enter key
{
    struct termios ttystate;
 
    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state== 1)  //NB_ENABLE
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state==0)  //NB_DISABLE
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

char Level::GetInput()
{
    char input = '\0';
    int fd_ = ListenForInput();
    if(!fd_ )
    {
        system("stty -icanon -echo");   //turning off echoing on terminal
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
    SetCanonicalMode(1);    //turn off enter as delimiter
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
            m_board->DrawTable();

        }
        //check score
    }
    SetCanonicalMode(0);    //turn back on enter as delimiter
    return level_success;
}

void Level::EndLevel()
{
    //display scores
}
