//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/    /*Command*/		                                            /*Update Interval*/	/*Update Signal*/
    {" Ram: ",  "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	   2,		           0},
    {"Net: ",   "iwgetid -r",                                                  5,                  0},
    {"Bat: ",   "acpi | awk '{print $4}' | sed 's/,//g'",                      5,                  0},
    {"Vol: ",   "pamixer --get-volume",                                        2,                  0},
    {"Bri: ",   "xbacklight -get | awk '{print $1}' | sed 's/\\(\\.\\)[0-9]*//g'",                2,                  0},
	{"",        "date '+%b %d (%a) %H:%M'",					               60,		           0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
