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
    Configuration();
    Configuration(std::string fileName);
    Configuration(const Configuration& orig);
    virtual ~Configuration();

    std::string getFileName();

    bool Init();
    std::vector<Level> m_levels;
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

    bool read();
    bool create();
    void setFileName(std::string New);
    void setLevel(Level New);
    void addColor(std::string strColor);
    bool brickCollide(rectangle &rect);
};

#endif /* CONFIGURATION_H */

