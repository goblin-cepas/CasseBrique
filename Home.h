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
    /// Input : Nothing 
    ///
    /// Result : Draw the menu interface.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool userInterface();

    ////////////////////////////////////////////////////////////
    /// Input : select Selection
    ///
    /// Result : Launch the game with the selected option.
    /// 
    /// info :
    ////////////////////////////////////////////////////////////
    bool launcher();


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
    /// Input : WINDOW *localWindow 
    ///
    /// Result : Destoy a window
    /// 
    /// info : 
    ////////////////////////////////////////////////////////////

   // void destroy_win(WINDOW *local_win);

    
    //void print_menu(WINDOW *menu_win, int highlight);
};

#endif /* HOME_H */

