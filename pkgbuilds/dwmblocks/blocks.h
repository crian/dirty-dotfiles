//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Command*/    /*Update Interval*/    /*Update Signal*/
    {"~/.config/dwm/blocks/spotify", 1, 0},

    {"~/.config/dwm/blocks/net", 10, 0},

    {"~/.config/dwm/blocks/battery", 5, 0},

    {"~/.config/dwm/blocks/backlight", 0, 11},

    {"~/.config/dwm/blocks/volume", 0, 10},

    {"~/.config/dwm/blocks/date", 60, 0},

    {"~/.config/dwm/blocks/time", 60, 0},
};

//sets delimeter between status commands. NULL pointer means no delimeter.
static const char * delim = "  ";
