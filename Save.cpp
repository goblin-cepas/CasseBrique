
#include "Save.h"
#include <sstream>
#include "Paddle.h"
#include "Ball.h"
#include <cstdlib>
#include "window.h"
#include "Ball.h"

Save::Save() : file("save.cfg") {
}

std::string Save::getFile() const {
    return this->file;
}

void Save::setFile(std::string newFile) {
    this->file = newFile;
}

void Save::initOutput() {
    this->of = new std::ofstream();
    this->of->open(this->file, std::ios::out | std::ios::trunc);
}

void Save::writeLine(std::string str) {
    (*this->of) << str << std::endl;
}

void Save::writePaddles(const std::vector<Paddle>& paddles) {
    this->writeLine("[Paddle]");
    size_t length = paddles.size();
    for (size_t i = 0; i < length; ++i) {
        Paddle paddle = (paddles[i]);
        rectangle rect = paddle.getPaddlePattern();

        (*this->of) << rect.LeftBottom.x << ";" << rect.LeftBottom.y << ";" << rect.RightTop.x
                << ";" << rect.RightTop.y << ";" << std::to_string(paddle.getPaddleColor())
                << ";" << std::to_string(paddle.getPaddleResistance()) << std::endl;
    }

    this->writeLine("[EndPaddle]");


}

void Save::writeBalls(const std::vector<Ball>& balls) {
    size_t length = balls.size();
    this->writeLine("[BeginBalls]");
    for (size_t i = 0; i < length; ++i) {
        Ball ball = balls[i];
        rectangle rect = ball.getBallPattern();
        velocity vel = ball.getVelocity();
        (*this->of) << "[Ball" << i << "]" << std::endl;
        (*this->of) << rect.LeftBottom.x << ";" << rect.LeftBottom.y << ";" << rect.RightTop.x
                << ";" << rect.RightTop.y << ";" << std::to_string(ball.getColor())
                << ";" << vel.accel << ";" << vel.direction.x << ";"
                << vel.direction.y << ";" << std::to_string(ball.getResistance())
                << std::endl;
        (*this->of) << "[EndBall" << i << "]" << std::endl;
    }
    this->writeLine("[EndBalls]");
}

void Save::writeBricks(const std::vector<Brick>& bricks) {
    size_t length = bricks.size();
    this->writeLine("[Bricks]");
    for (size_t i = 0; i < length; ++i) {
        Brick brick = bricks[i];
        rectangle rect = brick.getBrickPattern();
        (*this->of) << rect.LeftBottom.x << ";" << rect.LeftBottom.y << ";" << rect.RightTop.x
                << ";" << rect.RightTop.y << ";" << std::to_string(brick.getBrickColor()) << ";"
                << std::to_string(brick.getBrickBonus()) << ";" << std::to_string(brick.getBrickResistance())
                << std::endl;

    }
    this->writeLine("[EndBricks]");

}

void Save::writeSave(Level& level) {
    rectangle ws;
    this->initOutput();
    if (!this->of->is_open()) {
        std::cerr << "ERROR: File opening failed !" << std::endl;
    } else {
        this->writeLine("## This is the save file ##");
        this->writeLine("#------------");
        this->writeLine("[GameType]");
        this->writeLine(std::to_string(level.getIsCampaign()));
        this->writeLine("[EndGameType]");
        this->writeLine("#------------");
        this->writeLine("[Bonus]");
        this->writeLine(std::to_string(level.getNbBonus()));
        this->writeLine("[EndBonus]");
        this->writeLine("#------------");
        this->writePaddles(level.getTabPaddle());
        this->writeLine("#------------");
        this->writeLine("[GameWindow]");
        ws = level.getGameWindowsSize();
        (*this->of) << ws.LeftBottom.x << ";" << ws.LeftBottom.y << ";" << ws.RightTop.x << ";" << ws.RightTop.y << std::endl;
        this->writeLine("[EndGameWindow]");
        this->writeLine("#------------");
        this->writeLine("[MenuWindow]");
        ws = level.getMenuWindowsSize();
        (*this->of) << ws.LeftBottom.x << ";" << ws.LeftBottom.y << ";" << ws.RightTop.x << ";" << ws.RightTop.y << std::endl;
        this->writeLine("[EndMenuWindow]");
        this->writeLine("#------------");
        this->writeBalls(level.getTabBall());
        this->writeLine("#------------");
        this->writeLine("[Score]");
        this->writeLine(std::to_string(level.getScore()));
        this->writeLine("[EndScore]");
        this->writeLine("#------------");
        this->writeLine("[Jump]");
        this->writeLine(std::to_string(level.getJump()));
        this->writeLine("[EndJump]");
        this->writeLine("#------------");
        this->writeLine("[HP]");
        this->writeLine(std::to_string(level.getHp()));
        this->writeLine("[EndHP]");
        this->writeLine("#------------");
        this->writeBricks(level.getTabBrick());
        this->writeLine("#------------");
        this->writeLine("## End of file ##");

    }
    this->of->close();
}

