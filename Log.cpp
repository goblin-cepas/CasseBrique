#include "Log.h"

#include <fstream>
#include <string>
#include <ctime>

Log::Log() : m_fileName("log.cfg") {
};

Log::Log(std::string fileName) : m_fileName(fileName) {
};

std::string Log::getFileName() {
    return this->m_fileName;
}

std::string Log::getLog() {
    return this->m_log;
}

void Log::setLog(std::string New) {
    this->m_log = New;
}

void Log::setFileName(std::string New) {
    this->m_fileName = New;
}

bool Log::write(std::string logText) {
    this->setLog(logText);
    this->m_timeNow = time(0);
    this->m_date = ctime(&m_timeNow);
    // this permit to erase the chars "\n" into m_date
    this->m_date.erase(this->m_date.length() - 1, this->m_date.length());
    this->m_outLog.open(this->m_fileName, std::ios::out | std::ios::app);
    if (this->m_outLog.is_open()) {
        this->m_outLog << this->m_date;
        this->m_outLog << " : ";
        this->m_outLog << this->m_log;
        this->m_outLog << std::endl;
        this->m_outLog.close();
        return true;
    } else {
        return false;
    }
}