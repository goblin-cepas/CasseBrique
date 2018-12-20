#include "Score.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

#include "window.h"
#include "playerScore.h"

Score::Score() : m_fileName("score.cfg") {
}

Score::Score(std::string fileName) : m_fileName(fileName) {
}

std::string Score::getFileName() {
    return this->m_fileName;
}

void Score::setFileName(std::string New) {
    this->m_fileName = New;
}

std::vector<playerScore> Score::getScoreTab() {
    if (!this->read()) {
        std::cerr << "error : from read method" << std::endl;
    }
    return this->m_scoreTab;
 
}

bool Score::read() {
    std::string lineBuffer;
    std::string delimiter = ",";
    playerScore scoreLine;
    this->m_scoreFlux.open(this->m_fileName, std::fstream::in);
    if (this->m_scoreFlux.is_open()) {
        while (getline(this->m_scoreFlux, lineBuffer)) {
            scoreLine.pseudo = lineBuffer.substr(0, lineBuffer.find(delimiter));
            scoreLine.score = atoi(lineBuffer.substr(lineBuffer.find(delimiter) + 1, lineBuffer.length()).c_str());
            this->m_scoreTab.push_back(scoreLine);
        }
        this->m_scoreFlux.close();
        return true;
    } else {
        return false;
    }
}

bool Score::write(int score, std::string pseudo) {
    if (!this->read()) {
        std::cerr << "error : from read method" << std::endl;
    }

    playerScore scoreLine;
    scoreLine.pseudo = pseudo;
    scoreLine.score = score;
    this->m_scoreTab.push_back(scoreLine);

    if (!this->sorting()) {
        std::cerr << "error : from sorting method" << std::endl;
    }

    this->m_scoreFlux.open(this->m_fileName, std::ios::out);

    if (this->m_scoreFlux.is_open()) {
        std::cout << "file is open" << std::endl;
        std::cout << this->m_scoreTab.size() << std::endl;
        for (int i = 0; i<this->m_scoreTab.size() - 1; i++) {
            this->m_scoreFlux << this->m_scoreTab[i].pseudo;
            this->m_scoreFlux << ",";
            this->m_scoreFlux << this->m_scoreTab[i].score;
            this->m_scoreFlux << std::endl;
        }
        this->m_scoreFlux.close();
        return true;
    } else {
        std::cerr << "error : from write method" << std::endl;
        return false;
    }

}

bool Score::sorting() {
    for (int i = 0; i<this->m_scoreTab.size() - 1; i++) {
        int start = i;
        int end = this->m_scoreTab.size() - 1;
        while (start < end) {
            if (this->m_scoreTab[start].score < this->m_scoreTab[end].score) {
                std::swap(m_scoreTab[start], this->m_scoreTab[end]);
            } else {
                end--;
            }
        }
    }
    return true;
}

bool Score::printScoreScreen() {
    if (!this->read()) {
        std::cerr << "error : from read method" << std::endl;
    }
    Window scoreScreen(50, 50, 0, 0);
    int ch;
    Color color(BRED);
    Color color2(WBLUE);
    Color color3(BYELLOW);
    int nbscore;
    if (m_scoreTab.size() > 5) {
        nbscore = 5;
    } else {
        nbscore = m_scoreTab.size();
    }
    while ((ch = getch()) != 'q') {
        scoreScreen.print(4, 2, " ______   _____    _____     _____     _____ ", color);
        scoreScreen.print(4, 3, "|  ____| |  ___|  |  _  |   |  _  |   |  ___|", color);
        scoreScreen.print(4, 4, "| |____  | |      | | | |   | |_| |   | |___ ", color);
        scoreScreen.print(4, 5, "|____  | | |      | | | |   |     |   |  ___|", color);
        scoreScreen.print(4, 6, " ____| | | |___   | |_| |   | | |\\    | |___ ", color);
        scoreScreen.print(4, 7, "|______| |_____|  |_____|   |_| |_|   |_____|", color);
        scoreScreen.print(4, 8, "                                             ", color);
        for (int i = 9; i <= 30; i++) {
            scoreScreen.print(4, i, "                                             ", color2);
        }

        for (int i = 0; i < nbscore; i++) {
            scoreScreen.print(15, 15 + i * 2, "rank", color2);
            scoreScreen.print(20, 15 + i * 2, std::to_string(i + 1), color2);
            scoreScreen.print(25, 15 + i * 2, m_scoreTab[i].pseudo, color2);
            scoreScreen.print(22, 15 + i * 2, " : ", color2);
            scoreScreen.print(31, 15 + i * 2, std::to_string(m_scoreTab[i].score), color2);
        }        
        scoreScreen.print(12, 29 , "press 'q' to return home", color3);
        sleep(2);
        scoreScreen.clear();
    }
    
    return true;
}