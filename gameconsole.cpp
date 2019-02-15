#include <curses.h>
#include <gameconsole.h>
#include <screeneffects.h>

char* GameConsole::backgroundLayerBuffer;
char* GameConsole::objectsLayerBuffer;
char* GameConsole::effectsLayerBuffer;
char* GameConsole::projectilesLayerBuffer;
char* GameConsole::UILayerBuffer;

float GameConsole::dmg;
//ScreenEffect** effects;

int GameConsole::init()
{

    initscr();
	start_color();
	nl();
    noecho();
	curs_set(0);
    timeout(0);
	resize_term(40, 100);
	
	//VCRStripeEffect::setSize(100, 40);
	VCRStripeEffect::init(100, 40);
	//DeadPixelsEffect::setSize(100, 40);
	DeadPixelsEffect::init(100, 40);
	
	backgroundLayerBuffer = new char[100*40*3];
	objectsLayerBuffer = new char[100*40*3];
	effectsLayerBuffer = new char[100*40*3];
	projectilesLayerBuffer = new char[100*40*3];
	UILayerBuffer = new char[100*40*3];
	
	for(int i=0; i<8; i++){
		init_pair(i*8, COLOR_BLACK, i);
		init_pair(1+i*8, COLOR_BLUE,  i);
		init_pair(2+i*8, COLOR_GREEN,  i);
		init_pair(3+i*8, COLOR_CYAN,  i);
		init_pair(4+i*8, COLOR_RED,i);
		init_pair(5+i*8, COLOR_MAGENTA,  i);
		init_pair(6+i*8, COLOR_YELLOW, i);
		init_pair(7+i*8, COLOR_WHITE,  i);
	}
	wclear(stdscr);

}

char GameConsole::getColorPair(char fg, char bg)
{

	return bg*8+fg;

}

int GameConsole::shutdown()
{

	endwin();

}

void GameConsole::clr(){
	erase();
}

void GameConsole::writeChar(int x, int y, char c, char colorPair, short layer=1)
{
	if(x<0||x>100-1||y<0||y>40-1)return;
	switch(layer){
		case 0:
			backgroundLayerBuffer[(x+y*100)*2] = c;
			backgroundLayerBuffer[(x+y*100)*2+1] = colorPair;
			break;
		case 1:
			objectsLayerBuffer[(x+y*100)*2] = c;
			objectsLayerBuffer[(x+y*100)*2+1] = colorPair;
			break;
		case 2:
			effectsLayerBuffer[(x+y*100)*2] = c;
			effectsLayerBuffer[(x+y*100)*2+1] = colorPair;
			break;
		case 3:
			projectilesLayerBuffer[(x+y*100)*2] = c;
			projectilesLayerBuffer[(x+y*100)*2+1] = colorPair;
			break;
		case 4:
			UILayerBuffer[(x+y*100)*2] = c;
			UILayerBuffer[(x+y*100)*2+1] = colorPair;
			break;
		
	}
}

void GameConsole::applyToLayer(char* layer, int l){
	VCRStripeEffect::apply(layer,l,dmg);
	DeadPixelsEffect::apply(layer,l,dmg);
}

void GameConsole::draw()
{
	VCRStripeEffect::tick();
	
	char* layer = backgroundLayerBuffer;
	GameConsole::applyToLayer(layer,0);
	
	layer = objectsLayerBuffer;
	GameConsole::applyToLayer(layer,1);
	
	layer = effectsLayerBuffer;
	GameConsole::applyToLayer(layer,2);
	
	layer = projectilesLayerBuffer;
	GameConsole::applyToLayer(layer,3);
	
	layer = UILayerBuffer;
	GameConsole::applyToLayer(layer,4);
	
	char* rendered = new char[100*40*3];
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			rendered[(x+y*100)*2] = 0;
			rendered[(x+y*100)*2+1] = 0;
		}
	}
	
	layer = backgroundLayerBuffer;
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			rendered[(x+y*100)*2] = layer[(x+y*100)*2];
			rendered[(x+y*100)*2+1] = layer[(x+y*100)*2+1];
			layer[(x+y*100)*2]=0;
		}
	}
	
	layer = objectsLayerBuffer;
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			rendered[(x+y*100)*2] = layer[(x+y*100)*2];
			rendered[(x+y*100)*2+1] = layer[(x+y*100)*2+1];
			layer[(x+y*100)*2]=0;
		}
	}
	
	layer = effectsLayerBuffer;
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			rendered[(x+y*100)*2] = layer[(x+y*100)*2];
			rendered[(x+y*100)*2+1] = layer[(x+y*100)*2+1];
			layer[(x+y*100)*2]=0;
		}
	}
	
	layer = projectilesLayerBuffer;
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			rendered[(x+y*100)*2] = layer[(x+y*100)*2];
			rendered[(x+y*100)*2+1] = layer[(x+y*100)*2+1];
			layer[(x+y*100)*2]=0;
		}
	}
	
	layer = UILayerBuffer;
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			rendered[(x+y*100)*2] = layer[(x+y*100)*2];
			rendered[(x+y*100)*2+1] = layer[(x+y*100)*2+1];
			layer[(x+y*100)*2]=0;
		}
	}
	
	
	
	layer = rendered;
	GameConsole::applyToLayer(layer,5);
	for(int x = 0; x<100; x++){
		for(int y = 0; y<40; y++){
			char c = layer[(x+y*100)*2];
			char col = layer[(x+y*100)*2+1];
			if(c==0)continue;
			move((LINES-1)-y, x);
			attrset(COLOR_PAIR(col));
			addch(c);
			layer[(x+y*100)*2]=0;
		}
	}
	
	if(is_termresized())
		resize_term(40, 100);
	refresh();
}
