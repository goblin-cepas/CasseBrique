#include "Game.h"
#include "window.h"
#include <unistd.h>
Game::Game()
  :m_level(),m_timer(),m_pause(true),m_help(false)
{
  timer defaultTimer;
  defaultTimer.c=200;
  this->setTimer(defaultTimer);
}

Game::Game(Level newLevel,timer newTimer, bool newPause, bool newHelp)
  :m_level(newLevel), m_timer(newTimer), m_pause(newPause), m_help(newHelp)
{
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

void Game::setLevel(Level newLevel){m_level=newLevel;}
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
    //update chaque objets
    /*for(size_t i=0;i<m_level.getNbBrick(); i++){
      m_level.getTabBrick()[i].hit(m_level.getTabBrick()[i]);
    }
    for(size_t i=0;i<m_level.getNbBall(); i++){
      m_level.getTabBall()[i].collide(m_level.getTabBall()[i]);
    }
    m_level.getTabPaddle()[0].move();*/
    timer new_timer;
    new_timer.c=(this->getTimer().c)-1;  //Pas sur de faire une struct timer ???
    this->setTimer(new_timer);
    

    
    return true;
  }
}

bool Game::quit(int key){
  if((key=getch())=='q'){
    //quitter la partie et revenir au menu
    //Appeler Save
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
    int ch;
    if((key=getch())=='h'){
        this->setPause(true);
        this->setHelp(true);
        Window helpScreen(20,30,10,10,'+');
        do{
        helpScreen.setCouleurBordure(BRED);
        helpScreen.setCouleurFenetre(WBLACK);
        helpScreen.print(1,1,"This is the help screen!");
        helpScreen.print(1,4,"To move the paddle press '<-'' or '->'");
        helpScreen.print(1,7,"To launch the ball press the spacebar key");
        helpScreen.print(1,10,"To resume the game press the 'h' key");
        helpScreen.print(1,13,"To just pause the game press the 'p' key");
    	}while((ch=getch())!='h');	
        //do stuff and display help
    	clear();
    	hasBeenInterrupted=true;
    }
    else if((key=getch())=='p'){
      Window pauseScreen(5,10,95,20,'+');
      do{
      	pauseScreen.print(1,1,"Paused");
        this->setPause(true);
      }while((ch=getch())!='p');
      clear();
      hasBeenInterrupted=true;
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
  int ch3;
  int h=40,w=140;
  std::cout<<testGame->getTimer().c<<std::endl; 
  Window menuScreen(5,80,50,1,'+');
  Window gameScreen(h,w,50,10,'+');	
  bool launched=false;
  do{
  	menuScreen.setCouleurBordure(BRED);
  	menuScreen.setCouleurFenetre(WBLACK);
  	menuScreen.print(1,1,"Press Space to launch the ball !");
    launched = testGame->launch(ch);
    for(size_t i=0;i<w;++i){
      for (int j=0;j<h;++j){
      	gameScreen.print(i,j,'-',WRED);
      	
      }
  	}
   }while(launched==false);
   menuScreen.clear();
   char* score ="500";
    do{
    	menuScreen.setCouleurBordure(BRED);
  		menuScreen.print(1,1,"Current Score: "+score);
  		menuScreen.print(1,2,"Player life:");
  		menuScreen.print(60,1,"Press 'h' for help");
  		menuScreen.print(60,2,"Press 'p' for pause");
  		//Printer le reste des info du menu(vie, score...)
   		gameScreen.setCouleurBordure(BYELLOW);
    	testGame->interrupt(ch2);
    	std::cout<<testGame->getTimer().c<<std::endl;
    	for(size_t i=0;i<w;++i){
      		for (int j=0;j<h;++j){
      			if(j==20 && i==45){
      				gameScreen.print(i,j,'@',WBLACK);
      			}
        		else {
        			gameScreen.print(i,j,'-',WRED);
     			}
      		}
    	}
    testGame->update();
    usleep(50);
  }while(testGame->getTimer().c!=0 && (ch3=getch())!='q');
}


int main(){
  Game testGame;
  startProgramX();
  runGame(&testGame);
  stopProgramX();
  return 0;
}