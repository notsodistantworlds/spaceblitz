#include <debuglogger.h>

std::ofstream DebugLogger::file;

void DebugLogger::init(){
	file.open("debug.txt");
}

void DebugLogger::outputLine(std::string s){
	file << s << '\n';
}