#ifndef equipment_h
#define equipment_h
#include <gameengine.h>

class Vehicle;
class GameAsset;

class Equipment : public GameObject{
protected:
	GOPointer attachedTo;
	
	int xoff;
	int yoff;
	
public:
	Equipment();
	void attachEq(int x, int y, Vehicle* h);
	void updatePos();
	virtual void fire();
	virtual void tick();
};

class Gun : public Equipment{
	int reloadTime;
	float speed;
	
	int projAsset;
	
	int spawnOffsetX;
	int spawnOffsetY;
	
	int reload;
public:
	Gun(int projData, float speed, int reloadTime, int spawnOffsetX, int spawnOffsetY);
	
	void tick();
	void fire();
};

class GunRenderer:public Renderer{
	int art; 
	int col;
	
public:
	GunRenderer(Gun* gun, int art, int col);
	void draw();
	virtual ~GunRenderer();
};


class EquipmentSpawner{
public:
	static Gun* spawnBasicGun();
	static Gun* spawnBasicEnemyGun();
	static Equipment* spawnEquipment(GameAsset* asset);
};

#endif