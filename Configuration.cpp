#include "Configuration.h"

#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <cstdlib>

#include "Vector2.h"
#include "Level.h"
#include "window.h"

Configuration::Configuration() : m_fileName("config.cfg") {

}

Configuration::Configuration(std::string fileName) : m_fileName(fileName) {

}

Configuration::Configuration(const Configuration& orig) {

}

Configuration::~Configuration() {

}

std::string Configuration::getFileName() {
    return this->m_fileName;
}

/*
Level Configuration::getLevel() {
    return this->m_level;
}
 */
void Configuration::setFileName(std::string New) {
    this->m_fileName = New;
}

/*
void Configuration::setLevel(Level New) {
    this->m_level = New;
}
 */
bool Configuration::read() {
    std::string lineBuffer;

    bool Pattern = false;
    bool Color = false;
    bool Player = false;
    bool Score = false;
    bool Level = false;

    this->m_configFlux.open(this->m_fileName, std::ios::in);
    if (this->m_configFlux.is_open()) {
        while (getline(this->m_configFlux, lineBuffer)) {
            size_t Size = lineBuffer.length();
            lineBuffer = lineBuffer.substr(0, Size - 1);
            if (lineBuffer == "[EndPattern]") {
                Pattern = false;
            }
            if (lineBuffer == "[EndColor]") {
                Color = false;
            }
            if (lineBuffer == "[EndPlayer]") {
                Player = false;
            }
            if (lineBuffer == "[EndScore]") {
                Score = false;
            }
            if (lineBuffer == "[EndLevel]") {
                Level = false;
            }

            if (Pattern) {
                std::cout << lineBuffer << std::endl;
                //std::vector<Rectangle> m_BrickPatterns;
                std::size_t width = lineBuffer.find("width");

                std::size_t height = lineBuffer.find("height");

                if (width != std::string::npos) {
                    std::cout << "result width est " << lineBuffer[width];
                    std::cout << " at position " << width << '\n';
                }

                if (height != std::string::npos) {
                    std::cout << "result height est " << lineBuffer[height];
                    std::cout << " at position " << height << '\n';
                }

                std::size_t trouve = lineBuffer.find_first_not_of("abcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|");
                if (trouve != std::string::npos) {
                    std::cout << "result trouve est " << lineBuffer[trouve];
                    std::cout << " at position " << trouve << '\n';
                }

                if (height > width) {
                    std::string widthstr = lineBuffer.substr(width, height - 1);
                    std::size_t widthnumber = widthstr.find_first_not_of("abcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|");
                    std::cout << " widthnumber est " << widthstr[widthnumber] << '\n';
                    std::string heightstr = lineBuffer.substr(height, Size - 1);
                    std::size_t heightnumber = heightstr.find_first_not_of("abcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|");
                    std::cout << " heightnumber est " << heightstr[heightnumber] << '\n';
                    vector2 patternvect;
                    patternvect.x = widthstr[widthnumber] - '0';
                    std::cout << " patternvect x est " << patternvect.x << '\n';
                    patternvect.y = heightstr[heightnumber] - '0';
                    std::cout << " patternvect y est " << patternvect.y << '\n';
                    this->m_BrickPatterns.push_back(patternvect);

                    std::cout << " m_BrickPatterns est " << m_BrickPatterns[m_BrickPatterns.size() - 1].x << " en x est " << m_BrickPatterns[m_BrickPatterns.size() - 1].y << " en y" << '\n';

                } else {
                    std::string widthstr = lineBuffer.substr(width, Size - 1);
                    std::size_t widthnumber = widthstr.find_first_not_of("abcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|");
                    std::cout << " widthnumber est " << widthstr[widthnumber] << '\n';
                    std::string heightstr = lineBuffer.substr(height, width - 1);
                    std::size_t heightnumber = heightstr.find_first_not_of("abcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|");
                    std::cout << " heightnumber est " << heightstr[heightnumber] << '\n';
                    vector2 patternvect;
                    patternvect.x = widthstr[widthnumber] - '0';
                    patternvect.y = heightstr[heightnumber] - '0';
                    this->m_BrickPatterns.push_back(patternvect);

                    std::cout << " m_BrickPatterns est " << m_BrickPatterns[m_BrickPatterns.size() - 1].x << " en x est " << m_BrickPatterns[m_BrickPatterns.size() - 1].y << " en y" << '\n';
                }
            }

            if (Color) {
                std::size_t Color1 = lineBuffer.find("1");
                std::size_t Color2 = lineBuffer.find("2");
                std::size_t Color3 = lineBuffer.find("3");
                std::size_t Color4 = lineBuffer.find("4");
                std::size_t Color5 = lineBuffer.find("5");

                if (Color1 != std::string::npos) {
                    std::string color = lineBuffer.substr(lineBuffer.find_first_not_of("0123456789 :;[],.*-+_/\\|"), Size - 1);
                    addColor(color);
                }
                if (Color2 != std::string::npos) {
                    std::string color = lineBuffer.substr(lineBuffer.find_first_not_of("0123456789 :;[],.*-+_/\\|"), Size - 1);
                    addColor(color);
                }
                if (Color3 != std::string::npos) {
                    std::string color = lineBuffer.substr(lineBuffer.find_first_not_of("0123456789 :;[],.*-+_/\\|"), Size - 1);
                    addColor(color);
                }
                if (Color4 != std::string::npos) {
                    std::string color = lineBuffer.substr(lineBuffer.find_first_not_of("0123456789 :;[],.*-+_/\\|"), Size - 1);
                    addColor(color);
                }
                if (Color5 != std::string::npos) {
                    std::string color = lineBuffer.substr(lineBuffer.find_first_not_of("0123456789 :;[],.*-+_/\\|"), Size - 1);
                    addColor(color);
                }
            }

            if (Player) {
                std::size_t playerLife = lineBuffer.find("playerLife");
                std::size_t playerJump = lineBuffer.find("playerJump");
                if (playerLife != std::string::npos) {
                    this->m_playerLife = std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("HLJabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|"), Size - 1).c_str());
                    std::cout << "result m_playerLife est " << this->m_playerLife << std::endl;
                }

                if (playerJump != std::string::npos) {
                    this->m_playerJump = std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("HLJabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|"), Size - 1).c_str());
                    std::cout << "result m_playerJump est " << this->m_playerJump << std::endl;
                }
            }

            if (Score) {
                std::size_t scoreHit = lineBuffer.find("scoreHit");
                if (scoreHit != std::string::npos) {
                    this->m_scoreHit = std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("HLJabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|"), Size - 1).c_str());
                    std::cout << "result m_scoreHit est " << this->m_scoreHit << std::endl;
                }
            }

            if (Level) {
                std::size_t NBrick1 = lineBuffer.find("NBrickOne");
                std::size_t NBrick2 = lineBuffer.find("NBrickTwo");
                std::size_t NBrick3 = lineBuffer.find("NBrickThree");
                std::size_t NBrick4 = lineBuffer.find("NBrickFour");
                std::size_t NBrick5 = lineBuffer.find("NBrickFive");
                std::size_t Bonus = lineBuffer.find("%Bonus");

                if (NBrick1 != std::string::npos) {
                    this->m_NBrickOne.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                    std::cout << "Brick 1 " << this->m_NBrickOne[this->m_NBrickOne.size() - 1] << std::endl;
                }
                if (NBrick2 != std::string::npos) {
                    this->m_NBrickTwo.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                    std::cout << "Brick 2 " << this->m_NBrickTwo[this->m_NBrickTwo.size() - 1] << std::endl;
                }
                if (NBrick3 != std::string::npos) {
                    this->m_NBrickTwo.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                }
                if (NBrick4 != std::string::npos) {
                    this->m_NBrickFour.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                }
                if (NBrick5 != std::string::npos) {
                    this->m_NBrickFive.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                }
                if (Bonus != std::string::npos) {
                    this->m_Bonus.push_back(std::atoi(lineBuffer.substr(lineBuffer.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz :;[],.*-+_/\\|%"), Size - 1).c_str()));
                }
            }

            if (lineBuffer == "[Pattern]") {
                Pattern = true;
            }
            if (lineBuffer == "[Color]") {
                Color = true;
            }
            if (lineBuffer == "[Player]") {
                Player = true;
            }
            if (lineBuffer == "[Score]") {
                Score = true;
            }

            if (lineBuffer == "[Level-1]") {
                Level = true;
            }

            if (lineBuffer == "[Level-2]") {
                Level = true;
            }

            if (lineBuffer == "[Level-3]") {
                Level = true;
            }

            if (lineBuffer == "[Level-4]") {
                Level = true;
            }

            if (lineBuffer == "[Level-5]") {
                Level = true;
            }

        }
        this->m_configFlux.close();
        return true;
    } else {
        return false;
    }
}

