#include "Ball.h"

Ball::Ball()
  :m_ballPattern(), m_color(), m_velocity(), m_resistance()
{
}


Ball::Ball(const Ball& orig)
  :m_ballPattern(orig.m_ballPattern), m_color(orig.m_color), m_resistance(orig.m_resistance)
{
}
Ball::Ball(rectangle pattern,Color color,velocity velocity,int resistance)
  :m_ballPattern(pattern),m_color(color),m_velocity(velocity),m_resistance(resistance)
{
}

Ball::~Ball()
{
}

void Ball::setBallPattern(rectangle newPattern){m_ballPattern=newPattern;}
void Ball::setColor(Color newColor){m_color=newColor;}
void Ball::setVelocity(velocity newVelocity){m_velocity=newVelocity;}
void Ball::setResistance(int newResistance){m_resistance=newResistance;}


rectangle Ball::getBallPattern()const{return m_ballPattern;}
Color Ball::getColor()const{return m_color;}
velocity Ball::getVelocity()const{return m_velocity;}
int Ball::getResistance()const{return m_resistance;}

bool Ball::collide(Ball &ball){
  bool haveCollided=false;
  
  this->move(); 
  rectangle new_pattern=this->getBallPattern();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().LeftBottom.x==ball.getBallPattern().LeftBottom.x)
     && (this->getBallPattern().LeftBottom.y==ball.getBallPattern().LeftBottom.y)){
    new_pattern.RightTop.x=(this->getBallPattern().RightTop.x);
    new_pattern.RightTop.y=(this->getBallPattern().RightTop.y);
    new_velocity.direction.x=-new_velocity.direction.x;
    haveCollided=true;
  }
  else
    if((this->getBallPattern().RightTop.x==ball.getBallPattern().RightTop.x)
       && (this->getBallPattern().RightTop.y==ball.getBallPattern().RightTop.y)){
      new_pattern.LeftBottom.x=(this->getBallPattern().LeftBottom.x);
      new_pattern.LeftBottom.y=(this->getBallPattern().LeftBottom.y);
      new_velocity.direction.y=-new_velocity.direction.y;
      haveCollided=true;
    } 
  this->setBallPattern(new_pattern);

  return haveCollided;    
}

bool Ball::collide(Brick &brick){
  this->move(); bool haveCollided=false;
  rectangle new_pattern=this->getBallPattern();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().LeftBottom.x==brick.getBrickPattern().LeftBottom.x)
     && (this->getBallPattern().LeftBottom.y==brick.getBrickPattern().LeftBottom.y)){
    new_pattern.LeftBottom.x=(this->getBallPattern().RightTop.x);
    new_pattern.LeftBottom.y=(this->getBallPattern().RightTop.y);
    new_velocity.direction.x=-new_velocity.direction.x;
    haveCollided=true;
  }
  else
    if((this->getBallPattern().RightTop.x==brick.getBrickPattern().RightTop.x)
       && (this->getBallPattern().RightTop.y==brick.getBrickPattern().RightTop.y)){
      new_pattern.RightTop.x=(this->getBallPattern().LeftBottom.x);
      new_pattern.RightTop.y=(this->getBallPattern().LeftBottom.y);
      new_velocity.direction.y=-new_velocity.direction.y;
      haveCollided=true;
    } 
  this->setBallPattern(new_pattern);
  return haveCollided;    
}

bool Ball::collide(Paddle &paddle){
  bool haveCollided=false;
  rectangle new_pattern=this->getBallPattern();
  this->move();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().LeftBottom.x>=paddle.getPaddlePattern().LeftBottom.x
    && this->getBallPattern().LeftBottom.x<=paddle.getPaddlePattern().RightTop.x)
     && (this->getBallPattern().LeftBottom.y>=paddle.getPaddlePattern().LeftBottom.y-1)){
    new_pattern.LeftBottom.x=(this->getBallPattern().LeftBottom.x);
    new_pattern.LeftBottom.y=(this->getBallPattern().LeftBottom.y);
    new_pattern.RightTop.x=(this->getBallPattern().RightTop.x);
    new_pattern.RightTop.y=(this->getBallPattern().RightTop.y);
    if(new_velocity.direction.y=1){
      new_velocity.direction.y=-new_velocity.direction.y;
    }
    haveCollided=true;
  }
     
  this->setBallPattern(new_pattern);
  return haveCollided;    
}

bool Ball::move(){
  rectangle new_pos;bool isMoving=false;
  new_pos=getBallPattern();

  if(getVelocity().direction.x!=0){
    new_pos.LeftBottom.x=(new_pos.LeftBottom.x*getVelocity().accel*getVelocity().direction.x);
    new_pos.RightTop.x=((new_pos.RightTop.x*getVelocity().accel*getVelocity().direction.x));
    isMoving=true;
  }

  if(getVelocity().direction.y!=0){
    new_pos.RightTop.y=(new_pos.RightTop.y*getVelocity().accel*getVelocity().direction.y);
    new_pos.LeftBottom.y=(new_pos.LeftBottom.y*getVelocity().accel*getVelocity().direction.y);
    isMoving=true;
  }

  if(((new_pos.LeftBottom.x<0 || new_pos.LeftBottom.y)
    || (new_pos.RightTop.x<0 || new_pos.RightTop.y))){
      new_pos.LeftBottom.x=-new_pos.LeftBottom.x;
      new_pos.RightTop.y=-new_pos.RightTop.y;
      new_pos.RightTop.x=-new_pos.RightTop.x;
      new_pos.LeftBottom.y=-new_pos.LeftBottom.y;
  }
  
  this->setBallPattern(new_pos);
  return isMoving;
}