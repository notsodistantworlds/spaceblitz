#include <stdio.h>
#include <memory>
#include <iostream>
#include <stdlib.h> 
#include <gameconsole.h>
#include <gameengine.h>
#include <curses.h>
#include <vector>
#include <vehicles.h>
#include <equipment.h>
#include <projectiles.h>
#include <artassetmanager.h>
#include <gameassetmanager.h>
#include <ai.h>
#include <math.h>
#include <debuglogger.h>
#include <effects.h>
#include <windows.h>

using namespace std;

bool overlapHitbox(int* firstObj, int* secondObj){
	
	int obj1x1 = firstObj[0];
	int obj1y1 = firstObj[1];
	int obj1x2 = firstObj[2];
	int obj1y2 = firstObj[3];
	if(obj1x1>obj1x2||obj1y1>obj1y2)return false;
	
	int obj2x1 = secondObj[0];
	int obj2y1 = secondObj[1];
	int obj2x2 = secondObj[2];
	int obj2y2 = secondObj[3];
	if(obj2x1>obj2x2||obj2y1>obj2y2)return false;
	
	if( obj1x1<=obj2x1 && obj1x2>=obj2x1 ){
		if( obj1y1<=obj2y1 && obj1y2>=obj2y1) return true;
		if( obj2y1<=obj1y1 && obj2y2>=obj1y1) return true;
	}
	if( obj2x1<=obj1x1 && obj2x2>=obj1x1 ){
		if( obj1y1<=obj2y1 && obj1y2>=obj2y1) return true;
		if( obj2y1<=obj1y1 && obj2y2>=obj1y1) return true;
	}
	
	return false;
}

bool layersCollide(int obj1l, int obj2l){
	switch(obj1l){
		case 0: return true;
		case 1: switch(obj2l){
			case 1: return false;
			}
			break;
		default: return true;
	}
	return true;
}

void drawUI(GOPointer playerShip){
	for(int x = 0; x<20; x++)
		GameConsole::writeChar(x, 39, ' ', GameConsole::getColorPair(0,7), 4);
	for(int x = 0; x<21; x++)
		if((playerShip.getPointer()->getRigidBody()->getHP())>((float)x)/20.0)
		GameConsole::writeChar(x, 38, '#', GameConsole::getColorPair(4,5), 4);
	GameConsole::dmg = 1.0-playerShip.getPointer()->getRigidBody()->getHP();
}

