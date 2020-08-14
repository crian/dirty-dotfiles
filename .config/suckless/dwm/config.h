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
	/* class     instance  title           tags mask  isfloating  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          -1 },
	{ "floatst", NULL,     NULL,           0,         1,          -1 },
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

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "70x20", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_p,      spawn,          SHCMD("dmn_run") },
	{ MODKEY,                       XK_Escape, spawn,          SHCMD("dmn_power") },
	{ MODKEY,                       XK_c,      spawn,          SHCMD("dmn_clip") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD("dmn_search") },
	{ MODKEY,                       XK_n,      spawn,          SHCMD("networkmanager_dmenu") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("st -c floatst") },
	{ MODKEY|ControlMask,           XK_Return, spawn,          SHCMD("tabbed -d -c st -w") },
	{ MODKEY,                       XK_Down,   spawn,          SHCMD("playerctl play-pause") },
	{ MODKEY,                       XK_Up,     spawn,          SHCMD("playerctl stop") },
	{ MODKEY,                       XK_Right,  spawn,          SHCMD("playerctl next") },
	{ MODKEY,                       XK_Left,   spawn,          SHCMD("playerctl previous") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("pcmanfm") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("st -e lf") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("spoti") },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ControlMask,           XK_j,      shiftview,      {.i = +1 } },
	{ MODKEY|ControlMask,           XK_k,      shiftview,      {.i = -1 } },
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
	{ 0,                            XF86XK_AudioMute,        spawn, SHCMD("vol mute") },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, SHCMD("vol down") },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, SHCMD("vol up") },
	{ 0,                            XF86XK_MonBrightnessUp,  spawn, SHCMD("bri up") },
	{ 0,                            XF86XK_MonBrightnessDown,spawn, SHCMD("bri down") },
	{ 0,                            XF86XK_AudioNext,        spawn, SHCMD("playerctl next") },
	{ 0,                            XF86XK_AudioPrev,        spawn, SHCMD("playerctl previous") },
	{ 0,                            XF86XK_AudioPlay,        spawn, SHCMD("playerctl play-pause") },
	{ 0,                            XF86XK_AudioStop,        spawn, SHCMD("playerctl stop") },
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
