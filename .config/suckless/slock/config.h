/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#2E3440",   /* after initialization */
	[INPUT] =  "#81A1C1",   /* during input */
	[FAILED] = "#BF616A",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* allow control key to trigger fail on clear */
static const int controlkeyclear = 0;

/* time in seconds before the monitor shuts down */
static const int monitortime = 360;

/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#D8DEE9";

/* text size (must be a valid size) */
static const char * font_name = "6x13";
