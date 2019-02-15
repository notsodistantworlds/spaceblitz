#include <gameassetmanager.h>

class Explosion : public GameObject{
private:
	int maxSize;
	int sizePerTick;
	
	int size;
public:
	Explosion(int maxSize, int sizeGrowPerTick);
	void tick();
	int getSize();
};

class BackgroundScenery : public GameObject{
public:
	BackgroundScenery();
	void tick();
};

class BackgroundSceneryRenderer : public Renderer{
	int art;
	int col;
public:
	BackgroundSceneryRenderer(BackgroundScenery* sc, int art, int col);
	void draw();
};


class ExplosionRenderer : public Renderer{
	int art;
	int col;
public:
	ExplosionRenderer(Explosion* exp, int art, int col);
	~ExplosionRenderer();
	void draw();
};

class EffectsSpawner{
public:
	static GameObject* spawn(GameAsset* asset);
	static BackgroundScenery* spawnBackground(int art, int col);
};