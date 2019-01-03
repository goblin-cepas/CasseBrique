#ifndef HOME_H
#define HOME_H
#include <ncurses.h>

class Home {
public:

    enum select {
        arcade1,
        arcade2,
        arcade3,
        arcade4,
        arcade5,
        campaign,
        scoreboard,
        cont, //'continue' is already used by a c++ command
        quit,
        empty
    };
    Home();
    Home(select Selection);
    virtual ~Home();

    ////////////////////////////////////////////////////////////
    /// Input : Nothing
    ///
    /// Result : Return the selected option.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    select getSelect() const;

   
    ////////////////////////////////////////////////////////////
    /// Input : select Selection
    ///
    /// Result : Display the main menu and launch the game with
    /// the selected option.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void menu();


private:
    select m_selection;

    ////////////////////////////////////////////////////////////
    /// Input : select New
    ///
    /// Result : Set the current option.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void setSelect(select New);

    ////////////////////////////////////////////////////////////
    /// Input : int height, int width, int startY, int startX
    ///
    /// Result : Create a window
    /// 
    /// info : 
    ////////////////////////////////////////////////////////////
    //WINDOW *create_newwin(int height, int width, int starty, int startx);

    ////////////////////////////////////////////////////////////
    /// Input : Nothing 
    ///
    /// Result : Draw the menu interface.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    void userInterface();

};

#endif /* HOME_H */

