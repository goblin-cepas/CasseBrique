#include "Paddle.h"
extern "C" {
#include <curses.h>
}
#include "window.h"
#include <iostream>
#include "Bonus.h"


//Builder

Paddle::Paddle(rectangle NewRectangle, Color NewColor, int NewResistance) : m_paddlePattern(NewRectangle), m_paddleColor(NewColor), m_paddleResistance(NewResistance){
}

//Destructor
Paddle::~Paddle(){

}
//Accessors
rectangle Paddle::getPaddlePattern() const{
  return m_paddlePattern;
}
void Paddle::setPaddlePattern(rectangle NewPattern){
  m_paddlePattern = NewPattern;
}

Color Paddle::getPaddleColor() const{
  return m_paddleColor;
}
void Paddle::setPaddleColor(Color NewColor){
  m_paddleColor = NewColor;
}

int Paddle::getPaddleResistance() const{
  return m_paddleResistance;
}
void Paddle::setPaddleResistance(int NewResistance){
  m_paddleResistance = NewResistance;
}

//Method
void Paddle::move(){
    rectangle Move;
    int ch;
    Move=this->getPaddlePattern();
void Paddle::move(rectangle B){
  int h=50,w=50;
  int ch;
  Window plateau(h,w,1,6);
  plateau.setCouleurBordure(BBLUE);
  int x=w/2,y=h/2;
  char p='B';
  Color col=WBLUE;
  plateau.print(x,y,p,col);
  while((ch = getch()) != 'q')
  {
    switch (ch) {

        case KEY_LEFT:
    Move.x.x --;
    setPaddlePattern(Move);
    break;

        case KEY_RIGHT:
    Move.x.x ++;
    setPaddlePattern(Move);
    break;
        }

    }
}

void Paddle::bonus(Bonus &B){
    clocks newClock;
    newClock.c=20;
    if (getPaddlePattern().x.x && getPaddlePattern().x.y &&
        getPaddlePattern().y.x && getPaddlePattern().y.y == B.getBonusPattern().x.x && B.getBonusPattern().x.y &&
        B.getBonusPattern().y.x && B.getBonusPattern().y.x){
            B.setClock(newClock);
        }
}
