#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class AssetImporter{
	static std::ifstream openedFile;
	
public:
	static bool openFile(std::string name);
	static std::string readData(int& readSize);
	static int readInt(int fail);
	static void nextAsset();
	static bool fileOpened();
};