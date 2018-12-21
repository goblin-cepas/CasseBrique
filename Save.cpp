#include "Save.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Level.h"

Save::Save(): m_fileName("save.cfg") {
}

Save::Save(std::string file) : m_fileName(file) {
}

Save::~Save() {
}

std::string Save::getFileName() const {
    return this->m_fileName;
}

Level Save::getLevel() const {
    return this->m_level;
}

void Save::setLevel(Level New) {
    this->m_level = New;
}

void Save::setFileName(char* New) {
    this->m_fileName = New;
}

Level Save::load(std::ifstream) {
}

void Save::writeSave(Level level) {
    std::ofstream of("save.cfg", std::ios::out);
    if (!of.is_open()) {
        std::cerr << "ERROR : save file opening failed !" << std::endl;
    } else {
        std::cout << "heyr" << std::endl;
        of.seekp(4);
        char* buff;
        buff = "43";
        //(char*)level.getScore();
        std::cout << "lourd" << std::endl;
        of << buff;
        std::cout << "le bro" << std::endl;

        of.close();
        std::cout << "yes" << std::endl;
    }
    if (of.is_open()) {
        std::cerr << "ERROR : save file closing failed !" << std::endl;
    }
}

bool Save::createSave(Level level) {
}

std::ifstream Save::readFile() {
}