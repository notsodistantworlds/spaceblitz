#include <stdio.h>
#include <stdlib.h>
#include <string>

class ArtAsset{
private:
	int xsize;
	int ysize;
	int length;
	char* data;
public:
	ArtAsset(int dataLength, int xsize, int ysize, char* data);
	void getSize(int& x, int& y);
	char* getData(int& length);
	char getChar(int x, int y);
};

class ArtAssetManager{
	static ArtAsset** artAssets;
public:
	static void init();
	static void loadAssets(std::string filename);
	static void draw(int assetArt, int assetColors, int x, int y, int layer);
	static ArtAsset* getAsset(int index);
};