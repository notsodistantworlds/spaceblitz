#include <gameengine.h>
#include <effects.h>
#include <math.h>
#include <stdlib.h>  
#include <gameconsole.h>
#include <artassetmanager.h>

Explosion::Explosion(int maxSize, int sizeGrowPerTick){
	this->maxSize = maxSize;
	this->sizePerTick = sizeGrowPerTick;
	this-> size = 0;
}

void Explosion::tick(){
	size+=sizePerTick;
	if(size>=maxSize)
		toBeDestroyed = 0;
}

int Explosion::getSize(){
	return size;
}

void BackgroundScenery::tick(){
	float x = 0;
	float y = 0;
	this->getPosition(x, y);
	this->setPosition(x, y-0.5);
}

BackgroundScenery::BackgroundScenery(){
	this->toBeDestroyed = 100;
}

BackgroundSceneryRenderer::BackgroundSceneryRenderer(BackgroundScenery* sc, int art, int col){
	g = sc->createPointer();
	this -> art = art;
	this -> col = col;
}

void BackgroundSceneryRenderer::draw(){
	int xpos = 0;//(*vehicle).getGridPos()[0];
	int ypos = 0;//(*vehicle).getGridPos()[1];
	BackgroundScenery* b = dynamic_cast<BackgroundScenery*>(g.getPointer());
	if(b!=0){
		b->getGridPos(xpos, ypos);
	}else return;
	ArtAssetManager::draw(art, col, xpos, ypos, 0);
}

void ExplosionRenderer::draw(){
	Explosion* e = dynamic_cast<Explosion*>(g.getPointer());
	if(e==0)return;
	int xpos = 0;
	int ypos = 0;
	int artXS;
	int artYS;
	int colYS;
	ArtAssetManager::getAsset(col)->getSize(artXS, colYS);
	ArtAssetManager::getAsset(art)->getSize(artXS, artYS);
	e->getGridPos(xpos, ypos);
	int size = e->getSize(); 
	for(int x = -size; x<size;x++){
		for(int y = -size; y<size;y++){
			float dist = sqrt((float)x*(float)x+(float)y*(float)y);
			float s = size+0.01;
			int artpos = round((dist/s)*(artXS-1.0));
			if(artpos>=artXS)artpos = artXS;
			if(artpos<0)artpos = 0;
			char a = ArtAssetManager::getAsset(art)->getChar(artpos,rand()%artYS);
			char c = ArtAssetManager::getAsset(col)->getChar(artpos,rand()%colYS);
			if(rand()%100<(1.0-(dist/s))*100.0){
				GameConsole::writeChar(xpos+x, ypos+y, a, c, 3);
			}
		}
	}
}

ExplosionRenderer::ExplosionRenderer(Explosion* exp, int art, int col){
	this-> g =  exp->createPointer();
	this-> art = art;
	this-> col = col;
}

ExplosionRenderer::~ExplosionRenderer(){

}

GameObject* EffectsSpawner::spawn(GameAsset* asset){
	switch(asset->getData(0)[0]){
		case 'e':{
			int art = std::stoi(asset->getData(1));
			int col = std::stoi(asset->getData(2));
			int msize = std::stoi(asset->getData(3));
			int sizept = std::stoi(asset->getData(4));
			Explosion* exp = new Explosion(msize, sizept);
			ExplosionRenderer* expren = new ExplosionRenderer(exp, art, col);
			exp->assignComponents(0, expren);
			return exp;
			}
	}
	return 0;
}

BackgroundScenery* EffectsSpawner::spawnBackground(int art, int col){
	BackgroundScenery* b = new BackgroundScenery();
	BackgroundSceneryRenderer* ren = new BackgroundSceneryRenderer(b, art, col);
	b->assignComponents(0, ren);
	return b;
}