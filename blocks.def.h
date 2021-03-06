//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/    /*Command*/		                                            /*Update Interval*/	/*Update Signal*/
    {" CPU: ", "awk 'length==6{printf("%.0f MHz", $0/10^3); next} length==7{printf("%.1f GHz", $0/10^6)}' /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq", 2, 0},
	{"Ram: ",  "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	   2,		           0},
    {"Net: ",   "iwgetid -r",                                                  5,                  0},
    {"Bat: ",   "acpi | awk '{print $5}'",                      5,                  0},
    {"Vol: ",   "pamixer --get-volume",                                        2,                  0},
    {"Bri: ",   "xbacklight -get | awk '{print $1}' | sed 's/\\(\\.\\)[0-9]*//g'",                2,                  0},
	{"",        "date '+%b %d (%a) %H:%M'",					               60,		           0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
