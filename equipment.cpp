

#include <gameconsole.h>
#include <projectiles.h>
#include <vehicles.h>
#include <debuglogger.h>


#include <equipment.h>
#include <artassetmanager.h>
#include <gameassetmanager.h>
#include <math.h>
#include <stdio.h>






//class Vehicle;

Gun* EquipmentSpawner::spawnBasicGun(){
	
	Gun* g = new Gun(500, 1.5, 20,0, 1);
	GunRenderer* grend = new GunRenderer(g, 50, 50);
	GameObject* gun = g;
	gun -> assignComponents(0, grend);
	return g;
}


Gun* EquipmentSpawner::spawnBasicEnemyGun(){
	
	Gun* g = new Gun(500, -1.2, 10, 0, -2);
	GunRenderer* grend = new GunRenderer(g, 50, 50);
	GameObject* gun = g;
	gun -> assignComponents(0, grend);
	return g;
}

Equipment* EquipmentSpawner::spawnEquipment(GameAsset* asset){
	std::string t = asset->getData(0);
	switch(t[0]){
		case 'g':{
			
			int art = std::stoi(asset->getData(1));
			int col = std::stoi(asset->getData(2));
			float speed = std::stof(asset->getData(3));
			int reload = std::stoi(asset->getData(4));
			int spawnX = std::stoi(asset->getData(5));
			int spawnY = std::stoi(asset->getData(6));
			int proj = std::stoi(asset->getData(7));
			Gun* g = new Gun(proj, speed, reload, spawnX, spawnY);
			GunRenderer* grend = new GunRenderer(g, art, col);
			GameObject* gun = g;
			gun -> assignComponents(0, grend);
			return g;
			//gun
			}
		default: DebugLogger::outputLine("Unknown type"); return 0;
	}
}

Equipment::Equipment(){
	
}

void Equipment::updatePos(){
	int hx=0;
	int hy=0;
	GameObject* att = attachedTo.getPointer();
	if(att!=0)
		att->getGridPos(hx, hy);
	this->setPosition(xoff + hx,  yoff+hy);
	
	
}

void Equipment::tick(){
	
}

void Equipment::fire(){
	
}

void Equipment::attachEq(int x, int y, Vehicle* h){
	this -> attachedTo = h->createPointer();
	this -> xoff = x;
	this -> yoff = y;
}

Gun::Gun(int projAsset, float speed, int reloadTime, int spawnOffsetX, int spawnOffsetY){
	this -> projAsset = projAsset;
	this -> speed = speed;
	this -> reloadTime = reloadTime;
	this -> spawnOffsetX = spawnOffsetX;
	this -> spawnOffsetY = spawnOffsetY;
}

void Gun::tick(){
	if(attachedTo.getPointer()==0&&toBeDestroyed==-1)
		toBeDestroyed = 5;
	reload++;
}

void Gun::fire(){
	if(reload<reloadTime)return;
	reload = 0;
	int xp = 0;
	int yp = 0;
	this -> getGridPos(xp, yp);
	xp += spawnOffsetX;
	yp += spawnOffsetY;
	float vx = 0;
	float vy = 0;
	GameObject* att = attachedTo.getPointer();
	if(att!=0)
		att -> getRigidBody() -> getVelocity(vx, vy);
	GameObject * fired = GameAssetManager::spawn(projAsset);
	if(fired!=0){
		fired->setPosition(xp, yp);
		fired->setLayer(1);
		if(fired->getRigidBody()!=0){
			fired->getRigidBody()->setVelocity(vx, vy+speed);
		}
	}
}

GunRenderer::GunRenderer(Gun* gun, int art, int col){
	this -> g = gun->createPointer();
	this -> art = art;
	this -> col = col;
}

void GunRenderer::draw(){
	int xpos = 0;//(*vehicle).getGridPos()[0];
	int ypos = 0;//(*vehicle).getGridPos()[1];
	Gun* gun = dynamic_cast<Gun*>(g.getPointer());
	if(gun!=0){
		gun->getGridPos(xpos, ypos);
	}else return;
	ArtAssetManager::draw(art, col, xpos, ypos, 1);
}

GunRenderer::~GunRenderer(){
}
