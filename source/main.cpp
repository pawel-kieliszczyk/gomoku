#include <exception>
#include <iostream>

#include "Game.hpp"


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
