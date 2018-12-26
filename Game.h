#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include "timer.h"
#include "Save.h"

class Game {
public:
    Game();
    Game(Level);
    Game(const Game& orig);
    virtual ~Game();
    
    ////////////////////////////////////////////////////////////
    /// Input : none
    ///
    /// Result :retrieve the level of the current game
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    Level getLevel()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : none
    ///
    /// Result :retrieve the timer of the m_timer 
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    timer& getTimer();
    
    ////////////////////////////////////////////////////////////
    /// Input : none
    ///
    /// Result :retrieve m_pause as a boolean value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool getPause()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : none
    ///
    /// Result : retrieve m_help as a boolean value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool getHelp()const;
    
    ////////////////////////////////////////////////////////////
    /// Input : none
    ///
    /// Result : update the m_level member of the class and 
    /// return true if everything have gone well 
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    bool update();
    
    ////////////////////////////////////////////////////////////
    /// Input : an integer that represent an input 
    ///
    /// Result :return true if the 'q' key have been pressed
    /// else false
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool quit(int Key);
    
    ////////////////////////////////////////////////////////////
    /// Input : an integer that represent an input
    ///
    /// Result :return true if the 'h' or 'p' key has been pressed
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool interrupt(int Key);
    
    /////////////////////////s///////////////////////////////////
    /// Input : an integer that represent an input
    ///
    /// Result : return true if spacebar has been pressed 
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool launch(int Key);
    
private:
    Level m_level;
    timer m_timer;
    bool m_pause;
    bool m_help;
    
    ////////////////////////////////////////////////////////////
    /// Input : a level 
    ///
    /// Result : set the m_level member at the new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setLevel(Level& newLevel);
    
    ////////////////////////////////////////////////////////////
    /// Input : a timer structure
    ///
    /// Result : set the m_timer member at the new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setTimer(timer newTimer);
    
    ////////////////////////////////////////////////////////////
    /// Input : a boolean value
    ///
    /// Result : set the m_pause member at the new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setPause(bool newPause);
    
    ////////////////////////////////////////////////////////////
    /// Input : a boolean
    ///
    /// Result :set the m_help member at the new value
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setHelp(bool newHelp);

};

void runGame(Game&);

#endif /* GAME_H */

