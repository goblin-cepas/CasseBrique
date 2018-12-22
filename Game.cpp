#include "Game.h"
#include "window.h"
#include "Configuration.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
Game::Game()
  :m_level(),m_timer(),m_pause(true),m_help(false)
{
  timer defaultTimer;
  defaultTimer.c=1000;
  this->setTimer(defaultTimer);
}

Game::Game(Level newLevel)
  :m_level(newLevel), m_timer(), m_pause(true), m_help(false)
{
  timer defaultTimer;
  defaultTimer.c=1000;
  this->setTimer(defaultTimer);
}

Game::Game(const Game& orig)
  :m_level(orig.getLevel()),m_timer(orig.getTimer()),m_pause(orig.getPause()),m_help(orig.getHelp())
{
}

Game::~Game() {
  m_level.~Level();
}

Level Game::getLevel()const{return m_level;}
timer Game::getTimer()const{return m_timer;}
bool Game::getPause()const{return m_pause;}
bool Game::getHelp()const{return m_help;}

void Game::setLevel(Level& newLevel){m_level=newLevel;}
void Game::setTimer(timer newTimer){m_timer=newTimer;}
void Game::setPause(bool newPause){m_pause=newPause;}
void Game::setHelp(bool newHelp){m_help=newHelp;}


bool Game::update(){
  int ch;
 this->interrupt(ch);
  //update tout les objets dans un certain ordre + gérer la pause/aide
  if(this->getPause()==true){
   //On le display sur le plateau de jeu
    return false;
  }
  else{ 
    // we update the state of each object on the board

    m_level.getTabPaddle()[0].move();
/*
    for(size_t i=0;i<m_level.getTabBrick(); i++){
		this->getLevel().m_TabBrick[i].hit(m_TabBrick[i]);
    }

    for(size_t i=0;i<m_level.getTabBall(); i++){
      	this->getLevel().m_TabBall[i].move();
    }
*/
    
    timer new_timer;
    new_timer.c=(this->getTimer().c)-1; 
    this->setTimer(new_timer);
    

    
    return true;
  }
}

bool Game::quit(int key){
  if((key=getch())=='q'){    
    //Appeler Save
    //quitter la partie et revenir au menu
    this->~Game();
    return true;
  }
  else{
    return false;
  }
}

bool Game::interrupt(int key){
  bool hasBeenInterrupted=false;
  if(this->getPause()==false){
      switch(key=getch()){
        case 'p':
          {
          Window pauseScreen(10,20,110,20,'+');
          do{
            pauseScreen.setCouleurBordure(BRED);
            pauseScreen.setCouleurFenetre(WBLACK);
            pauseScreen.print(7,3,"Paused");
            this->setPause(true);
            }while((key=getch())!='p');
          hasBeenInterrupted=true;
          break;
        }
        case 'h':
          {
          this->setPause(true);
          this->setHelp(true);
          Window helpScreen(20,45,2,15,'+');
          Window pauseScreen(10,20,110,20,'+');
          do{
            pauseScreen.setCouleurBordure(BRED);
            pauseScreen.setCouleurFenetre(WBLACK);
            pauseScreen.print(7,3,"Paused");
            helpScreen.setCouleurBordure(BRED);
            helpScreen.setCouleurFenetre(WBLACK);
            helpScreen.print(1,1,"This is the help screen!");
            helpScreen.print(1,4,"To move the paddle press '<-' or '->'");
            helpScreen.print(1,7,"To launch the ball press the spacebar key");
            helpScreen.print(1,10,"To resume the game press the 'h' key");
            helpScreen.print(1,13,"To just pause the game press the 'p' key");
    	     }while((key=getch())!='h');
          helpScreen.setCouleurBordure(WBLACK);
    	   hasBeenInterrupted=true;
         break;
       }
    }
    
  }
  this->setPause(false);
  return hasBeenInterrupted;
}

bool Game::launch(int key){
  if((key=getch())==' '){
    this->setPause(false);
    return true;
  }
  else{ 
    return false;
  }
}

