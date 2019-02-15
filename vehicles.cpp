#include <math.h>
#include <gameengine.h>
#include <gameconsole.h>
#include <vehicles.h>
#include <equipment.h>
#include <effects.h>
#include <artassetmanager.h>

Vehicle::Vehicle(float thrust, int* eqslots, int eqSlotsAmount, int expAsset){
	this -> thrust = thrust;
	this -> eqSlots = new int[eqSlotsAmount*2];
	this -> expAsset = expAsset;
	this -> eq = new GOPointer[eqSlotsAmount];
	for(int i = 0; i<eqSlotsAmount*2; i++){
		eqSlots[i] = eqslots[i];
	}
	this -> slotAmount = eqSlotsAmount;
	
}

Vehicle::~Vehicle(){
	delete[] eqSlots;
	delete[] eq;
	
}

void Vehicle::input(float x, float y, bool fire){
	this -> inputX = x;
	this -> inputY = y;
	this -> inputFire = fire;
}

void Vehicle::tick(){
	RigidBody* rb = this -> getRigidBody();
	if(rb != 0){
		if(rb->getHP()<=0){
			if(this->toBeDestroyed==-1)
			this->toBeDestroyed = 10;
		}
		rb -> addForce(thrust*inputX, thrust*inputY);
	}
	for(int i = 0; i<slotAmount; i++){
		Equipment* e = dynamic_cast<Equipment*>(eq[i].getPointer());
		if(e!=0)
			e->updatePos();
	}
	if(inputFire)
	for(int i = 0; i<slotAmount; i++){
		Equipment* e = dynamic_cast<Equipment*>(eq[i].getPointer());
		if(e!=0)
			e->fire();
	}
	if(this->toBeDestroyed==0){
		Explosion* e = dynamic_cast<Explosion*>(GameAssetManager::spawn(expAsset));
		float x; float y;
		this->getPosition(x, y);
		e->setPosition(x, y);
	}
}


void Vehicle::attachEquipment(Equipment* eq, int slot){
	this -> eq[slot] = eq->createPointer();
	eq->attachEq(eqSlots[slot*2], eqSlots[slot*2+1], this);
}

int* Vehicle::hitBox(){
	int x;
	int y;
	this->getGridPos(x, y);
	return new int[4] {x-1, y-1, x+1, y+1}; 
}

int Vehicle::getSlotAmount(){
	return slotAmount;
}

Vehicle* VehicleSpawner::spawn(GameAsset* asset){
	int health = std::stoi(asset->getData(0));
	float mass = std::stof(asset->getData(1));
	float thrust = std::stof(asset->getData(2));
	
	int art = std::stoi(asset->getData(3));
	int col = std::stoi(asset->getData(4));
	
	int hitx = std::stoi(asset->getData(5));
	int hity = std::stoi(asset->getData(6));
	
	int explAsset = std::stoi(asset->getData(7));
	
	int slotAmount = std::stoi(asset->getData(8));
	int* eqSlots = new int[slotAmount*2];
	for(int i = 0; i<slotAmount*2; i++){
		eqSlots[i] = std::stoi(asset->getData(9+i));
	}
	Vehicle* v = new Vehicle(thrust, eqSlots, slotAmount, explAsset);
	GameObject* g = v;
	RigidBody* vrb = new RigidBody(g, mass, 0.5, 0, 0, health);
	VehicleRenderer* vren =  new VehicleRenderer (v, art, col);
	v->assignComponents(vrb, vren);
	return v;
}

void VehicleRenderer::draw(){
	int xpos = 0;//(*vehicle).getGridPos()[0];
	int ypos = 0;//(*vehicle).getGridPos()[1];
	Vehicle* vehicle = dynamic_cast<Vehicle*>(g.getPointer());
	if(vehicle!=0){
		vehicle->getGridPos(xpos, ypos);
	}else return;
	ArtAssetManager::draw(art, col, xpos, ypos, 1);
}

VehicleRenderer::VehicleRenderer(Vehicle* veh, int art, int col){
	g = veh->createPointer();
	this -> art = art;
	this -> col = col;
}

VehicleRenderer::~VehicleRenderer(){

}
