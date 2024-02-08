#include<ncurses.h>

int main () 
{
	int c;
	int y=11,x=11;
	int rows, cols;
 	initscr();
	keypad(stdscr, true);
	noecho();
	curs_set(0);	
        getmaxyx(stdscr, rows, cols);
	char map[rows][cols];
	do
	{
		for(int yy = 0; yy < rows; yy++)
		{
			for(int xx=0; xx < cols; xx++)
			{
				map[yy][xx] = '#';
				mvaddch(yy,xx, '#');
			}
		}
		
		for(int yy = 11; yy < rows/2; yy++)
		{
			for(int xx=11; xx < cols/2; xx++)
			{
				map[yy][xx] = ' ';
				mvaddch(yy,xx, ' ');
			}
		}


		//clear();
		//printw("rows - %d, cols - %d", rows, cols);
		if(c == KEY_UP && map[y-1][x] == ' ') y--;
		else if(c == KEY_DOWN && map[y+1][x] == ' ') y++;
		else if(c ==KEY_RIGHT && map[y][x+1] == ' ') x++;
		else if(c == KEY_LEFT && map[y][x-1] == ' ') x--;
		mvaddch(y,x,'@');
	} 
	while((c = getch()) != 27); // 27 - Esc
	endwin();	
	return 0;
}
