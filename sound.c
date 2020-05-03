#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"

// function definitions
WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h){
	for(int i=0; i<4; i++)
		printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize); //class 11
	printf("Number of channels: %d\n", h.numChannels); 
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	// --to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %f second\n", duration);
} //class 11


/*
void wavdata(WAVheader h, FILE *fp){
	// for sample rate 16000sps,we need to read 2000 samples to calculate a 
	// "Fast" decible value. A decibel value is always calculated by (rms) formula
	short samples[SIZE];
	int peaks = 0, flag = 0;

	for(int i=0; i<BARS; i++){	// to read 5-second wave file we need 40 data
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;
		for(int k=0; k<SIZE; k++){	// sum the squares of all data
			sum = sum + samples[k]*samples[k];
		}
		// double dB = sqrt(sum/2000);
		double dB = 20*log10(sqrt(sum/SIZE));
#ifdef SDEBUG
		printf("dB[%d] = %f\n", i, dB);
#else
		if(dB > 70) {
		 setfgcolor(RED);
		if(flag == 0){
			peaks++; flag=1;
		}
	}
		else {
			setfgcolor(WHITE);
			if(flag==1) flag=0;
		}
		drawbar(i+1, (int)dB/3);
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate:%d\n", SAMPLERATE);
		gotoXY(1,75);
		setfgcolor(MAGENTA);
		printf("Duration: %.2f\n", (double)h.subchunk2Size/h.byteRate);
		gotoXY(1,150);
		setfgcolor(YELLOW);
		printf("Peaks: %d\n", peaks);
#endif

	}
}*/
//class 12
