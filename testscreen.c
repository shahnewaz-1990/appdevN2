// this file will be used to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
int main(){
	Position cur = getscreensize();   // get screensize
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900302", cur.row, cur.col);
	printf("%s\n", postdata);
	sendpost(URL, postdata);	
	gotoXY(1,1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("Today we will make some animation. Press any key to continue\n  ");
	getchar();		// wait for the user to press a key		
	getchar();
	int ff,bb;
	float step = (float)cur.col/cur.row;

	for(int i=1;i<=cur.row; i++){
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;
		setcolors(ff, bg(bb));
		erasescreen();
		drawrect(10, 10, 5, 30);
	//	gotoXY(21-i,(i-1)*4+1);
		gotoXY(cur.row-i, (i-1)*step+1);
		printf("HELLO\n");
		/*
		//setcolors(RED, bg(bb));
		setcolors(RED,bg(BLACK));
		gotoxy(i,((i-1)*4+1)/2);
		erasescreen();
		drawrect(10, 10, 5,30);
        printf("%s\n",BAR);
		sleep(1);*/
		usleep(250000);

	}

/*	for (int i=1; i<25; i++){
        ff = (i+1)%8+BLACK;
        bb = (i+2)%8+BLACK;
		erasescreen();
		//setcolors(YELLOW, bg(bb));
		setcolors(GREEN,bg(BLACK));
        gotoxy(i,(i*4+81)/2);
        printf("HELLO\n");
		//setcolors(RED, bg(bb));
		setcolors(RED,bg(BLACK));
        gotoxy(25-i,(i*4+81)/2);
        printf("%s\n",BAR);
        sleep(1);

    } */

	getchar();
	resetscreen();
	erasescreen();
	printf("color is set back to default\n");
	getchar();
/*
	setfgcolor(GREEN);
	gotoxy(14,35);
	printf("Hello, World!\n");
	getchar();
	drawbar(30,30);
	drawbar(50,30);
	getchar();
	resetscreen();
	printf("This is default color\n");
*/

}
