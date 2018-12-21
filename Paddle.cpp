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


void Paddle::move(rectangle B){
  int ch;
  while((ch = getch()) != 'q')
  {
    switch (ch) {

        case KEY_LEFT:    B.LeftBottom.x --;
    setPaddlePattern(B);
    break;

        case KEY_RIGHT:
    B.LeftBottom.x ++;
    setPaddlePattern(B);

    break;
        }

    }
}

void Paddle::bonus(Bonus &B){
    clocks newClock;
    newClock.c=20;

    if (getPaddlePattern().LeftBottom.x && getPaddlePattern().LeftBottom.y &&
        getPaddlePattern().RightTop.x && getPaddlePattern().RightTop.y == B.getBonusPattern().LeftBottom.x && B.getBonusPattern().LeftBottom.y &&
        B.getBonusPattern().RightTop.x && B.getBonusPattern().RightTop.x){
            //B.setClock(newClock);

        }
}
