#include "Game.h"
#include "window.h"
#include "Configuration.h"
#include "Log.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

Game::Game()
  :m_level(),m_timer(),m_pause(true),m_help(false)
{
  timer defaultTimer;
  time(&defaultTimer.start);
  time(&defaultTimer.end);
  defaultTimer.elapsed=difftime(defaultTimer.end,defaultTimer.end);
  this->setTimer(defaultTimer);
}

Game::Game(Level newLevel)
  :m_level(newLevel), m_timer(), m_pause(true), m_help(false)
{
  timer defaultTimer;
  time(&defaultTimer.start);
  time(&defaultTimer.end);
  defaultTimer.elapsed=difftime(defaultTimer.end,defaultTimer.end);
  this->setTimer(defaultTimer);
}


Game::~Game() {
  m_level.~Level();
}

Level Game::getLevel()const{return m_level;}
timer& Game::getTimer(){return m_timer;}
bool Game::getPause()const{return m_pause;}
bool Game::getHelp()const{return m_help;}

void Game::setLevel(Level& newLevel){m_level=newLevel;}
void Game::setTimer(timer newTimer){m_timer=newTimer;}
void Game::setPause(bool newPause){m_pause=newPause;}

void Game::setHelp(bool newHelp){m_help=newHelp;}


bool Game::update(Log &log){
  int ch; bool hasBeenUpdated=false;
  this->interrupt(ch,log);
  
  if(this->getPause()==true){
    return false;
  }
  else{
  		m_level.getTabPaddle()[0].move(log);

  		int timerSec=this->getTimer().elapsed;

  	    //Update of the timer
    	time(&this->getTimer().end);
    	unsigned int elaTmp = difftime(this->getTimer().end, this->getTimer().start);
    	this->m_timer.elapsed = elaTmp;
    
    	if(m_timer.elapsed-timerSec!=0 && hasBeenUpdated==false){
  			//Updating the ball
    		m_level.getTabBall()[0].move();
    		hasBeenUpdated=true;
		}
		else if(m_timer.elapsed-timerSec==0){
			hasBeenUpdated=false;
		}
    //Updating the state of each bricks
    for(size_t i = 0; i<getLevel().getTabBrick().size();i++){
      if(getLevel().getTabBrick()[i].getBrickPattern().LeftBottom.x==getLevel().getTabBall()[0].getBallPattern().LeftBottom.x 
        && getLevel().getTabBrick()[i].getBrickPattern().LeftBottom.y==getLevel().getTabBall()[0].getBallPattern().LeftBottom.y){
        m_level.getTabBrick()[i].hit();
      }
    }
  }
}

bool Game::quit(int key, Log &log){
  if((key=getch())=='q'){
  	std::string logEntry = std::to_string(key);
  	log.write(logEntry);
    Window quitScreen(10,20,80,20,'+');
    quitScreen.setCouleurBordure(BRED);
	quitScreen.setCouleurFenetre(WBLACK);
	quitScreen.print(2,3,"Are you sure you");
	quitScreen.print(3,4,"want to quit ?");
	quitScreen.print(8,7,"y/n",WBLUE);
	int ch;bool save=false,keypressed=false;
	do{
		switch (ch=getch()){
			case 'y':
			{
			 	std::string logEntry = std::to_string(ch);
  				log.write(logEntry);
				save=true;
				keypressed=true;
				break;
			}
			case 'n':
			{
			  	std::string logEntry = std::to_string(key);
  				log.write(logEntry);
				save=false;
				keypressed=true;
				break;
			}
		}
	}while(keypressed==false);
	if(save==true){
		Level currLevel=this->getLevel();
    	Save save;
    	save.writeSave(currLevel);

    	this->~Game();

    	return true;
	}
	else{
		return false;
	}
  }
  else{
    return false;
  }
}