int main(int argc, char **argv)
{
	GameConsole::init();
	GameObject::init();
	ArtAssetManager::init();
	GameAssetManager::init();
	DebugLogger::init();
	//sleep(10);
	//return 0;
	
	ArtAssetManager::loadAssets("playershipsART.txt");
	ArtAssetManager::loadAssets("enemyshipsART.txt");
	ArtAssetManager::loadAssets("equipmentART.txt");
	ArtAssetManager::loadAssets("projectilesART.txt");
	ArtAssetManager::loadAssets("explosionsART.txt");
	ArtAssetManager::loadAssets("backgroundSceneryART.txt");
	
	GameAssetManager::loadAssets("equipment.txt");
	GameAssetManager::loadAssets("projectiles.txt");
	GameAssetManager::loadAssets("playerships.txt");
	GameAssetManager::loadAssets("enemyships.txt");
	GameAssetManager::loadAssets("explosions.txt");
	
	float minCollisionForce = 3;
	float maxCollisionForce = 15;
	
	GOPointer playerShip;
	switch(rand()%2){
		case 0:
			playerShip = GameAssetManager::spawn(1)->createPointer();
			break;
		case 1:
			playerShip = GameAssetManager::spawn(3)->createPointer();
			break;
	}
	playerShip.getPointer()->setPosition(rand()%100, 10);
	Vehicle* veh = dynamic_cast<Vehicle*>(playerShip.getPointer());
	std::vector<GameAsset*> equipm = GameAssetManager::getAssets(1,0,100,true);
	for(int i = 0; i<veh->getSlotAmount(); i++){
		if(equipm.size()>0){
			Equipment* q = dynamic_cast<Equipment*>(equipm[rand()%equipm.size()]->spawn());
			veh->attachEquipment(q, i);
		}
	}
	GOPointer enemy;
	int shutdown = -1;
	int clearup = 0;
	while(true){
		clearup++;
		GameConsole::clr();
		float inputx=0.0;
		float inputy=0.0;
		bool fire = false;/*
		switch(getch()){
			case 's':
				inputy = -1.0;
				break;
			case 'w':
				inputy = 1.0;
				break;
			case 'a':
				inputx = -1.0;
				break;
			case 'd':
				inputx = 1.0;
				break;
			case ' ':
				fire=true;
				break;
		}*/
		if(GetKeyState('A') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			inputx = -1;
		}
		if(GetKeyState('D') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			inputx = 1;
		}
		if(GetKeyState('W') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			inputy = 1;
		}
		if(GetKeyState('S') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			inputy = -1;
		}
		if(GetKeyState(' ') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			fire = true;
		}
		
		GameObject* g = playerShip.getPointer();
		Vehicle* plShip = dynamic_cast<Vehicle*>(g);
		if(g!=0&&plShip!=0){
			plShip->input(inputx, inputy, fire); 
			drawUI(playerShip);
			float x = 0;
			float y = 0;
			g->getPosition(x, y);
			if(x<5)x = 5;
			if(y<2)y = 2;
			if(x>94)x = 94;
			if(y>32)y = 32;
			g->setPosition(x, y);
		}else{
			if(shutdown<0)shutdown = 50;
			shutdown--;
		}
		
		if(enemy.getPointer()==0){
			switch(rand()%3){
				case 0:
					enemy = GameAssetManager::spawn(101)->createPointer();
					break;
				case 1:
					enemy = GameAssetManager::spawn(103)->createPointer();
					break;
				case 2:
					enemy = GameAssetManager::spawn(105)->createPointer();
					break;
			}
			enemy.getPointer()->setPosition(rand()%100, 50);
			Vehicle* veh = dynamic_cast<Vehicle*>(enemy.getPointer());
			Controller* ctrl = new SimpleAheadAI(enemy);
			enemy.getPointer()->assignController(ctrl);
			std::vector<GameAsset*> equipm = GameAssetManager::getAssets(1,0,100,false);
			for(int i = 0; i<veh->getSlotAmount(); i++){
				if(equipm.size()>0){
					Equipment* q = dynamic_cast<Equipment*>(equipm[rand()%equipm.size()]->spawn());
					veh->attachEquipment(q, i);
				}else{
					Equipment* gun = dynamic_cast<Equipment*>(GameAssetManager::spawn(1003));
					veh->attachEquipment(gun, i);
				}
			}
		}else{
			for(int x = 0; x<20; x++)
				GameConsole::writeChar(99-x, 39, ' ', GameConsole::getColorPair(0,7), 4);
			for(int x = 0; x<21; x++){
				if((enemy.getPointer()->getRigidBody()->getHP())>((float)x)/20.0)
				GameConsole::writeChar(99-x, 38, '#', GameConsole::getColorPair(6,5), 4);
			}
		}
		
		if(shutdown==0)break;
		
		if(rand()%3==1){
			BackgroundScenery* bkg = EffectsSpawner::spawnBackground(4001+rand()%5, 4000);
			bkg->setPosition(rand()%100,50);
		}
		
		if(rand()%100==1){
			BackgroundScenery* bkg = EffectsSpawner::spawnBackground(4101, 4102);
			bkg->setPosition(rand()%100,50);
		}
		
		GameObject::destroyObjects();
		
		GameObject* iteratego;
		
		int i = 0;
		while(i>=0){
			iteratego = GameObject::iterate(i);
			if(iteratego!=0&&iteratego->getRigidBody()!=0)
				iteratego->getRigidBody()->tick();
		}
		//continue;
		//int goAmount = 0;
		
		i = 0;
		while(i>=0){
			iteratego = GameObject::iterate(i);
			if(iteratego!=0){
				iteratego->baseTick();
				iteratego->tick();
				//goAmount++;
			}
		}
		
		i = 0;
		while(i>=0){
			iteratego = GameObject::iterate(i);
			if(iteratego==0)continue;
			int j = 0;
			while(j>=0){
				GameObject* iteratego2 = GameObject::iterate(j);
				if(iteratego2==0)continue;
				if(iteratego==iteratego2)continue;
				int* go1hitbox = iteratego->hitBox();
				int* go2hitbox = iteratego2->hitBox();
				if(layersCollide(iteratego->getLayer(), iteratego2->getLayer())||
				layersCollide(iteratego2->getLayer(), iteratego->getLayer()))
				if(overlapHitbox(go1hitbox, go2hitbox)){
					iteratego->collision(iteratego2);
					iteratego2->collision(iteratego);
					if(iteratego->getRigidBody()!=0 && iteratego2->getRigidBody()!=0){
						float xx; float yy;
						float xx2; float yy2;
						float hitboxSize = 3; 
						iteratego->getPosition(xx, yy);
						iteratego2->getPosition(xx2, yy2);
						xx = xx-xx2;
						yy = yy-yy2;
						float xdir = xx/sqrt(xx*xx+yy*yy);
						float ydir = yy/sqrt(xx*xx+yy*yy);
						if(sqrt(xx*xx+yy*yy)<0.02){xdir = (rand()%100-50.0)/100.0;ydir = (rand()%100-50.0)/100.0;}
						float force = sqrt(xx*xx+yy*yy)/hitboxSize;
						iteratego->getRigidBody()->addForce(xdir*(minCollisionForce+maxCollisionForce*force), ydir*xdir*(minCollisionForce+maxCollisionForce*force));
						iteratego2->getRigidBody()->addForce(-xdir*(minCollisionForce+maxCollisionForce*force), -ydir*xdir*(minCollisionForce+maxCollisionForce*force));
					}
				}
				
			}
		}
		
		i = 0;
		while(i>=0){
			iteratego = GameObject::iterate(i);
			
			if(iteratego!=0&&iteratego->getController()!=0)
				iteratego->getController()->tick(plShip);
		}
		
		i = 0;
		while(i>=0){
			iteratego = GameObject::iterate(i);
			if(iteratego!=0&&iteratego->getRenderer()!=0)
				iteratego->getRenderer()->draw();
		}
		
		if(clearup>50){
			clearup = 0;
			
		}
		
		
		
		GameConsole::draw();
		napms(50);
	}

	GameConsole::shutdown();
	return 0;
}
