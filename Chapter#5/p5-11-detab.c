#include <stdio.h>
#include <stdlib.h>
#define TAB 7

main(int argc, char *argv[]){
	int i,c;
	int tab = TAB;

	if (argc >= 2)
		tab = atoi(argv[1]);
		
	while ((c = getchar()) != EOF){
		++i;
		if (c == '\n') i = 0;
		
		if (c == '\t') 
			while ( i % tab != 0) {
				putchar(' ');
				++i;
			}
		else	putchar(c);
	}
	return 0;
}