#ifndef gameassetmanager_h
#define gameassetmanager_h
#include <memory>
#include <vector>
#include <gameengine.h>

class GameAsset{
private:
	bool playerUsable;
	int objType;
	int level;
	std::vector<std::string> data;
public:
	GameAsset(bool playerUsable, int objType, int level);
	void loadData(std::string s);
	std::string getData(int index);
	GameObject* spawn();
	bool qualifies(bool playerUsable, int objType, int levelMin, int levelMax);
};

class GameAssetManager{
	static int assetAmount;
	static GameAsset** assets;
public:
	static void init();
	static void loadAssets(std::string filename);
	static GameObject* spawn(int index);
	static std::vector<GameAsset*> getAssets(int objType, int levelMin, int levelMax, bool playerUsable);
};

#endif