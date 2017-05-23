#include <exception>
#include <iostream>

#include "game.h"


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