bool Game::interrupt(int key,Log& log){
  bool hasBeenInterrupted=false;
    switch(key=getch()){
    case 'p':
      {
       	std::string logEntry = std::to_string(key);
  		log.write(logEntry);
      	Window pauseScreen(10,20,80,20,'+');
		this->setPause(true);
		pauseScreen.setCouleurBordure(BRED);
  		pauseScreen.setCouleurFenetre(WBLACK);
  		pauseScreen.print(7,3,"Paused");
		do{
			usleep(600);
		}while((key=getch())!='p');
		hasBeenInterrupted=true;
		break;
      }
    case 'h':
      {

      	std::string logEntry = std::to_string(key);
  		log.write(logEntry);
		Window helpScreen(20,45,2,15,'+');
		this->setPause(true);
		this->setHelp(true);
		Window pauseScreen(10,20,80,20,'+');
		pauseScreen.setCouleurBordure(BRED);
		pauseScreen.setCouleurFenetre(WBLACK);
		pauseScreen.print(7,3,"Paused");
		helpScreen.setCouleurBordure(BRED);
		helpScreen.setCouleurFenetre(WBLACK);
		helpScreen.print(1,1,"This is the help screen!",WBLUE);
		helpScreen.print(1,4,"To move the paddle press '<-' or '->'");
		helpScreen.print(1,7,"To launch the ball press the spacebar key");
		helpScreen.print(1,10,"To resume the game press the 'h' key");
		helpScreen.print(1,13,"To just pause the game press the 'p' key");
		do{
	  		usleep(600);
		}while((key=getch())!='h');
		helpScreen.setCouleurBordure(WBLACK);
		hasBeenInterrupted=true;
		break;
      } 
      this->setHelp(false);
    }
	this->setPause(false);
  return hasBeenInterrupted;
}

bool Game::launch(int key, Log &log){
  if((key=getch())==' '){
  	std::string logEntry = std::to_string(key);
  	log.write(logEntry);
    this->setPause(false);
    return true;
  }
  else{ 
    return false;
  }
}

