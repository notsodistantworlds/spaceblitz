#include <gameengine.h>
#include <ai.h>
#include <vehicles.h>
#include <math.h>

SimpleAheadAI::SimpleAheadAI(GOPointer controlledShip){
	this -> obj = controlledShip;
}

void SimpleAheadAI::tick(GameObject* player){
	Vehicle* contrShip = dynamic_cast<Vehicle*>(obj.getPointer());
	if(contrShip==0)return;
	
	int px = 0;
	int py = 0;
	int x = 0;
	int y = 0;
	float vx = 0;
	float vy = 0;
	
	float accelY = 0;
	
	contrShip->getRigidBody()->getVelocity(vx, vy);
	
	if(player==0){
		
		if(vy>0)accelY = -1; else accelY = 1;
		if(vx>0)
		contrShip -> input(-1, accelY, false); else contrShip -> input(1, accelY, false);
		return;
	}
	
	contrShip -> getGridPos(x, y);
	player -> getGridPos(px, py);
	int r = (rand()%3)-1;
	px += r;
	bool fire = rand()%3 == 1;
	
	if(vy>0)fire = false;
	
	if(y>30)accelY=-1;
	if(y<30)accelY= 1;
	if(px>x+5)contrShip -> input(1, accelY, fire); else
	if(px<x-5)contrShip-> input(-1, accelY, fire); else
	if(px>x+2)contrShip -> input(0.2, accelY, fire); else
	if(px<x-2)contrShip-> input(-0.2, accelY, fire); else
		contrShip -> input(0, accelY, fire);
}