void Configuration::addColor(std::string strColor) {
    if (strColor == "WBLACK") {
        this->m_BrickColor.push_back(Color::WBLACK);
    }
    if (strColor == "WCYAN") {
        this->m_BrickColor.push_back(Color::WCYAN);
    }
    if (strColor == "WBLUE") {
        this->m_BrickColor.push_back(Color::WBLUE);
    }
    if (strColor == "WYELLOW") {
        this->m_BrickColor.push_back(Color::WYELLOW);
    }
    if (strColor == "WGREEN") {
        this->m_BrickColor.push_back(Color::WGREEN);
    }
    if (strColor == "WMAGENTA") {
        this->m_BrickColor.push_back(Color::WMAGENTA);
    }
    if (strColor == "WRED") {
        this->m_BrickColor.push_back(Color::WRED);
    }
    if (strColor == "BWHITE") {
        this->m_BrickColor.push_back(Color::BWHITE);
    }
    if (strColor == "BCYAN") {
        this->m_BrickColor.push_back(Color::BCYAN);
    }
    if (strColor == "BBLUE") {
        this->m_BrickColor.push_back(Color::BBLUE);
    }
    if (strColor == "BYELLOW") {
        this->m_BrickColor.push_back(Color::BYELLOW);
    }
    if (strColor == "BGREEN") {
        this->m_BrickColor.push_back(Color::BGREEN);
    }
    if (strColor == "BGREEN") {
        this->m_BrickColor.push_back(Color::BGREEN);
    }
    if (strColor == "BRED") {
        this->m_BrickColor.push_back(Color::BRED);
    }


}

