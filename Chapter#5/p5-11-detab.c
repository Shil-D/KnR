#include <stdio.h>
#include <stdlib.h>
#define TAB 7

main(int argc, char *argv[]){
	int i,c;
	int tab[30];
	int ntab = argc;

	i=0;
	while (--ntab)
		tab[i++] = atoi(*++argv);

	i=0;
		
	while ((c = getchar()) != EOF){
		++i;
		if (c == '\n') {
			i = 0;
			ntab = 0;
		}
		
		if (c == '\t'){
			if (ntab < argc-1){
				while ( i % tab[ntab] != 0) {
					putchar(' ');
					++i;
				}
				ntab++;
			}
			else 
				while ( i % TAB != 0) {
					putchar(' ');
					++i;
				}
		}
		else
			putchar(c);

	}
	return 0;
}