

class Vehicle;
class GOPointer;

class SimpleAheadAI: public Controller{
public:
	void tick(GameObject* player);
	SimpleAheadAI(GOPointer controlledShip);
};