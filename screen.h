// usually in a header file, following information are included
// 1. function declarations
// 2. constant definitions
// 3. conditional compilation (will be discussed later)

// constant definitions

#define ESC 0X1B 

//#define BLACK 30, instead of using #define, it's better to use enumeration

enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c)  (c+10)		// macro definition

#define UNICODE			// for conditional compillation
#define BAR "\u2590"

//#define DEBUG     // for conditional compilation

typedef struct{  // this struct will define a compound data, which consists of
	int row;    // the number of rows and columns of our screen
	int col;
}Position;



// function declarations

void erasescreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetscreen(void);
void gotoXY(int ,int);
void drawbar(int ,int);
void drawrect(int, int, int, int);
Position getscreensize(void);

