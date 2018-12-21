#include "Bonus.h"
#include <unistd.h>
#include <iostream>


Bonus::Bonus()
  :m_bonusPattern(), m_color(), m_velocity(), m_clock(), m_typeBonus()
{
}
Bonus::Bonus(rectangle newPattern, Color color, velocity newVelocity, clocks newClock, Bonus::typeBonus newType)
  :m_bonusPattern(newPattern),m_color(color),m_velocity(newVelocity), m_clock(newClock), m_typeBonus(newType)
{}

Bonus::Bonus(const Bonus& orig)
  :m_bonusPattern(orig.getBonusPattern()), m_color(orig.getColor()), m_velocity(orig.getVelocity()), m_clock(orig.getClock())
{
}

Bonus::~Bonus() {
}


void Bonus::setBonusPattern(rectangle newPattern){m_bonusPattern=newPattern;}
void Bonus::setColor(Color newColor){m_color=newColor;}
void Bonus::setVelocity(velocity newVelocity){m_velocity=newVelocity;}
void Bonus::setClock(clocks newClock){m_clock=newClock;}
void Bonus::setType(Bonus::typeBonus newType){m_typeBonus=newType;}

rectangle Bonus::getBonusPattern()const{return m_bonusPattern;}
Color Bonus::getColor()const{return m_color;}
velocity Bonus::getVelocity()const{return m_velocity;}
clocks Bonus::getClock()const{return m_clock;}
Bonus::typeBonus Bonus::getType()const{return m_typeBonus;}

bool Bonus::move(){
  rectangle new_pos;
  new_pos=getBonusPattern();
  if(getVelocity().direction.x!=0){
    new_pos.LeftBottom.x=new_pos.LeftBottom.x*getVelocity().accel*getVelocity().direction.x;
    new_pos.LeftBottom.y=new_pos.LeftBottom.y*getVelocity().accel*getVelocity().direction.x;
  }
  if(getVelocity().direction.y!=0){
    new_pos.RightTop.y=new_pos.RightTop.y*getVelocity().accel*getVelocity().direction.y;
    new_pos.RightTop.x=new_pos.RightTop.x*getVelocity().accel*getVelocity().direction.y;
  }
  this->setBonusPattern(new_pos);
  return true;
}
