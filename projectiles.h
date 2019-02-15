#include <gameengine.h>
#include <gameassetmanager.h>

class Projectile : public GameObject{
	float damage;
public:
	Projectile(float damage);
	void tick();
	void draw();
	int* hitBox();
	void collision(GameObject* with);
	void assignRigidbody(RigidBody* rb);
};

class TailProjectileRenderer:public Renderer{
	int art;
	int col;
public:
	TailProjectileRenderer(Projectile* p, int art, int col);
	void draw();
	virtual ~TailProjectileRenderer();
};

class ProjectileSpawner{
public:
	static Projectile* spawnBasicProjectile(float dmg, int x, int y, float vx, float vy);
	static GameObject* spawnProjectile(GameAsset* asset);
};