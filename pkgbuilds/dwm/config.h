/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 10;       /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int barheight = 6;        /* bar height */
static const unsigned int statuspad = 4;        /* status padding */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
    "IBM Plex Mono:size=10:antialias=true:autohint=true",
    "siji:size=12:antialias=true:autohint=true"
};
static const char dmenufont[]        = "monospace:size=10";
static const char normfgcolor[]      = "#d8dee9";
static const char normbgcolor[]      = "#2e3440";
static const char normbordercolor[]  = "#3b4252";
static const char selfgcolor[]       = "#81a1c1";
static const char selbgcolor[]       = "#3b4252";
static const char selbordercolor[]   = "#81a1c1";
static const char titlefgcolor[]     = "#a3be8c";
static const char titlebgcolor[]     = "#2e3440";
static const char titlebordercolor[] = "#2e3440";
static const char *colors[][3]       = {
	/*                fg            bg                border   */
	[SchemeNorm]  = { normfgcolor,  normbgcolor,      normbordercolor },
	[SchemeSel]   = { selfgcolor,   selbgcolor,       selbordercolor },
	[SchemeTitle] = { titlefgcolor, titlebgcolor,     titlebordercolor },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },
	{ "floatst",  NULL,       NULL,       0,            1,           1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "bstack.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  ",      tile },    /* first entry is default */
	{ "  ",      NULL },    /* no layout function means floating behavior */
	{ "  ",      monocle },
	{ "  ",      bstack },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for executing programs */
#define ESHCMD(cmd) SHCMD("exec " cmd)

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmn_run", NULL };
static const char *dmenupwr[]      = { "dmn_power", NULL };
static const char *dmenuclp[]      = { "dmn_clip", NULL };
static const char *dmenusrh[]      = { "dmn_search", NULL };
static const char *dmenunet[]      = { "networkmanager_dmenu", NULL };
static const char *termcmd[]       = { "st", NULL };
static const char *tabterm[]       = { "tabbed", "-d", "-c", "st", "-w", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "70x20", NULL };
static const char *mutecmd[]       = { "vol", "mute", NULL };
static const char *volupcmd[]      = { "vol", "up", NULL };
static const char *voldowncmd[]    = { "vol", "down", NULL };
static const char *briupcmd[]      = { "bri", "up", NULL };
static const char *bridowncmd[]    = { "bri", "down", NULL };
static const char *plyrplay[]      = { "playerctl", "play-pause", NULL };
static const char *plyrstop[]      = { "playerctl", "stop", NULL };
static const char *plyrnext[]      = { "playerctl", "next", NULL };
static const char *plyrprev[]      = { "playerctl", "previous", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Escape, spawn,          {.v = dmenupwr } },
	{ MODKEY,                       XK_c,      spawn,          {.v = dmenuclp } },
	{ MODKEY,                       XK_w,      spawn,          {.v = dmenusrh } },
	{ MODKEY,                       XK_n,      spawn,          {.v = dmenunet } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = tabterm } },
	{ MODKEY|ControlMask,           XK_Return, spawn,          SHCMD("st -c floatst") },
	{ MODKEY,                       XK_s,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_Down,   spawn,          {.v = plyrplay } },
	{ MODKEY,                       XK_Up,     spawn,          {.v = plyrstop } },
	{ MODKEY,                       XK_Right,  spawn,          {.v = plyrnext } },
	{ MODKEY,                       XK_Left,   spawn,          {.v = plyrprev } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          ESHCMD("dmenufm") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          ESHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          ESHCMD("pcmanfm") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          ESHCMD("spotify") },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Tab,    zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ControlMask,           XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_plus,   setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_plus,   setgaps,        {.i = 0 } },
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ 0,                            XF86XK_AudioMute,        spawn, {.v = mutecmd } },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = voldowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = volupcmd } },
	{ 0,                            XF86XK_MonBrightnessUp,  spawn, {.v = briupcmd } },
	{ 0,                            XF86XK_MonBrightnessDown,spawn, {.v = bridowncmd } },
	{ 0,                            XF86XK_AudioNext,        spawn, {.v = plyrnext } },
	{ 0,                            XF86XK_AudioPrev,        spawn, {.v = plyrprev } },
	{ 0,                            XF86XK_AudioPlay,        spawn, {.v = plyrplay } },
	{ 0,                            XF86XK_AudioStop,        spawn, {.v = plyrstop } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
