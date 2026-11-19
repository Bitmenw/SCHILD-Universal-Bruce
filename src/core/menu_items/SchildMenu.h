#ifndef __SCHILD_MENU_H__
#define __SCHILD_MENU_H__

#include "MenuItemInterface.h"

class SchildMenu : public MenuItemInterface {
public:
    void optionsMenu(void) override;
    void draw(void) override;
    String getName(void) override;

private:
    String _name = "SCHILD";
};

#endif