//Une fct void runGame() ?????
void runGame(Game *testGame){
  int ch;
  int ch2;
  int h=45,w=140;
  
  std::cout<<testGame->getTimer().c<<std::endl; 
  
  Window menuScreen(5,80,50,1,'+');
  Window gameScreen(h,w,50,10,'+');	
  bool launched=false;
  do{
  	menuScreen.setCouleurBordure(BRED);
  	menuScreen.setCouleurFenetre(WBLACK);
  	menuScreen.print(1,1,"Press Space to launch the ball !");
    launched = testGame->launch(ch);
    for(size_t x=0;x<w;++x){
      for (size_t y=0;y<h;++y){
      	gameScreen.print(x,y,'-',WRED);
      	
      }
  	}
    usleep(600);
   }while(launched==false);
   menuScreen.clear();
   std::vector<playerScore> tabScore=testGame->getLevel().createMenu();
   short int tabI=0;short int cpt=0; int playerHp; int playerSc;
    do{	
    	playerHp=testGame->getLevel().getHp();
    	playerSc=testGame->getLevel().getScore();
    	menuScreen.clear();
    	menuScreen.setCouleurBordure(BRED);

  		/*------------------Score section of the menu------------------------*/
    	menuScreen.print(32,1,"Highscores: ", WBLUE);

  		if(tabI==0 && cpt<10){
  			menuScreen.print(32,2,tabScore[tabI].pseudo);
  			menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
  		}

  		if(tabI==1 && (cpt>=10 && cpt<20)){
  			menuScreen.print(32,2,tabScore[tabI].pseudo);
  			menuScreen.print(37,2,std::to_string(tabScore[tabI].score));	
  		}

  		if(tabI==2 && (cpt>=20 && cpt<30)){
  			menuScreen.print(32,2,tabScore[tabI].pseudo);
  			menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
  		}

  		if(tabI==3 && (cpt>=30 && cpt<40)){
  			menuScreen.print(32,2,tabScore[tabI].pseudo);
  			menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
  		}

  		if(tabI==4 && (cpt>=40 && cpt<50)){
  			menuScreen.print(32,2,tabScore[tabI].pseudo);
  			menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
  		}

  		if(tabI>4){tabI=0; cpt=0;}
  	
  	    cpt++;

    	if(((cpt==10 || cpt==20)||(cpt==30 || cpt==40)) || cpt==50){
    		tabI++;
   		}

  		/*------------------End score section -----------------------------*/
  		/*------------------Player Stats section of the menu---------------*/
  		
  		menuScreen.print(1,1,"Current Score: "+std::to_string(playerSc));
  		menuScreen.print(1,2,"Player life: "+std::to_string(playerHp));

  		/*------------------End player stats section-----------------------*/
  		/*------------------Help section of the menu-----------------------*/
  		
  		menuScreen.print(60,1,"Press 'h' for help");
  		menuScreen.print(60,2,"Press 'p' for pause");
  		menuScreen.print(60,3,"Hold 'q' to quit");

  		/*------------------End help section-------------------------------*/
  	
   		gameScreen.setCouleurBordure(BYELLOW);
    	testGame->interrupt(ch2);
    	std::cout<<testGame->getTimer().c<<std::endl;
    	for(size_t x=0;x<w;++x){
      		for (int y=0;y<h;++y){
      			if((x==testGame->getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x
               && y==testGame->getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.y)
              ||((x==testGame->getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x)
               &&y==testGame->getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y)){
              gameScreen.print(x,y,'P');
            }
        		else {
        			gameScreen.print(x,y,'-',WRED);
     			  }
      		}
    	}
    testGame->update();
    usleep(600);
  }while(testGame->getTimer().c!=0 && testGame->quit(ch)==false);
}


int main(){
  Configuration config;
  config.Init();
  Game testGame(config.getLevel(1));  
  startProgramX();
  runGame(&testGame);
  stopProgramX();
  return 0;
}