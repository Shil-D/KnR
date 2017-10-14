#include <stdio.h>
#include <stdlib.h>
#define TAB 4

main(int argc, char *argv[]){
	int i,j,c, d;
	int tab = TAB;
	int starttab = 0;

	d=0;
	while (--argc > 0)
		switch (c = **++argv){
            case '+':
                tab = atoi(*argv+1);
                break;
            case '-':
                starttab = atoi(*argv+1);
                break;
            default:
                printf("Illegal arguments\n");
                return 0;
        }
	
	while ((c = getchar()) != EOF){
		d++;
		if (c == '\n') d = 0;
		if (c == ' ' && d > starttab) {
			i++ ;
			if (i % tab == 0) {
				i = 0;
				putchar('\t');
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
