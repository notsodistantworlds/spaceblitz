/*class ScreenEffect{

	
};*/

class VCRStripeEffect{
	static int xsize;
	static int ysize;
	static int* stripePositions;
	static int* stripeColorShifts;
	static int maxStripes;
public:
	static char*  apply(char* data, int layer, float damage);
	static void init(int xsize, int ysize);
	static void tick();
};
class DeadPixelsEffect{
	static bool* pixels;
	static int xsize;
	static int ysize;
	static float lastDmg;
public:
	static char*  apply(char* data, int layer, float damage);
	static void init(int xsize, int ysize);
};