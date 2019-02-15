#include <assetimporter.h>
#include <debuglogger.h>
#include <stdio.h>

std::ifstream AssetImporter::openedFile;

bool AssetImporter::openFile(std::string name){
	if(openedFile.is_open())openedFile.close();
	openedFile.open(name);
	if(openedFile.is_open())
	DebugLogger::outputLine("Importing "+name); else DebugLogger::outputLine("File not found: "+name);
	return openedFile.is_open();
}

bool AssetImporter::fileOpened(){
	return openedFile.is_open();
}

std::string AssetImporter::readData(int& readSize){
	char readChar = openedFile.get();
	while(readChar=='/'){
		while(readChar != 10){
			readChar = openedFile.get();
		}
		readChar = openedFile.get();
	}

	switch(readChar){
		case 10:{ 
			DebugLogger::outputLine("Next entry"); 
			readSize = -1; 
			return ""; 
			if(openedFile.eof()){DebugLogger::outputLine("End of asset file");openedFile.close();}
			break;
			}
		default:{
			std::string read = "";
			int ch = openedFile.get();
			while(ch!=10&&!openedFile.eof()){
				if(ch>=0)
				read += (char)ch;
				ch = openedFile.get();
			}
			readSize = read.length();
			DebugLogger::outputLine("read data:"+read+"("+std::to_string(read.length())+")");
			if(openedFile.eof()){DebugLogger::outputLine("End of asset file");openedFile.close();}
			return read;break;
			}
	}
}

int AssetImporter::readInt(int fail){
	int size = 0;
	std::string data = AssetImporter::readData(size);
	int r = fail;
	if(size>0);
	try{
		r = std::stoi(data);
	}catch (std::exception& e){
		DebugLogger::outputLine("Attempting to read an int \""+data+"\":"+ e.what());
	}
	return r;
}

void AssetImporter::nextAsset(){
	
}