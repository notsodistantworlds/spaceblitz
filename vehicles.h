#ifndef vehicles_h
#define vehicles_h

#include <gameengine.h>
#include <gameassetmanager.h>

class Equipment;

class Vehicle : public GameObject{
	float inputY;
	float inputX;
	bool inputFire;
	
	float thrust;
	
	int expAsset;
	
	int slotAmount;
	int* eqSlots;
	GOPointer* eq;
public:
	Vehicle(float thrust, int* eqSlots, int eqSlotsAmount, int expAsset);
	void tick();
	int* hitBox();
	void input(float x, float y, bool fire);
	void attachEquipment(Equipment* eq, int slot);
	int getSlotAmount();
	virtual ~Vehicle();
};

class VehicleRenderer:public Renderer{
	int art;
	int col;
public:
	VehicleRenderer(Vehicle* veh, int art, int col);
	void draw();
	virtual ~VehicleRenderer();
};

class VehicleSpawner{
public:
	static Vehicle* spawn(GameAsset*  asset);
};

#endif