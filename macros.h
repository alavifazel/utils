#ifndef MACRO
#define MACRO

#define USAGE "\
General commands:  \n\
timer 	Starts a loop and prints out the time.\n\
\nCode generation commands: \n\
(Supported languages: Java, C)\n\
<lang> gs	Generates getter/setters of the given field (for OOP languages).\n\
<lang> bp	Outputs a starting code boilerplate for the specified language.\n\
\nExample usage:\n\
	x java gs private int myField\\;\n\
	x timer\n"

#define C_BOILERPLATE "\
#include <stdio.h>\n\
\n\
int main(int argv, char** argc) {\n \
    return 0;\n\
}\n"

#define HTML_BOILERPLATE "\
<!DOCTYPE html>\"\n\
<html lang=\"en\">\n\
<head>\n\
\t<meta charset=\"UTF-8\">\n\
\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n\
\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
\t<title>Document</title>\n\
</head>\n\
<body>\n\
\n\
</body>\n\
</html>\n"

#endif
