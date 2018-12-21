#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <string>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>

#include "Rectangle.h"
#include "Level.h"

class Configuration {
public:
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Configuration instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    Configuration();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Configuration instance with custom m_fileName
    ////////////////////////////////////////////////////////////
    Configuration(std::string fileName);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : String, the content of m_fileName
    /// 
    /// info :  
    ////////////////////////////////////////////////////////////
    std::string getFileName();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Bool, True if the m_Levels is Correctly filled, else False
    /// 
    /// info :  this Method extract values from config.cfg and create a std::vector<Level> m_levels
    ////////////////////////////////////////////////////////////
    bool Init();

    ////////////////////////////////////////////////////////////
    /// Input : Number, the number of the level to return;
    ///
    /// Result :&Level, return the level from m_levels by reference
    /// 
    /// info :  to get Level 1 you have to call getLevel(1), Level 2 -> getLevel(2), there is only 5 levels.
    ////////////////////////////////////////////////////////////
    Level& getLevel(int levelNumber);

private:
    std::string m_fileName;
    std::vector<vector2> m_BrickPatterns;
    std::vector<Color> m_BrickColor;
    std::vector<Ball> m_ballLevel;
    std::vector<Paddle> m_paddleLevel;
    std::vector<Brick> m_brickLevel;
    std::vector<int> m_NBrickOne;
    std::vector<int> m_NBrickTwo;
    std::vector<int> m_NBrickThree;
    std::vector<int> m_NBrickFour;
    std::vector<int> m_NBrickFive;
    std::vector<int> m_Bonus;
    std::vector<Level> m_levels;

    int m_playerLife;
    int m_playerJump;
    int m_scoreHit;

    std::fstream m_configFlux;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    bool read();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    bool create();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    void setFileName(std::string New);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    void setLevel(Level New);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    void addColor(std::string strColor);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'config.cfg'
    ////////////////////////////////////////////////////////////
    bool brickCollide(rectangle &rect);
};

#endif /* CONFIGURATION_H */

