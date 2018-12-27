#include "Level.h"
#include "window.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "Home.h"
#include "Score.h"

#include <iostream>


Level::Level(size_t NbBonus,std::vector<Brick> TabBrick,std::vector<Ball> TabBall,std::vector<Paddle> TabPaddle,int Score,int Hp,int Jump) :
m_NbBonus(NbBonus),m_TabBrick(TabBrick),m_TabBall(TabBall),m_TabPaddle(TabPaddle),m_Score(Score),m_Hp(Hp),m_Jump(Jump){

}

Level::Level(){}
Level::Level(const Level& L) : m_NbBonus(L.m_NbBonus),m_TabBrick(L.m_TabBrick),m_TabBall(L.m_TabBall),m_TabPaddle(L.m_TabPaddle),m_Score(L.m_Score),m_Hp(L.m_Hp),m_Jump(L.m_Jump){}
Level::~Level(){

}
bool Level::getIsCampaign() const{
    return this->isCampaign;
}

void Level::setIsCampaign(bool Boolean){
    this->isCampaign=Boolean;
}

size_t Level::getNbBonus() const{
    return m_NbBonus;
}
void Level::setNbBonus(size_t NewNbBonus){
    m_NbBonus = NewNbBonus;
}
std::vector<Brick>& Level::getTabBrick(){
    return this->m_TabBrick;
}
void Level::setTabBrick(std::vector<Brick>& NewTabBrick){
     m_TabBrick = NewTabBrick;
}

std::vector<Ball>& Level::getTabBall(){
    return this->m_TabBall;
}
void Level::setTabBall(std::vector<Ball>& NewTabBall){
    m_TabBall = NewTabBall;
}

std::vector<Paddle>& Level::getTabPaddle(){
    return this->m_TabPaddle;
}
void Level::setTabPaddle(std::vector<Paddle>& NewTabPaddle){
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
    //operator
Level& Level::operator=(const Level& L){
    if(this != &L){
        m_NbBonus = L.m_NbBonus;
        m_TabBrick = L.m_TabBrick;
        m_TabBall = L.m_TabBall;
        m_TabPaddle = L.m_TabPaddle;
        m_Score = L.m_Score;
        m_Hp = L.m_Hp;
        m_Jump = L.m_Jump;
    }
    return *this;
}
