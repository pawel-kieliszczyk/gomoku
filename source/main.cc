#include <exception>
#include <iostream>

#include "gomoku/game.h"


int main()
{
    try
    {
        Gomoku::Game gomokuGame;
        gomokuGame.play();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