void Save::initInput(std::string newFile) {
    this->ifile = new std::ifstream();
    this->ifile->open(newFile, std::ios::in);
}

void Save::initLevel() {
    this->loadedGame = new Level();
}

void Save::readBonus() {
    std::string buff = "";
    std::getline(*(this->ifile), buff);
    this->loadedGame->setNbBonus(std::atoi(buff.c_str()));
}

void Save::readPaddle() {
    std::string line = "";
    std::getline(*(this->ifile), line);
    std::string word;
    std::istringstream stream(line);
    unsigned int counter = 0;
    vector2 lb, rt;
    rectangle rect;
    std::vector<Paddle> paddles;
    Paddle paddle;
    Color buff1;
    int buff2;
    while (std::getline(stream, word, ';')) {

        switch (counter) {
            case 0:
                lb.x = std::atoi(word.c_str());
                break;
            case 1:
                lb.y = std::atoi(word.c_str());
                break;
            case 2:
                rt.x = std::atoi(word.c_str());
                break;
            case 3:
                rt.y = std::atoi(word.c_str());
                rect.LeftBottom = lb;
                rect.RightTop = rt;
                break;
            case 4:
                buff1 = (Color) std::atoi(word.c_str());
                break;
            case 5:
                buff2 = std::atoi(word.c_str());
                paddle.setPaddlePattern(rect);
                paddle.setPaddleColor(buff1);
                paddle.setPaddleResistance(buff2);
                paddles.push_back(paddle);
                break;

        }
        ++counter;
    }

    this->loadedGame->setTabPaddle(paddles);
}

void Save::readGameWindow() {
    std::string line = "";
    std::getline(*(this->ifile), line);
    std::string word;
    std::istringstream stream(line);
    unsigned int counter = 0;
    vector2 lb, rt;
    rectangle rect;
    while (std::getline(stream, word, ';')) {

        switch (counter) {
            case 0:
                lb.x = std::atoi(word.c_str());
                break;
            case 1:
                lb.y = std::atoi(word.c_str());
                break;
            case 2:
                rt.x = std::atoi(word.c_str());
                break;
            case 3:
                rt.y = std::atoi(word.c_str());
                rect.LeftBottom = lb;
                rect.RightTop = rt;
                break;
        }
        ++counter;
    }
    this->loadedGame->setGameWindowsSize(rect);

}

void Save::readMenuWindow() {
    std::string line = "";
    std::getline(*(this->ifile), line);
    std::string word;
    std::istringstream stream(line);
    unsigned int counter = 0;
    vector2 lb, rt;
    rectangle rect;
    while (std::getline(stream, word, ';')) {

        switch (counter) {
            case 0:
                lb.x = std::atoi(word.c_str());
                break;
            case 1:
                lb.y = std::atoi(word.c_str());
                break;
            case 2:
                rt.x = std::atoi(word.c_str());
                break;
            case 3:
                rt.y = std::atoi(word.c_str());
                rect.LeftBottom = lb;
                rect.RightTop = rt;
                break;
        }
        ++counter;
    }
    this->loadedGame->setMenuWindowsSize(rect);

}

