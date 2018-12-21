#include "Home.h"
#include "window.h"
#include <iostream>
#include <ncurses.h>
#include "Score.h"
//#include "Save.h"
//Colo);
//Color WRED(WRED);

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

bool Home::launcher() {
    if (this->m_selection == empty) {
        std::cerr << "LAUNCHING ERROR: Can't create or load a game, no game mode selected !" << std::endl;
        return true;
    } else {
        if (this->m_selection == scoreboard) {
            Score Scoreboard;
            Scoreboard.printScoreScreen();
        }
       /* if (this->m_selection == cont) {
            Save Savedgame();
            Savedgame.load();
        }
        else{
            Save Newgame("bricksave.save");
            Newgame.createsave(this->m_selection);
        }*/
    }

    return false;
}

void Home::setSelect(select New) {
    this->m_selection = New;

}

bool Home::userInterface() {

    /* NOTE POUR LE MOI DU PLUS TARD OU LE CAMARADE PERDU : Cette methode pour laquelle j'en ai chié (parce que
     je suis débile nécessite une optimisation certaine : tous les points de répétitions doivent être remplacés
     par une "sous méthode" pour faciliter la lecture du code, il faudrait également faire un truc plus
     propre pour la manipulation des coordonnées parce que je me suis perdu plein de fois dans ce code de 
     merde...*/

    
    int x, buff, one, two, three, four, five, six, seven, eight, nine; // ces variables vont stockées les X de chaque proposition, c'est degueulasse mais provisoire...
    bool failed = false;
    //    Colo);
    //   Color WRED(WRED);
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
                //x--;
                std::cerr << x;
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
                //x++;
                std::cerr << x;
                break;
            case 10: //le KEY_ENTER ne marchait pas, mais va savoir pourquoi 10 correspond a l'action d'appuyer sur entrer...
                refresh();
                if (x == one) {
                    c = arcade1;
                    ch = 0; // Je pense que cette instruction sert a rien, PENSER A LA SUPPRIMER
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
            default:
                //std::cerr<<"Josua est NULL"<<std::endl; //c'est du débug hein, en vrai j'suis plutot pas mal comme gars
                break;

        }
    }
    if (c != empty) {
        std::cout << "HOURRAY !" << std::endl;
    } else {
        failed = true;
    }
   
    this->setSelect(c);
    return failed;

}
