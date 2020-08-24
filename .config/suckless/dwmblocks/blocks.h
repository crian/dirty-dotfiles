//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/    /*Command*/     /*Update Interval*/ /*Update Signal*/
    {"", "~/.config/dwm/blocks/net", 10, 0},

    {"", "~/.config/dwm/blocks/battery", 5, 0},

    {"", "~/.config/dwm/blocks/backlight", 0, 11},

    {"", "~/.config/dwm/blocks/volume", 0, 10},

    {"", "~/.config/dwm/blocks/date", 60, 0},

    {"", "~/.config/dwm/blocks/time", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
