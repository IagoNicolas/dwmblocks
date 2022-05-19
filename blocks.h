//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/    /*Command*/		                                            /*Update Interval*/	/*Update Signal*/
    {" Ram: ",  "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",     2,		           0},
    {"Net: ",   "iwgetid -r",                                                  5,                  0},
    {"Bat0: ",   "cat /sys/class/power_supply/BAT0/capacity",                 30,                  0},
    {"Bat1: ",   "cat /sys/class/power_supply/BAT1/capacity",                 30,                  0},
    {"Vol: ",   "pamixer --get-volume",                                        2,                  0},
    {"Bri: ",   "xbacklight -get | awk '{print $1}' | sed 's/\\(\\.\\)[0-9]*//g'",                2,                  0},
	{"",        "date '+%b %d (%a) %H:%M'",					               60,		           0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
