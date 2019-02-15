

#include <assetimporter.h>
#include <gameconsole.h>
#include <math.h>
#include <debuglogger.h>


#include <gameassetmanager.h>
#include <vehicles.h>
#include <equipment.h>
#include <projectiles.h>
#include <effects.h>

GameAsset** GameAssetManager::assets;
int GameAssetManager::assetAmount;

void GameAssetManager::init(){
	assetAmount = 5000;
	assets = new GameAsset*[assetAmount];
	for(int i =0; i<assetAmount; i++){
		assets[i] = 0;
	}
}

void GameAssetManager::loadAssets(std::string filename){
	if(!AssetImporter::openFile(filename))return;
	
	int readSize=0;
	std::string read = AssetImporter::readData(readSize);
	if(readSize>0){DebugLogger::outputLine("Expected the file to start with line feed character \\n"); return;}
	
	while(AssetImporter::fileOpened()){
		int index=0;
		int step = 0;
		readSize=0;
		bool playerUsable = false;
		int level = 0;
		int otype = 0;
		std::vector<std::string> data;
		try{
			
			DebugLogger::outputLine("Importing another asset");
			index = AssetImporter::readInt(0);
			step++;
			
			DebugLogger::outputLine("Importing asset index "+ std::to_string(index));
			
			otype = AssetImporter::readInt(0);
			DebugLogger::outputLine("object type: "+ std::to_string(otype));
			step++;
			
			level = AssetImporter::readInt(0);
			DebugLogger::outputLine("level = "+ std::to_string(level));
			step++;
			
			playerUsable = AssetImporter::readInt(0)>0;
			DebugLogger::outputLine("playerUsable = "+ std::to_string(playerUsable));
			step++;
			
			read = AssetImporter::readData(readSize);
			while(readSize>0){
				data.push_back(read);
				read = AssetImporter::readData(readSize);
			}
			step++;
		}catch (std::exception& e){
			DebugLogger::outputLine("Parse error on step "+std::to_string(step)+": "+ e.what());
		}
		if(assets[index]!=0){DebugLogger::outputLine("Asset "+std::to_string(index)+" already imported!");continue;}
		assets[index] = new GameAsset(playerUsable, otype, level);
		
		for(int i = 0; i<data.size(); i++){
			assets[index]->loadData(data[i]);
			DebugLogger::outputLine("data["+std::to_string(i)+"] = "+ assets[index]->getData(i));
		}
		
	}
	
}

std::vector<GameAsset*> GameAssetManager::getAssets(int objType, int levelMin, int levelMax, bool playerUsable){
	std::vector<GameAsset*> r;
	for(int i = 0; i<assetAmount; i++){
		if(assets[i]!=0){
			if(assets[i]->qualifies(playerUsable, objType, levelMin, levelMax))
				r.push_back(assets[i]);
		}
	}
	return r;
}

GameObject* GameAssetManager::spawn(int index){
	if(assets[index]!=0)
	return assets[index]->spawn(); else return 0;
}

GameAsset::GameAsset(bool playerUsable, int objType, int level){
	this -> playerUsable = playerUsable;
	this -> objType = objType;
	this -> level = level;
}

void GameAsset::loadData(std::string s){
	this->data.push_back(s);
}

std::string GameAsset::getData(int index){
	if(index<data.size())
	return data[index]; else return "";
}

GameObject* GameAsset::spawn(){
	switch(objType){
		case 0:
			return VehicleSpawner::spawn(this);
		case 1:
			return EquipmentSpawner::spawnEquipment(this);
		case 2:
			return ProjectileSpawner::spawnProjectile(this);
		case 10:
			return EffectsSpawner::spawn(this);
		
		default: DebugLogger::outputLine("Attempting to spawn asset - unknown object type"); return 0;
	}
}

bool GameAsset::qualifies(bool playerUsable, int objType, int levelMin, int levelMax){
	if(this->playerUsable == playerUsable)
		if(this->objType==objType)
			if(this->level<=levelMax&&this->level>=levelMin)
				return true;
	return false;
}