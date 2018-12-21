#include "Brick.h"
extern "C" {
#include <curses.h>
}
#include <iostream>
#include "window.h"


//Builder

Brick::Brick(rectangle NewRectangle,Color NewColor,bool NewBonus,int NewResistance) : m_brickPattern (NewRectangle), m_brickColor(NewColor), m_bonus(NewBonus),m_brickResistance(NewResistance){

}
//Destructor
Brick::~Brick(){

}
//Accessors

rectangle Brick::getBrickPattern() const {
  return m_brickPattern;
}
void Brick::setBrickPattern(rectangle NewBrickPattern){
  m_brickPattern = NewBrickPattern;
}

Color Brick::getBrickColor() const {
  return m_brickColor;
}
void Brick::setBrickColor(Color NewBrickColor){
  m_brickColor = NewBrickColor;
}

bool Brick::getBrickBonus() const{
  return m_bonus;
}
void Brick::setBrickBonus(bool NewBonus){
  m_bonus = NewBonus;
}

int Brick::getBrickResistance() const{
  return m_brickResistance;
}
void Brick::setBrickResistance(int NewBrickResistance){
  m_brickResistance = NewBrickResistance;
}

//Method

void Brick::hit(Brick &B){
  if (m_brickResistance == 0){
    delete &B;
  }
  else {
    m_brickResistance--;
  }
}
