#include "Home.h"
#include "window.h"
#include <iostream>
#include <ncurses.h>
#include "Score.h"
#include "Configuration.h"
#include "Level.h"
#include "Save.h"
#include "Game.h"

Home::Home() : m_selection(empty) {
}

Home::Home(select Selection) :
m_selection(Selection) {
}

Home::~Home() {
}

Home::select Home::getSelect()const {
    return this->m_selection;
}

void Home::userInterface() {



    int x, buff, one, two, three, four, five, six, seven, eight, nine;
    bool failed = false;
    Window menuWindow(50, 50, 0, 0);
    select c = empty;

    int ch;

    menuWindow.print(25, 10, "ARCADE 1", WRED);
    one = 10;
    x = 10;

    menuWindow.print(25, 11, "ARCADE 2");
    two = 11;

    menuWindow.print(25, 12, "ARCADE 3");
    three = 12;

    menuWindow.print(25, 13, "ARCADE 4");
    four = 13;

    menuWindow.print(25, 14, "ARCADE 5");
    five = 14;

    menuWindow.print(25, 15, "CAMPAIGN");
    six = 15;

    menuWindow.print(25, 16, "SCOREBOARD");
    seven = 16;

    menuWindow.print(25, 17, "CONTINUE");
    eight = 17;

    menuWindow.print(25, 18, "QUIT");
    nine = 18;

    buff = 10;
    while (((ch = getch()) != 'q')&&(c == empty)) {


        switch (ch) {
            case KEY_UP:
                x--;
                if (x < one) {
                    x = 10;
                }

                if (x == one) {

                    menuWindow.print(25, 10, "ARCADE 1", WRED);
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == two) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2", WRED);
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == three) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3", WRED);
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == four) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4", WRED);
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == five) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5", WRED);
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == six) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN", WRED);
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == seven) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD", WRED);
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == eight) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE", WRED);
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == nine) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT", WRED);

                }
                break;

            case KEY_DOWN:
                x++;
                if (x > nine) {
                    x = 18;
                }
                if (x == one) {

                    menuWindow.print(25, 10, "ARCADE 1", WRED);
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == two) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2", WRED);
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == three) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3", WRED);
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == four) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4", WRED);
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == five) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5", WRED);
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == six) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN", WRED);
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == seven) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD", WRED);
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == eight) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE", WRED);
                    menuWindow.print(25, 18, "QUIT");

                }
                if (x == nine) {

                    menuWindow.print(25, 10, "ARCADE 1");
                    menuWindow.print(25, 11, "ARCADE 2");
                    menuWindow.print(25, 12, "ARCADE 3");
                    menuWindow.print(25, 13, "ARCADE 4");
                    menuWindow.print(25, 14, "ARCADE 5");
                    menuWindow.print(25, 15, "CAMPAIGN");
                    menuWindow.print(25, 16, "SCOREBOARD");
                    menuWindow.print(25, 17, "CONTINUE");
                    menuWindow.print(25, 18, "QUIT", WRED);
                }
               
                break;
            case 10:
                refresh();
                if (x == one) {
                    c = arcade1;
                    ch = 0;
                }
                if (x == two) {
                    c = arcade2;
                    ch = 0;
                }
                if (x == three) {
                    c = arcade3;
                    ch = 0;
                }
                if (x == four) {
                    c = arcade4;
                    ch = 0;
                }
                if (x == five) {
                    c = arcade5;
                    ch = 0;
                }
                if (x == six) {
                    c = campaign;
                    ch = 0;
                }
                if (x == seven) {
                    c = scoreboard;
                    ch = 0;
                }
                if (x == eight) {
                    c = cont;
                    ch = 0;
                }
                if (x == nine) {
                    c = quit;
                }

                break;

        }
    }
    if (c == empty) {
        std::cerr << "ERROR : Selection ended with no option selected." << std::endl;
    }

    this->setSelect(c);
}

void Home::menu() {
    this->userInterface();
    Configuration config;
    config.Init();

    if (this->m_selection == empty) {
        std::cerr << "ERROR: Can't create or load a game, no game mode selected !" << std::endl;

    } else {
        if (m_selection == arcade1) {
            Level arc1(config.getLevel(1));
            Game game(arc1);
            runGame(game);
        } else if (m_selection == arcade2) {
            Level arc2(config.getLevel(2));
            Game game(arc2);
            runGame(game);
        } else if (m_selection == arcade3) {
            Level arc3(config.getLevel(3));
            Game game(arc3);
            runGame(game);
        } else if (m_selection == arcade4) {
            Level arc4(config.getLevel(4));
            Game game(arc4);
            runGame(game);
        } else if (m_selection == arcade5) {
            Level arc5(config.getLevel(5));
            Game game(arc5);
            runGame(game);
        } else if (m_selection == campaign) {
            Save cmpgn;
            int i = 1;
            while (i < 6) {
                Level Camp(config.getLevel(i));
                Game game(Camp);
                if (runGame(game)) {
                    cmpgn.setNbLevel(i);
                    cmpgn.writeSave(game.getLevel());
                    i = 6;
                } else {
                    i++;
                }
            }
        } else if (this->m_selection == scoreboard) {
            Score scoreboard;
            scoreboard.printScoreScreen();
        } else if (this->m_selection == cont) {
            Save savedGame;
            savedGame.loadSave(savedGame.getFile());
            Level loadedGame = *(savedGame.getLoadedGame());
            if (savedGame.getNbLevel() == -1) {
                Game lGame(loadedGame);
                runGame(lGame);
            } else if (savedGame.getNbLevel() > 0) {
                Game lGame(loadedGame);
                runGame(lGame);
                int i = savedGame.getNbLevel();
                while (i < 6) {
                    Level Camp(config.getLevel(i));
                    Game game(Camp);
                    if (runGame(game)) {
                        savedGame.setNbLevel(i);
                        savedGame.writeSave(game.getLevel());
                        i = 6;
                    } else {
                        i++;
                    }
                }
            } else {
                std::cerr << "ERROR, The savefile cannot be read : INVALID GAMETYPE"
                        << std::endl;

            }
        }
    }
}


void Home::setSelect(select New) {
    this->m_selection = New;

}