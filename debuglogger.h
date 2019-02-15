#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class DebugLogger{
	static std::ofstream file;
public:	
	static void init();
	static void outputLine(std::string s);
};