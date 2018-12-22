#include "Level.h"
#include <iostream>
#include "window.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "Home.h"
#include "Score.h"


Level::Level(size_t NbBonus,rectangle gameWindowsSize,rectangle menuWindowSize,std::vector<Brick> TabBrick,std::vector<Ball> TabBall,std::vector<Paddle> TabPaddle,int Score,int Hp,int Jump) :
m_NbBonus(NbBonus),m_gameWindowsSize(gameWindowsSize),m_MenuWindowsSize(menuWindowSize),m_TabBrick(TabBrick),m_TabBall(TabBall),m_TabPaddle(TabPaddle),m_Score(Score),m_Hp(Hp),m_Jump(Jump){

}

Level::Level(){}
Level::~Level(){

}

size_t Level::getNbBonus() const{
    return m_NbBonus;
}
void Level::setNbBonus(size_t NewNbBonus){
    m_NbBonus = NewNbBonus;
}

rectangle Level::getGameWindowsSize() const{
    return m_gameWindowsSize;
}

void Level::setGameWindowsSize(rectangle NewGameWindowsSize){
    m_gameWindowsSize = NewGameWindowsSize;
}


rectangle Level::getMenuWindowsSize() const{
    return m_MenuWindowsSize;
}

void Level::setMenuWindowsSize(rectangle NewMenuWindowsSize){
    m_MenuWindowsSize = NewMenuWindowsSize;
}

std::vector<Brick>& Level::getTabBrick() {
    return m_TabBrick;
}
void Level::setTabBrick(std::vector<Brick> NewTabBrick){
     m_TabBrick = NewTabBrick;
}

std::vector<Ball>& Level::getTabBall() {
    return m_TabBall;
}
void Level::setTabBall(std::vector<Ball> NewTabBall){
    m_TabBall = NewTabBall;
}

std::vector<Paddle>& Level::getTabPaddle() {
    return m_TabPaddle;
}
void Level::setTabPaddle(std::vector<Paddle> NewTabPaddle){
    m_TabPaddle = NewTabPaddle;
}

int Level::getScore() const{
    return m_Score;
}
void Level::setScore(int NewScore){
    m_Score = NewScore;
}

int Level::getHp() const{
    return m_Hp;
}
void Level::setHp(int NewHp){
    m_Hp = NewHp;
}

int Level::getJump() const {
    return m_Jump;
}
void Level::setJump(int NewJump){
    m_Jump = NewJump;
}
    //method
std::vector<playerScore> Level::createMenu(){
    Score MenuScore;
    std::vector<playerScore> test;
    test = MenuScore.getScoreTab();
    if (test.size() > 5){
        test.resize(5);
    }
    return test;
}
