#include <string>
#include <fstream>
#include <ncurses.h>
#include <iostream>
#include "Home.h"
#include "window.h"
#include "Level.h"
#include "Save.h"
#include "Rectangle.h"

int main(int argc, char** argv) {
//    startProgramX();
    std::cout<<"COUCOU J'ARRIVE"<<std::endl;
    Save save;
    std::cout<<"AYE"<<std::endl;
   rectangle A;
    rectangle B;
    rectangle C;
    A.LeftBottom.x=20;
    A.LeftBottom.y=10;
    A.RightTop.x=30;
    A.RightTop.y=15;
    B.LeftBottom.x=30;
    B.LeftBottom.y=35;
    B.RightTop.x=25;
    B.RightTop.y=20;
    std::vector<Brick> bric;
    std::vector<Ball> bal;
    std::vector<Paddle> pad;
    Level test(25,A,B,bric,bal,pad,0,5,2); 
    std::cout<<"AYE6"<<std::endl;
    save.setFile("save4.cfg");
    std::cout<<save.getFile()<<std::endl;
    
    save.loadSave("save3.cfg");
    test = *(save.getLoadedGame());
    save.writeSave(test);
//    stopProgramX();
    std::cout<<"coucou"<<std::endl;
    return 0;
}

