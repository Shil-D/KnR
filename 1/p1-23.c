#include <stdio.h>

/*this programm comment comments*/
main(){
	int c, stat, instr;
	stat = 0;
	instr = 0;
	while ((c=getchar()) != EOF){
		if( stat == 0){
			if (c == '/' && instr == 0){
				if ((c=getchar()) == '*')
					stat = 1;
				else{
					putchar('/');
					putchar(c);
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

		}
	}
}
