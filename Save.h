#ifndef SAVE_H
#define SAVE_H
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "window.h"
#include "Level.h"

class Save {
public:
    Save();
    Save(std::string);
   ~Save();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Get the file name associated to the stream
    /// 
    /// info : might be used to make custom/mutiple saves.
    ////////////////////////////////////////////////////////////
    std::string getFileName() const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Get the needed level
    /// 
    /// info : Is used to create a savefile from the aforeseaid level
    ////////////////////////////////////////////////////////////
    Level getLevel() const;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Access the save and read it.
    /// 
    /// info : Is used to load the save.
    ////////////////////////////////////////////////////////////
    std::ifstream readFile();

    ////////////////////////////////////////////////////////////
    /// Input : level currentLevel
    ///
    /// Result : Fill the save file with the (new) current level data.
    /// 
    /// info : The save file is overwritted with the default configuration  
    /// related to the level type.
    ////////////////////////////////////////////////////////////
    bool createSave(Level level);

    ////////////////////////////////////////////////////////////
    /// Input : level currentLevel
    ///
    /// Result : Fill the save file with the user's progress in
    /// the current level.
    ///
    /// info : The save file is overwritted with the current level
    /// status data.
    ////////////////////////////////////////////////////////////
    void writeSave(Level level);

    ////////////////////////////////////////////////////////////
    /// Input : ifstream
    ///
    /// Result : Load a level with the saved configurations.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    Level load(std::ifstream);

private:
    std::string m_fileName;
    Level m_level;

    ////////////////////////////////////////////////////////////
    /// Input : char* New
    ///
    /// Result : None
    /// 
    /// info : Set the save file name
    ////////////////////////////////////////////////////////////
    void setFileName(char* New);

    ////////////////////////////////////////////////////////////
    /// Input : level New
    ///
    /// Result : None
    /// 
    /// info : Set the save file level
    ////////////////////////////////////////////////////////////
    void setLevel(Level New);
};

#endif /* SAVE_H */ 

