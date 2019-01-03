#include <string>
#include <fstream>
#include <ncurses.h>
#include <iostream>
#include "Home.h"
#include "window.h"
#include "Level.h"
#include "Save.h"
#include "Rectangle.h"
#include "Score.h"
#include "Configuration.h"
#include "Game.h"

int main(int argc, char** argv, char** env) {

    if (argv[1]) {
        std::string argv1 = argv[1];
        if (argv1 == "-A") {
            std::cout << "Authors : Sylvain Courroye, Josua Phillipot, Aurelie Besnier et Denis Beauget" << std::endl;
        }
        if (argv1 == "-V") {
            std::cout << " Version : 1.0" << std::endl;
        }
        if (argv1 == "-H") {
            std::cout << "This is the help screen  : " << std::endl;
            std::cout << "To move the paddle press '<-' or '->'\n"
                    << "To launch the ball press the spacebar key\n"
                    << "To resume the game press the 'h' key\n"
                    << "To just pause the game press the 'p' key" << std::endl;
        }
        if (argv1 == "-All") {
            std::cout << "The Authors : Sylvain Courroye, Josua Philippot, Aurélien Besnier et Denis Beauget" << std::endl;
            std::cout << " Version : 1.0" << std::endl;
            std::cout << "This is the help screen  : " << std::endl;
            std::cout << "To move the paddle press '<-' or '->'\n"
                    << "To launch the ball press the spacebar key\n"
                    << "To resume the game press the 'h' key\n"
                    << "To just pause the game press the 'p' key" << std::endl;
        }
        if (argv1 == "-C" && argv[2]) {
            std::string argv2 = argv[2];
            Configuration config(argv2);
            config.Init();
            Game testGame(config.getLevel(1));
        }

    } else {
        startProgramX();
        Home home;
        home.menu();
        stopProgramX();
    }
    return 0;
}