bool Configuration::create() {

    int windowWidth = 60;
    int windowHeight = 50;

    Color ballColor(WBLUE);
    Color paddleColor(WBLUE);

    this->m_paddleLevel.push_back(new Paddle(new rectangle(new vector2(windowWidth / 2 - 2, windowHeight - 1), new vector2(windowWidth / 2 + 2, windowHeight)), paddleColor, 400));
    this->m_brickLevel.push_back(new rectangle(new vector2(windowWidth / 2, windowHeight - 2), new vector2(windowWidth / 2 + 1, windowHeight - 3)), ballColor, new velocity(10.f, new vector2(windowWidth / 2 + 2, windowHeight - 4)), 400);

    srand(time(NULL));
    int loop = 0;

    int numberBonus;
    int posX = 0;
    int posY = 20;
    int i = 0;
    while (i <= 5) {
        int numberBrick = this->m_NBrickOne[i] + this->m_NBrickTwo[i] + this->m_NBrickThree[i] + this->m_NBrickFour[i] + this->m_NBrickFive[i];
        while (numberBrick > 0) {
            int randPattern = rand() % m_BrickPatterns.size();
            rectangle brickRect = new rectangle(new vector2(posX, posY), new vector2(posX + m_BrickPatterns[randPattern].x, posY + m_BrickPatterns[randPattern].y));
            if (!brickCollide(brickRect)) {
                if (m_NBrickFive[i] > 0) {
                    m_NBrickFive[i]--;
                    numberBrick--;
                    numberBonus = rand() % 100 + 1;
                    this->m_brickLevel.push_back(new Brick(brickRect, this->m_BrickColor[4], (numberBonus <= this->m_Bonus[i]), 5));
                } else if (m_NBrickFour[i] > 0) {
                    m_NBrickFour[i]--;
                    numberBrick--;
                    numberBonus = rand() % 100 + 1;
                    this->m_brickLevel.push_back(new Brick(brickRect, this->m_BrickColor[3], (numberBonus <= this->m_Bonus[i]), 4));
                } else if (m_NBrickThree[i] > 0) {
                    m_NBrickThree[i]--;
                    numberBrick--;
                    numberBonus = rand() % 100 + 1;
                    this->m_brickLevel.push_back(new Brick(brickRect, this->m_BrickColor[2], (numberBonus <= this->m_Bonus[i]), 3));
                } else if (m_NBrickTwo[i] > 0) {
                    m_NBrickTwo[i]--;
                    numberBrick--;
                    numberBonus = rand() % 100 + 1;
                    this->m_brickLevel.push_back(new Brick(brickRect, this->m_BrickColor[1], (numberBonus <= this->m_Bonus[i]), 2));
                } else if (m_NBrickOne[i] > 0) {
                    m_NBrickOne[i]--;
                    numberBrick--;
                    numberBonus = rand() % 100 + 1;
                    this->m_brickLevel.push_back(new Brick(brickRect, this->m_BrickColor[0], (numberBonus <= this->m_Bonus[i]), 1));
                }
            } else {
                posX++;
            }
            if (posX >= windowWidth) {
                posX = 0;
                posY++;
                if (posY >= windowHeight) {
                    posY = 20;
                    loop++;
                    if (loop > 5) {
                        return false;
                    }
                }
            }
        }
        this->m_levels.push_back(new Level(0, new rectangle(new vector2(0, 0), new vector2(windowWidth, windowHeight)), new rectangle(new vector2(0, windowHeight + 11), new vector2(windowWidth, windowHeight + 1)), this->m_brickLevel, this->m_ballLevel, this->m_paddleLevel, this->m_scoreHit, this->m_playerLife, this->m_playerJump));
        this->m_brickLevel.clear();
        i++;
    }
    return true;
}

bool Configuration::brickCollide(rectangle &rect) {
    for (int i = 0; i < this->m_brickLevel.size(); i++) {
        rectangle rectTry = this->m_brickLevel[i].getBrickPattern();
        if (rect.LeftBottom.x >= rectTry.LeftBottom.x && rect.RightTop.x <= rectTry.RightTop.x) {
            if (rect.LeftBottom.y >= rectTry.LeftBottom.x && rect.RightTop.y <= rectTry.RightTop.y) {
                return true;
            }
        }
        return false;
    }
}

bool Configuration::Init() {
    if (!this->read()) {
        std::cerr << "Error Read Method Config" << std::endl;
    }
    if (!this->create()) {
        std::cerr << "Error Create Method Config" << std::endl;
    }

}

