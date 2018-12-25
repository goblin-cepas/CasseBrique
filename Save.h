
#ifndef SAVE_H
#define SAVE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Level.h"
#include "Rectangle.h"

class Save {
public:
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Create a Save entity.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    
    Save();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Delete the aforesaid Save entity.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    
    virtual ~Save();

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Return the string containting the save file name.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    std::string getFile() const;
    
    ////////////////////////////////////////////////////////////
    /// Input : std::string file
    ///
    /// Result : Set the save file name.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    
    void setFile(std::string file);
    
    ////////////////////////////////////////////////////////////
    /// Input : Level& level
    ///
    /// Result : Create or write on the save file with the current's
    /// file save.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    
    void writeSave(Level& level);
    
    ////////////////////////////////////////////////////////////
    /// Input : std::string file
    ///
    /// Result : Load a level contained in the aforesaid file.
    ///
    /// info : Once loaded, the method getLoadedGame must be
    /// called in order to retreive the level.
    ////////////////////////////////////////////////////////////
    
    void loadSave(std::string file);
    
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Return the loaded level as a pointer.
    ///
    /// info :
    ////////////////////////////////////////////////////////////
    
    Level* getLoadedGame();
    
    
private:
    std::string file;
    std::ofstream* of = NULL;
    std::ifstream* ifile = NULL;
    Level* loadedGame = NULL;

    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Initialize the pointer associated with the future
    /// loaded level.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void initLevel();
    
    ////////////////////////////////////////////////////////////
    /// Input : std::string newfile
    ///
    /// Result : Initialize the pointer associated with the input
    /// flow.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void initInput(std::string newFile);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the value of bonuses.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readBonus();
   
  
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Initialize the pointer associated with the output
    /// flow.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void initOutput();
    
    ////////////////////////////////////////////////////////////
    /// Input : const std::vector<Paddle>& paddles
    ///
    /// Result : Write the paddle preset.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void writePaddles(const std::vector<Paddle>& paddles);
    
    ////////////////////////////////////////////////////////////
    /// Input : std::string str
    ///
    /// Result : Write a string.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void writeLine(std::string str);
    
    ////////////////////////////////////////////////////////////
    /// Input : const std::vector<Ball>& balls 
    ///
    /// Result : Write the ball preset.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void writeBalls(const std::vector<Ball>& balls);
    
    ////////////////////////////////////////////////////////////
    /// Input : const std::vector<Brick>& bricks
    ///
    /// Result : Write the bricks presets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void writeBricks(const std::vector<Brick>& bricks);
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the game type resets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    
    void readGameType();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the paddle presets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    
    void readPaddle();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the game window presets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readGameWindow();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the menu window presets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readMenuWindow();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the ball presets.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readBalls();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive score value.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readScore();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive HP value.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readHP();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive jump values.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readJump();
    
    ////////////////////////////////////////////////////////////
    /// Input : None
    ///
    /// Result : Retreive the bricks values.
    ///
    /// info : This method is ONLY meant to be use as a submethod
    ////////////////////////////////////////////////////////////
    
    void readBricks();
    

};

#endif /* SAVE_H */