void Save::readBalls() {
    std::string line = "";
    std::getline(*(this->ifile), line);
    std::vector<Ball> balls;
    while (line != "[EndBalls]") {
        if (line.substr(1, 1) == "[") {

            std::getline(*(this->ifile), line);
        }
        else {
            std::string word;
            std::istringstream stream(line);
            unsigned int counter = 0;
            vector2 lb, rt, v2;
            rectangle rect;
            Color buff1;
            float acceleration;
            int buff2;
            velocity vel;
            while (std::getline(stream, word, ';')) {

                switch (counter) {
                    case 0:
                        lb.x = std::atoi(word.c_str());
                        break;
                    case 1:
                        lb.y = std::atoi(word.c_str());
                        break;
                    case 2:
                        rt.x = std::atoi(word.c_str());
                        break;
                    case 3:
                        rt.y = std::atoi(word.c_str());
                        rect.LeftBottom = lb;
                        rect.RightTop = rt;
                        break;
                    case 4:
                        buff1 = (Color) std::atoi(word.c_str());
                        break;
                    case 5:
                        acceleration = std::atof(word.c_str());
                        ;
                        break;
                    case 6:
                        v2.x = std::atoi(word.c_str());

                        break;
                    case 7:
                        v2.y = std::atoi(word.c_str());

                        vel.accel = acceleration;
                        vel.direction.x = v2.x;
                        vel.direction.y = v2.y;
                        break;
                    case 8:
                        buff2 = std::atoi(word.c_str());
                        Ball ball(rect, buff1, vel, buff2);
                        balls.push_back(ball);
                        break;

                }
                ++counter;
            }


            std::getline(*(this->ifile), line);
        }
    }
    this->loadedGame->setTabBall(balls);
}

void Save::readScore() {
    std::string buff = "";
    std::getline(*(this->ifile), buff);
    this->loadedGame->setScore(std::atoi(buff.c_str()));
}

void Save::readJump() {
    std::string buff = "";
    std::getline(*(this->ifile), buff);
    this->loadedGame->setJump(std::atoi(buff.c_str()));

}

void Save::readHP() {
    std::string buff = "";
    std::getline(*(this->ifile), buff);
    this->loadedGame->setHp(std::atoi(buff.c_str()));

}

void Save::readGameType() {
    std::string buff = "";
    std::getline(*(this->ifile), buff);
    this->loadedGame->setIsCampaign(std::atoi(buff.c_str()));

}


void Save::readBricks() {
    std::string line = "";
    std::getline(*(this->ifile), line);
    std::vector<Brick> bricks;
    while (line != "[EndBricks]") {
        if (line.substr(1, 1) == "[") {

            std::getline(*(this->ifile), line);
        }
        else {
            std::string word;
            std::istringstream stream(line);
            unsigned int counter = 0;
            vector2 lb, rt;
            rectangle rect;
            Color buff1;
            bool bonus;
            int buff2;

            while (std::getline(stream, word, ';')) {

                switch (counter) {
                    case 0:
                        lb.x = std::atoi(word.c_str());
                        break;
                    case 1:
                        lb.y = std::atoi(word.c_str());
                        break;
                    case 2:
                        rt.x = std::atoi(word.c_str());
                        break;
                    case 3:
                        rt.y = std::atoi(word.c_str());
                        rect.LeftBottom = lb;
                        rect.RightTop = rt;
                        break;
                    case 4:
                        buff1 = (Color) std::atoi(word.c_str());
                        break;
                    case 5:
                        bonus = std::atof(word.c_str());
                        ;
                        break;
                    case 6:

                        buff2 = std::atoi(word.c_str());
                        Brick brick(rect, buff1, bonus, buff2);
                        bricks.push_back(brick);
                        break;

                }
                ++counter;
            }



            std::getline(*(this->ifile), line);
        }
    }
    this->loadedGame->setTabBrick(bricks);
}

void Save::loadSave(std::string file) {

    std::string line = "";
    this->initLevel();
    this->initInput(file);
    if (!this->ifile->is_open()) {
        std::cerr << "ERROR: File opening failed !" << std::endl;
    } else {
        while (std::getline(*(this->ifile), line)) {
            if (line.substr(1, 1) == "#") {
                continue;
            } else if (line == "[GameType]") {
                this->readGameType();
            } else if (line == "[Bonus]") {
                this->readBonus();
            } else if (line == "[Paddle]") {
                this->readPaddle();
            } else if (line == "[GameWindow]") {
                this->readGameWindow();
            } else if (line == "[MenuWindow]") {
                this->readMenuWindow();
            } else if (line == "[BeginBalls]") {
                this->readBalls();
            } else if (line == "[Score]") {
                this->readScore();
            } else if (line == "[Jump]") {
                this->readJump();
            } else if (line == "[HP]") {
                this->readHP();
            } else if (line == "[Bricks]") {
                this->readBricks();
            }
        }
    }
    this->ifile->close();
}

Level * Save::getLoadedGame() {
    return this->loadedGame;
}

Save::~Save() {
    if (this->of != NULL) {
        delete this->of;
    }
    if (this->ifile != NULL) {
        delete this->ifile;
    }
    if (this->loadedGame != NULL) {
        delete this->loadedGame;
    }
}

