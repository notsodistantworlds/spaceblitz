#include <stdlib.h>
#include <math.h>
#include <gameengine.h>
#include <gameconsole.h>

GameObject** GameObject::objects;
unsigned short GameObject::nextObjIndex;
unsigned long GameObject::nextObjHash;
unsigned short GameObject::objectBufferSize;

void GameObject::getPosition(float& x, float& y){
	x = this -> x;
	y = this -> y;
}
void GameObject::getGridPos(int& x, int& y){
	x = round(this -> x);
	y = round(this -> y);
}

int* GameObject::hitBox(){
	return new int[4] {this->x+3, this->y+3, this->x-3, this->y-3}; 
}

void GameObject::collision(GameObject* with){
	
}

Renderer* GameObject::getRenderer(){
	return this -> ren;
}

RigidBody* GameObject::getRigidBody(){
	return this -> rb;
}

Controller* GameObject::getController(){
	return this -> ctrl;
}

void GameObject::assignComponents(RigidBody* rb, Renderer* ren){
	this -> rb = rb;
	this -> ren = ren;
}

void GameObject::assignController(Controller* ctrl){
	this -> ctrl = ctrl;
}

bool GameObject::getShouldBeDestroyed(){
	return toBeDestroyed==0;
}

void GameObject::nextHash(){
	GameObject::nextObjHash += rand()%3;
}

void GameObject::nextIndex(){
	bool wrap = false;
	unsigned short startingIndex = nextObjIndex;
	while(objects[nextObjIndex]!=0){
		if(nextObjIndex<objectBufferSize){
			nextObjIndex++;
		}else{
			nextObjIndex = 0;
			wrap = true;
		}
		if(wrap&&nextObjIndex>startingIndex)
			throw 10;
	}
}

GameObject::GameObject(){
	this -> layer = 0;
	this -> toBeDestroyed = -1;
	this -> ren = 0;
	this -> rb = 0;
	this -> ctrl = 0;
	GameObject::objects[nextObjIndex] = this;
	this -> index = nextObjIndex;
	this -> objHash = nextObjHash;
	nextHash();
	nextIndex();
}

GameObject::~GameObject(){
	delete rb;
	delete ren;
	delete ctrl;
}

void GameObject::baseTick(){
	if(this->toBeDestroyed>0)this->toBeDestroyed--;
}

GOPointer GameObject::createPointer(){
	GOPointer p;
	p.setPointer(this->index, this -> objHash);
	return p;
}

void GameObject::tick(){
}

void GameObject::setPosition(float x, float y){
	this->x = x;
	this->y = y;
}

void GameObject::destroyObjects(){
	unsigned short i = 0;
	while(i<objectBufferSize){
		if(objects[i]!=0&&objects[i]->getShouldBeDestroyed()){
			delete objects[i];
			objects[i] = nullptr;
		}
		i++;
	}
}

void GameObject::init(){
	objectBufferSize = 5000;
	GameObject::objects = new GameObject*[objectBufferSize];
	GameObject::nextObjIndex = 0;
	GameObject::nextObjHash = 0;
	unsigned short i = 0;
	GameObject::objects[0]=0;
	while(i<objectBufferSize-1){
		i++;
		GameObject::objects[i]=0;
	}
}

GameObject* GameObject::getGameObject(int index, int objHash){
	
	if(index<objectBufferSize){
		if(objects[index]!=0&&objects[index]->objHash == objHash)
			return objects[index];
		else return 0;
	}else{ return 0;}
}

GameObject* GameObject::iterate(int& i){
	while(i<objectBufferSize){
		if(objects[i]!=0){i++; return objects[i-1];}
		i++;
	}
	i=-10;
	return 0;
}

void GameObject::setLayer(int l){
	this->layer = l;
}

int GameObject::getLayer(){
	return this->layer;
}


Renderer::Renderer(){
	
}

Renderer::~Renderer(){
	
}

void Renderer::draw(){

}

RigidBody::RigidBody(GameObject* obj, float mass, float mSpeed, float vx, float vy, float maxHP){
	this -> g = obj->createPointer();
	this -> mass = mass;
	this -> maxSpeed = mSpeed;
	this -> vx = vx;
	this -> vy = vy;
	this -> maxHP = maxHP;
	this -> hp = maxHP;
}

void RigidBody::tick(){
	GameObject* obj = g.getPointer();
	if(obj==0)return;
	if(hp>maxHP) hp = maxHP;
	float x;
	float y;
	float speed = sqrt(vx*vx+vy*vy);
	if(speed>this->maxSpeed){
		vx = vx*(maxSpeed/speed);
		vy = vy*(maxSpeed/speed);
	}
	obj->getPosition(x, y);
	x = x+vx;
	y = y+vy;
	obj->setPosition(x, y);
}

void RigidBody::addForce(float x, float y){
	vx += x/(this->mass);
	vy += y/(this->mass);
}

void RigidBody::getVelocity(float& x, float& y){
		x=vx;
		y=vy;
}

void RigidBody::setVelocity(float x, float y){
	vx=x;
	vy=y;
}

void RigidBody::receiveDamage(float dmg){
	this -> hp -= dmg;
}

float RigidBody::getHP(){
	return this->hp/this->maxHP;
}

GOPointer::GOPointer(){
	index = 0;
	objHash = 50;
	init = false;
}

void GOPointer::setPointer(unsigned short index, unsigned long objHash){
	init = true;
	this->index = index;
	this->objHash = objHash;
}

GameObject* GOPointer::getPointer(){
	if(!init)return 0;
	return GameObject::getGameObject(this->index, this->objHash);
}

void Controller::tick(GameObject* player){
	
}