#ifndef SCORE_H
#define SCORE_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "window.h"
#include "playerScore.h"

class Score {
public:
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Score instance with default m_fileName to 'score.cfg'
    ////////////////////////////////////////////////////////////
    Score();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : None
    /// 
    /// info :  Construct Score instance with specific m_fileName
    ////////////////////////////////////////////////////////////
    Score(std::string fileName);
    
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
    /// Result : type std::vector<playerScore> ,return dynamic table of playerScore struct
    /// 
    /// info :  this method call the method read(),
    ///         if the file was written once, the score are decreasing in the 
    ///         std::vector<playerScore> Result
    ////////////////////////////////////////////////////////////
    std::vector<playerScore> getScoreTab();
    
    ////////////////////////////////////////////////////////////
    /// Input : int score; the score to write, std::string pseudo; pseudo of the player
    ///
    /// Result : bool, True if Correctly read, sorting and written, False Else
    /// 
    /// info :  cerr get the error if one append
    ///         this method call method, read(), sorting(),
    ///         so the file after call contain the scores and pseudo
    ///         with decreasing score
    ////////////////////////////////////////////////////////////
    bool write(int score, std::string pseudo);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : bool, True if Correctly displayed, False Else
    /// 
    /// info :  cerr get the error if one append
    ///         this method call method, read()
    ////////////////////////////////////////////////////////////
    bool printScoreScreen();
    
private:
    std::string m_fileName;
    std::fstream m_scoreFlux;
    std::vector<playerScore> m_scoreTab;

    ////////////////////////////////////////////////////////////
    /// Input : String, a new value to remplace the m_fileName value
    ///
    /// Result : None
    /// 
    /// info : /
    ////////////////////////////////////////////////////////////
    void setFileName(std::string New);

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Bool, True if m_scoreTab is correctly filled, False Else
    /// 
    /// info :  This method read the file with m_fileName name (default 'score.cfg')
    ///         and fill std::vector<playerScore> m_scoreTab
    ////////////////////////////////////////////////////////////
    bool read();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result :Bool, True is correctly std::vector<playerScore> m_scoreTab sorting,
    ///         False else
    ///
    /// info :  This method sort m_scoreTab with descreasing score but
    ///         complexity is O(m_scoreTab.size²), so if we'll have time
    ///         later we will improve to n.log(n)
    ////////////////////////////////////////////////////////////
    bool sorting();
};

#endif /* SCORE_H */

