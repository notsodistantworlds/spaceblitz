#ifndef gameengine_h
#define gameengine_h
#include <vector>
#include <stdio.h>

class RigidBody;
class Renderer;
class Controller;

class GOPointer;

class GameObject{
protected:
	int toBeDestroyed;
	
private:
	float x;
	float y;
	RigidBody * rb;
	Renderer* ren;
	Controller* ctrl;
	
	unsigned short index;
	unsigned long objHash;
	int layer;
	
	static unsigned short nextObjIndex;
	static unsigned long nextObjHash;
	static unsigned short objectBufferSize;
	static GameObject** objects;
	static void nextHash();
	static void nextIndex();
	
public:
	virtual ~GameObject();
	void getPosition(float& x, float& y);
	void getGridPos(int& x, int& y);
	
	void setPosition(float x, float y);
	
	RigidBody* getRigidBody();
	Renderer* getRenderer();
	Controller* getController();
	bool getShouldBeDestroyed();
	
	virtual int* hitBox();
	
	virtual void collision(GameObject* with);
	
	void baseTick();
	virtual void tick();
	
	void setLayer(int l);
	int getLayer();
	
	GameObject();
	void assignComponents(RigidBody* rb, Renderer* ren);
	void assignController(Controller* ctrl);
	GOPointer createPointer();
	static GameObject* getGameObject(int index, int objHash);
	static GameObject* iterate(int& index);
	static void destroyObjects();
	static void init();
	//static void clearObjects();
};

class GOPointer{
private:
	bool init;
	unsigned short index;
	unsigned long objHash;
public:
	void setPointer(unsigned short index, unsigned long objHash);
	GameObject* getPointer();
	GOPointer();
};

class RigidBody{
	float vx;
	float vy;
	
	float maxSpeed;
	float mass;
	GOPointer g;
	
	float hp;
	float maxHP;
	
public:
	RigidBody(GameObject* obj, float mass, float mSpeed, float vx=0, float vy=0, float maxHP = 100);
	static RigidBody* getRigidbody(int& index);
	void getVelocity(float& x, float& y);
	void addForce(float x, float y);
	void setVelocity(float x, float y);
	void receiveDamage(float dmg);
	float getHP();
	void tick();
	static void clearObjects();
};

class Renderer{
protected:
	GOPointer g;
public:
	Renderer();
	static Renderer* getRenderer(int& index);
	virtual void draw();
	virtual ~Renderer();
	static void clearObjects();
};

class Controller{
protected:
	GOPointer obj;
public:
	virtual void tick(GameObject* player);
};

#endif