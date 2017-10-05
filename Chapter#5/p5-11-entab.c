#include <stdio.h>
#define TAB 4

main(int argc, char *argv[]){
    int i,j,c;
    int tab[30];
	int ntab = argc;

	i=0;
	while (--ntab)
		tab[i++] = atoi(*++argv);

	i=0;
	
	while ((c = getchar()) != EOF){
		if (c == '\n') {
			i = 0;
			ntab = argc;
		}
		
		if (c == ' ') {
			i++ ;
			if (ntab < argc-1){
				if (i % tab[ntab] == 0) {
					i = 0;
					putchar('\t');
					ntab++;
				}
			}
			else{
				if (i % TAB == 0) {
					i = 0;
					putchar('\t');
				}
			}
		}
		else {
			for (j = 0; j < i; j++) putchar(' ');
			i = 0;
			putchar(c);
		}
	}
	return 0;
}
