#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <ctime>

class Log {
public:
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with default m_fileName to 'log.cfg'
    ////////////////////////////////////////////////////////////
    Log();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Log instance with specific m_fileName
    ////////////////////////////////////////////////////////////
    Log(std::string fileName);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : type string ,return the value of the attribut m_fileName.
    /// 
    /// info : /
    ////////////////////////////////////////////////////////////
    std::string getFileName();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : type string ,return the value of the attribut m_log.
    /// 
    /// info : /
    ////////////////////////////////////////////////////////////
    std::string getLog();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Bool, True if the File is Correctly written, else False
    /// 
    /// info :  The method concatenate the attribut m_string into the file 
    ///         with name m_fileName (default : log.cfg)
    ///         like 'Tue Nov 20 21:21:49 2018 : logText'
    ////////////////////////////////////////////////////////////
    bool write(std::string logText);
    
private:

    std::string m_fileName;
    std::string m_log;
    std::ofstream m_outLog;
    time_t m_timeNow;
    std::string m_date;
    
    ////////////////////////////////////////////////////////////
    /// Input : String, a new value to remplace the m_log value
    ///
    /// Result : None
    /// 
    /// info : /
    ////////////////////////////////////////////////////////////
    void setLog(std::string New);
    
    ////////////////////////////////////////////////////////////
    /// Input : String, a new value to remplace the m_fileName value
    ///
    /// Result : None
    /// 
    /// info : /
    ////////////////////////////////////////////////////////////
    void setFileName(std::string New);
};

#endif /* LOG_H */

