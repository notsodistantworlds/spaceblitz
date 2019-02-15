#include <artassetmanager.h>
#include <assetimporter.h>
#include <gameconsole.h>
#include <math.h>
#include <debuglogger.h>

ArtAsset** ArtAssetManager::artAssets;

void ArtAssetManager::init(){
	int assetAmount = 5000;
	artAssets = new ArtAsset*[assetAmount];
	for(int i =0; i<assetAmount; i++){
		artAssets[i] = 0;
	}
}

ArtAsset* ArtAssetManager::getAsset(int index){
	return artAssets[index];
}

void ArtAssetManager::loadAssets(std::string filename){
	if(!AssetImporter::openFile(filename))return;
	
	while(AssetImporter::fileOpened()){
		DebugLogger::outputLine("Attempting to locate another asset...");
		int readSize=0;
		int index=0;
		int xsize = 0;
		int ysize = 0;
		std::string data = "";
		int step = 0;
		try{
			data = AssetImporter::readData(readSize);
			if(readSize>0){DebugLogger::outputLine("Expected another asset "+std::to_string(readSize)); return;}
			step++;
			if(!AssetImporter::fileOpened())return;
			
			DebugLogger::outputLine("Importing another art asset");
			index = AssetImporter::readInt(0);
			step++;
			DebugLogger::outputLine("Importing art asset index "+ std::to_string(index));
			
			
			xsize = AssetImporter::readInt(0);
			DebugLogger::outputLine("xsize = "+ std::to_string(xsize));
			step++;
			
			ysize = AssetImporter::readInt(0);
			DebugLogger::outputLine("ysize = "+ std::to_string(ysize));
			step++;
			
			data = AssetImporter::readData(readSize);
			DebugLogger::outputLine("data = "+ data);
			step++;
			
		}catch (std::exception& e){
			DebugLogger::outputLine("Parse error on step "+std::to_string(step)+": "+ e.what());
		}
		char* d = new char[data.length()];
		for(int i = 0; i<data.length(); i++){
			d[i] = data[i];
		}
		if(artAssets[index]!=0){DebugLogger::outputLine("Art asset "+std::to_string(index)+" already imported!");continue;}
		DebugLogger::outputLine("Asset "+std::to_string(index)+
		"[xsize:"+std::to_string(xsize)+","+
		"ysize:"+std::to_string(ysize)+","+
		"datalength:"+std::to_string(data.length())+"]");
		artAssets[index] = new ArtAsset(readSize, xsize, ysize, d);
	}
	
}

void ArtAssetManager::draw(int assetArt, int assetColors, int x, int y, int layer){
	ArtAsset* art = artAssets[assetArt];
	ArtAsset* colors = artAssets[assetColors];
	if(art == 0||colors == 0) {
		GameConsole::writeChar(x, y, 'x', GameConsole::getColorPair(4,0), layer);
		return;
	}
	int xsize = 0;
	int ysize = 0;
	art->getSize(xsize, ysize);
	for(int xx = 0; xx<xsize; xx++){
		for(int yy=0; yy<ysize; yy++){
			char a = art->getChar(xx, yy);
			char c = colors->getChar(xx, yy);
			GameConsole::writeChar(x+xx-round(((float)xsize)/2.0)+1, y+yy-round(((float)ysize)/2.0)+1, a, c, layer);
		}
	}
}

ArtAsset::ArtAsset(int dataLength, int xsize, int ysize, char* data){
	this -> xsize = xsize;
	this -> ysize = ysize;
	this -> length = dataLength;
	this -> data = new char[length];
	for(int i = 0; i<length; i++){
		this->data[i] = data[i];
	}
}

void ArtAsset::getSize(int& x, int& y){
	x = this->xsize;
	y = this->ysize;
}

char ArtAsset::getChar(int x, int y){
	if(x+y*xsize<length){
		return data[x+y*xsize];
	}return 'x';
}