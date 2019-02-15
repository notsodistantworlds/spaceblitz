class GameConsole{
	static char* backgroundLayerBuffer;
	static char* objectsLayerBuffer;
	static char* effectsLayerBuffer;
	static char* projectilesLayerBuffer;
	static char* UILayerBuffer;
	
	
	//static ScreenEffect** effects;
public:
	static float dmg;
	
	static int init();
	static int shutdown();
	static void draw();
	static void writeChar(int x, int y, char c, char colorPair, short layer);
	static void clr();
	static char getColorPair(char fg, char bg);
	static void applyToLayer(char* layer, int l);
};