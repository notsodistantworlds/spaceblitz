#include <screeneffects.h>
#include <math.h>
#include <stdlib.h>

int VCRStripeEffect::xsize;
int VCRStripeEffect::ysize;

int VCRStripeEffect::maxStripes;

int* VCRStripeEffect::stripePositions;
int* VCRStripeEffect::stripeColorShifts;

void VCRStripeEffect::tick(){
	for(int i = 0; i<VCRStripeEffect::maxStripes; i++)
		stripePositions[i]++;
}

char* VCRStripeEffect::apply(char* data, int layer, float damage){
	
	//int str = 0;
	if(layer<5)return data;
	if(damage>0.05)
	for(int i = 0; i<VCRStripeEffect::maxStripes; i++){
		int y = stripePositions[i];
		if(y>=VCRStripeEffect::ysize){
			if(rand()%100<damage*damage*0.01*100)
				stripePositions[i] = 0;
				stripeColorShifts[i] = rand()%8;
			continue;
		}
		if(stripeColorShifts[i]>7) stripeColorShifts[i] = stripeColorShifts[i]%8;
		for(int x = VCRStripeEffect::xsize-1; x>0; x--){
			data[(x+y*100)*2] = data[((x-1)+y*100)*2];
			//if(data[(x+y*100)*2] == 0) data[(x+y*100)*2] = ' ';
			char col = data[(x+y*100)*2+1]%8;
			char bkg = data[(x+y*100)*2+1]-col;
			char sh = stripeColorShifts[i];
			data[(x+y*100)*2+1] = (col+sh)%8+((bkg+sh)%8*8);//data[((x-1)+y*100)*2+1];
		}
		//str++;
	}
	//if(rand()%100>50)data[0] = 'Y';
	return data;
}

void VCRStripeEffect::init(int xsize, int ysize){
	VCRStripeEffect::maxStripes = 5;
	stripePositions = new int[maxStripes/*ysize*/];
	stripeColorShifts = new int[maxStripes/*ysize*/];
	VCRStripeEffect::xsize = xsize;
	VCRStripeEffect::ysize = ysize;
}


int DeadPixelsEffect::xsize;
int DeadPixelsEffect::ysize;

bool* DeadPixelsEffect::pixels;
float DeadPixelsEffect::lastDmg;

char* DeadPixelsEffect::apply(char* data, int layer, float damage){
	if(damage<0.05) return data;
	if(layer<5)return data;
	
	int dpixels = 0;
	for(int y = 0; y<ysize; y++){
		for(int x = 0; x<xsize; x++){
			if(!pixels[(x+y*xsize)])continue;
			data[(x+y*100)*2] = ' ';
			data[(x+y*100)*2+1] = rand()%64;//data[((x-1)+y*100)*2+1];
			dpixels++;
		}
	}
	
	float ratio = ((float)dpixels)/((float)(xsize*ysize));
	//if(lastDmg>damage){
	//if(damage>1)damage = 1;
	if(ratio*500<((damage>1.0)?1.0:damage)){
		
		for(int j = 0; j<500; j++){
			int x = rand()%xsize;
			int y = rand()%ysize;
			if(rand()%100<damage*100)
				pixels[(x+y*xsize)] = true;
			else break;
		}
		
	}
	
	//lastDmg = damage;

	
	return data;
}

void DeadPixelsEffect::init(int xsize, int ysize){
	DeadPixelsEffect::xsize = xsize;
	DeadPixelsEffect::ysize = ysize;
	
	lastDmg = 0;
	
	DeadPixelsEffect::pixels = new bool[xsize*ysize];
}