bool runGame(Game &testGame){
  int ch;
  int h=35,w=60;

  Log log;
  
  Window menuScreen(5,80,50,1,'+');
  Window gameScreen(h,w,59,10,'+');	

  bool launched=false;
  
  velocity veloc;
  vector2 vectVeloc;
  vectVeloc.x = 0;
  vectVeloc.y = -1;
  veloc.accel = 1.6f;
  veloc.direction = vectVeloc;
  
  testGame.getLevel().getTabBall()[0].setVelocity(veloc);

  int tabB=0;
  Color brickColor;
  
  do{
    menuScreen.setCouleurBordure(BRED);
    menuScreen.setCouleurFenetre(WBLACK);
    menuScreen.print(1,1,"Press Space to launch the ball !");
    launched = testGame.launch(ch, log);
    /*------------------Display of the paddle--------------------------*/

    for(size_t x=0;x<w;++x){
      for (size_t y=0;y<h;++y){

	if((x==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x)
	   || (x==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x)){
	  
	  gameScreen.print(x,testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y,' ',WGREEN);
	  
	  for(int i=testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x-1;
	      i>=testGame.getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x+1; --i){
	    gameScreen.print(i,testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y,' ', WBLUE);
	  }
	}
	/*------------------End of the paddle display----------------------*/
	
	/*------------------Display of the bricks-------------------------*/
	
	else if((x==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x
		 && y==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y)
		|| ((x==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x)
		    && y==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y)){
	  if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==1){
	    gameScreen.print(x,y,' ',WCYAN);
	    brickColor=WCYAN;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==2){
	    gameScreen.print(x,y,' ',WBLUE);
	    brickColor=WBLUE;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==3){
	    gameScreen.print(x,y,' ',WYELLOW);
	    brickColor=WYELLOW;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==4){
	    gameScreen.print(x,y,' ',WGREEN);
	    brickColor=WGREEN;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==5){
	    gameScreen.print(x,y,' ',WRED);
	    brickColor=WRED;
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x;
	      i>=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x; --i ){
	    gameScreen.print(i,testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y,' ',brickColor);
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x;
	      i<=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x; ++i ){
	    gameScreen.print(i,testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y,' ',brickColor);
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y;
	      i>=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y; --i){
	    gameScreen.print(testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x,i,' ',brickColor); 
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y;
	      i<=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y; ++i){
	    gameScreen.print(testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x,i,' ',brickColor); 
	  }
	  
	  if(++tabB>=testGame.getLevel().getTabBrick().size()){tabB=0;}
	}
	
	/*------------------End display of the bricks--------------------*/

	/*------------------Display of the ball----------------------------*/
	
	else if((x==testGame.getLevel().getTabBall()[0].getBallPattern().LeftBottom.x
		 && y==testGame.getLevel().getTabBall()[0].getBallPattern().LeftBottom.y)
		|| ((x==testGame.getLevel().getTabBall()[0].getBallPattern().RightTop.x)
		    && y==testGame.getLevel().getTabBall()[0].getBallPattern().RightTop.y))
	  {
	    gameScreen.print(x,y,'@');
	  }
	
	/*------------------End display of the ball--------------------------*/
      }
    }
    
    usleep(600);
  }while(launched==false);
  gameScreen.setCouleurBordure(BYELLOW);
  std::vector<playerScore> tabScore=testGame.getLevel().createMenu();
  short int tabI=0; int playerHp; int playerSc;
  int timerSec; int timerSec5; int quit;bool quitTrouve;
  do{
    
    timerSec=testGame.getTimer().elapsed;
    playerHp=testGame.getLevel().getHp();
    playerSc=testGame.getLevel().getScore();
    if(timerSec%5==0){
      timerSec5=timerSec;
      menuScreen.clear();
      menuScreen.setCouleurBordure(BRED);
    }
    
    /*------------------Score section of the menu------------------------*/
    
    menuScreen.print(32,1,"Highscores: ", WBLUE);
    
    if(tabI==0 ){
      menuScreen.print(32,2,tabScore[tabI].pseudo);
      menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
    }
    
    if(tabI==1){
      menuScreen.print(32,2,tabScore[tabI].pseudo);
      menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
    }
    
    if(tabI==2){
      menuScreen.print(32,2,tabScore[tabI].pseudo);
      menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
    }
    
    if(tabI==3){
      menuScreen.print(32,2,tabScore[tabI].pseudo);
      menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
    }
    
    if(tabI==4){
      menuScreen.print(32,2,tabScore[tabI].pseudo);
      menuScreen.print(37,2,std::to_string(tabScore[tabI].score));
    }
    
    if(tabI>4){tabI=0;}  	  
    
    if(!(timerSec-timerSec5!=0)){
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
    
    /*------------------Displaying each objects on the board-----------*/
    for(size_t x=0;x<w;++x){
      for (size_t y=0;y<h;++y){
	
	/*------------------Display of the paddle--------------------------*/
	
	if(((x==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x)
	   || (x==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x))
     && y==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y){
	  
	  gameScreen.print(x,y,' ',WGREEN);
	       
	  for(int i=testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x-1;
	      i>=testGame.getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x+1; --i){
	    gameScreen.print(i,testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y,' ',testGame.getLevel().getTabPaddle()[0].getPaddleColor());
	  }
	}
	
	/*------------------End of the paddle display---------------------*/
	
	/*------------------Display of the bricks-------------------------*/
	
	else if((x==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x
		 && y==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y)
		|| ((x==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x)
		    && y==testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y)){
	  if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==1){
	    gameScreen.print(x,y,' ',WCYAN);
	    brickColor=WCYAN;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==2){
	    gameScreen.print(x,y,' ',WBLUE);
	    brickColor=WBLUE;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==3){
	    gameScreen.print(x,y,' ',WYELLOW);
	    brickColor=WYELLOW;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==4){
	    gameScreen.print(x,y,' ',WGREEN);
	    brickColor=WGREEN;
	  }
	  
	  else if(testGame.getLevel().getTabBrick()[tabB].getBrickResistance()==5){
	    gameScreen.print(x,y,' ',WRED);
	    brickColor=WRED;
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x;
	      i>=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x; --i ){
	    gameScreen.print(i,testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y,' ',brickColor);
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x;
	      i<=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x; ++i ){
	    gameScreen.print(i,testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y,' ',brickColor);
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y;
	      i>=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y; --i){
	    gameScreen.print(testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.x,i,' ',brickColor); 
	  }
	  
	  for(int i=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.y;
	      i<=testGame.getLevel().getTabBrick()[tabB].getBrickPattern().LeftBottom.y; ++i){
	    gameScreen.print(testGame.getLevel().getTabBrick()[tabB].getBrickPattern().RightTop.x,i,' ',brickColor); 
	  }
	  
	  if(++tabB>=testGame.getLevel().getTabBrick().size()){tabB=0;}
	}
	
	
	/*------------------End display of the bricks--------------------*/
	
	/*------------------Display of the balls-------------------------*/
	
	else if((x==testGame.getLevel().getTabBall()[0].getBallPattern().LeftBottom.x
		 && y==testGame.getLevel().getTabBall()[0].getBallPattern().LeftBottom.y)
		|| ((x==testGame.getLevel().getTabBall()[0].getBallPattern().RightTop.x)
		    && y==testGame.getLevel().getTabBall()[0].getBallPattern().RightTop.y))
	  {
	    gameScreen.print(x,y,'@');
	  }
	
	/*------------------End display of balls------------------------*/
	//if the current position is not near an object of the level display a black space
	else if((x<testGame.getLevel().getTabPaddle()[0].getPaddlePattern().LeftBottom.x
		 || x>testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.x)
		&& y==testGame.getLevel().getTabPaddle()[0].getPaddlePattern().RightTop.y){
	  gameScreen.print(x,y,' ',WBLACK);
	}
      }
    }  
    /*------------------End display of the objects------------------*/

    //Updating the state of the other objects
    testGame.update(log);

    quitTrouve=testGame.quit(quit,log);
  }while(quitTrouve!=true  && testGame.getLevel().getHp()!=0);

  return quitTrouve;
}