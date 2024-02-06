#include<ncurses.h>

int main () 
{
	char a;
	initscr();
        //mvprintw(11,11,"Hello, world!");
	a = getch();	
	mvaddch(12,12,a);
	getch();
	endwin();	
	return 0;
}
