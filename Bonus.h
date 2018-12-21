#ifndef BONUS_H
#define BONUS_H
#include "Rectangle.h"
#include "Velocity.h"
#include "Clock.h"
#include "window.h"


class Bonus {
public:
    //Declaration of the typeBonus enumeration
    enum typeBonus{
      jumpPlus,
      jumpMinus,
      magnet,
      ballPlus,
      fireBall,
      heavyBall,
      paddleSizePlus,
      paddleSizeMinus,
      ballPattern,
      brickLocker
    };

    //Constructor/Destructors
    Bonus();
    Bonus(rectangle,Color,velocity,clocks,typeBonus);
    Bonus(const Bonus& orig);
    virtual ~Bonus();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrieve the pattern of m_bonusPattern
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    rectangle getBonusPattern()const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrieve the color of m_color
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    Color getColor()const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrieve the velocity of m_velocity
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    velocity getVelocity()const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : retrieve the timer of m_clock

    ///
    /// info :
    ////////////////////////////////////////////////////////////
    clocks getClock()const;


    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :retrieve the type of m_typeBonus
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    typeBonus getType()const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :returns true if the bonus is moving, else
    /// returns false
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    bool move();

 private:
    rectangle m_bonusPattern;
    Color m_color;
    velocity m_velocity;
    clocks m_clock;
    typeBonus m_typeBonus;

    ////////////////////////////////////////////////////////////
    /// Input : A rectangle structure
    ///
    /// Result :set m_bonusPattern to the new value
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    void setBonusPattern(rectangle newPattern);

    ////////////////////////////////////////////////////////////
    /// Input : A color enumeration
    ///
    /// Result : set m_color to the new value
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    void setColor(Color newColor);

    ////////////////////////////////////////////////////////////
    /// Input : a velocity structure
    ///
    /// Result : set m_velocity to the new value
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    void setVelocity(velocity newVelocity);

    ////////////////////////////////////////////////////////////
    /// Input : a clock structure
    ///
    /// Result :set m_clock to the new value
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    void setClock(clocks newClock);

    ////////////////////////////////////////////////////////////
    /// Input : A typeBonus enumeration
    ///
    /// Result :set m_typeBonus to the new value
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    void setType(typeBonus newType);
};

#endif /* BONUS_H */
