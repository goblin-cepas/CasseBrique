#ifndef BALL_H
#define BALL_H
#include "Rectangle.h"
#include "Velocity.h"
#include "Brick.h"
#include "Paddle.h"
#include "window.h"

class Ball {
public:
    //Constructors/Destructor
    Ball();
    Ball(const Ball& orig);
    Ball(rectangle, Color, velocity, int);
    virtual ~Ball();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrieve the pattern of the ball as a rectangle
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    rectangle getBallPattern()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :retrieve the color of the ball 
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    Color getColor()const;
 
    ////////////////////////////////////////////////////////////
    /// Input : 
    ///
    /// Result :
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setVelocity(velocity New);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrive the velocity of m_velocity
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    velocity getVelocity()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :retrieve the resistance of the ball
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    int getResistance()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :return a true if the ball hit a brick, paddle    
    /// or another ball, else return false
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    bool collide(Ball&);
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :return a true if the ball hit a brick, else   
    /// return false
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    bool collide(Brick&);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :return a true if the ball hit a paddle else,    
    /// return false
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    bool collide(Paddle&);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :return true if the ball is moving, else false 
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool move();
    
private:
    rectangle m_ballPattern;
    Color m_color;
    velocity m_velocity;
    int m_resistance;
    
    ////////////////////////////////////////////////////////////
    /// Input : A rectangle to change the pattern of 
    /// m_ballPattern
    /// Result :set the m_ballPattern to the new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setBallPattern(rectangle New);
    
    ////////////////////////////////////////////////////////////
    /// Input :A color to replace m_color 
    ///
    /// Result : set m_color to a new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setColor(Color New);
    

    ////////////////////////////////////////////////////////////
    /// Input : An integer to replace m_resistance
    ///
    /// Result : set m_resistance to a new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setResistance(int New);
};

#endif /* BALL_H */

