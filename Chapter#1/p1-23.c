#include <stdio.h>

/*this programm deletes comments*/
main(){
	int c, stat, instr, get, exit;
	stat = 0;
	instr = 0;
	exit = 0;
	get = 1;
	while (!exit){
		if (get) c = getchar();
		else get = 1;
		if (c == EOF) exit = 1;
		if( stat == 0){
			if (c == '/' && instr == 0){
				if ((c=getchar()) == '*')
					stat = 1;
				else{
					putchar('/');
					get = 0;
				}
			}
			else if (c == '"'){
				if (instr) instr = 0;
				else instr = 1;
				putchar(c);
			}
			else putchar(c);
		}
		else {
			if (c == '*')
				if ((c=getchar()) == '/')
					stat = 0;
				else get = 0;

		}
	}
}
