#include <gameengine.h>
#include <projectiles.h>
#include <vehicles.h>
#include <gameconsole.h>
#include <math.h>
#include <stdio.h>
#include <artassetmanager.h>

Projectile* ProjectileSpawner::spawnBasicProjectile(float dmg, int x, int y, float vx, float vy){
	Projectile* proj = new Projectile(dmg);
	proj->setPosition(x, y);
	RigidBody* rb = new RigidBody(proj, 10, 50, vx, vy);
	TailProjectileRenderer* trend = new TailProjectileRenderer(proj, 50, 50);
	GameObject* projGO = proj;
	projGO -> assignComponents(rb, trend);
	return proj;
}

GameObject* ProjectileSpawner::spawnProjectile(GameAsset* asset){
	switch(asset->getData(0)[0]){
		case 'p':{
			float dmg = std::stof(asset->getData(1));
			Projectile* proj = new Projectile(dmg);
			float mass = std::stof(asset->getData(2));
			RigidBody* rb = new RigidBody(proj, mass, 10);
			Renderer* rend = 0;
			switch(asset->getData(3)[0]){
				case 't':
					int art = std::stoi(asset->getData(4));
					int col = std::stoi(asset->getData(5));
					rend = new TailProjectileRenderer(proj, art, col);
					break;
			
			}
			GameObject* projGO = proj;
			projGO -> assignComponents(rb, rend);
			return projGO;
			}
	}
}

Projectile::Projectile(float damage){
	this -> damage = damage;
	this->toBeDestroyed = 100;
}

int* Projectile::hitBox(){
	int x;
	int y;
	this->getGridPos(x, y);
	return new int[4] {x, y, x, y}; 
}

void Projectile::collision(GameObject* with){
	if(this->toBeDestroyed<=3)
		return;
	if(with!=0&&with->getRigidBody()!=0)
		with->getRigidBody()->receiveDamage(damage);
	this->toBeDestroyed = 3;
}

void Projectile::tick(){
	
}

TailProjectileRenderer:: TailProjectileRenderer(Projectile* p, int art, int col){
	this -> g = p->createPointer();
	this -> art = art;
	this -> col = col;
}

void TailProjectileRenderer::draw(){
	int xpos = 0;
	int ypos = 0;
	Projectile* p = dynamic_cast<Projectile*>(g.getPointer());
	if(p!=0)
		p->getGridPos(xpos, ypos);
	char core = 'x';
	char tail = '.';
	if(ArtAssetManager::getAsset(art)!=0){
		core = ArtAssetManager::getAsset(art)->getChar(0, 0);
		tail = ArtAssetManager::getAsset(art)->getChar(1, 0);
	}
	char corec = 50;
	char tailc = 50;
	if(ArtAssetManager::getAsset(col)!=0){
		corec = ArtAssetManager::getAsset(col)->getChar(0, 0);
		tailc = ArtAssetManager::getAsset(col)->getChar(1, 0);
	}
	GameConsole::writeChar(xpos, ypos, core, corec, 3);
	RigidBody* rb = p->getRigidBody();
	if(rb!=0){
			float vx, vy;
			rb->getVelocity(vx, vy);
			if(fabs(vx/vy)>2){
				if(vx>0)xpos--; else if(vx<0) xpos++;
			}else if(fabs(vx/vy)<0.5){
				if(vy>0)ypos--; else if(vy<0) ypos++;
			}else{
				if(vx>0)xpos--; else if(vx<0) xpos++;
				if(vy>0)ypos--; else if(vy<0) ypos++;
			}
			
			if(fabs(vx)>0.2||fabs(vy)>0.2)
			GameConsole::writeChar(xpos, ypos, tail, tailc, 2);
		}
}

TailProjectileRenderer::~TailProjectileRenderer(){

}