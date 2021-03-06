#include <stdio.h>
#include <stdlib.h>
#define TAB 7

main(int argc, char *argv[]){
	int i,c;
	int tab = TAB;
	int starttab = 0;

    i=0;
	while (--argc > 0){
        c = **++argv;
		switch (c){
            case '+':
                tab = atoi(*argv + 1);
                break;
            case '-':
                starttab = atoi(*argv+1);
                break;
            default:
                printf("Illegal argument\n");
                return 0;
        }}
		
	while ((c = getchar()) != EOF){
		++i;
		if (c == '\n') {
			i = 0;
		}
		
		if (c == '\t' && i > starttab)
            while ( i % tab != 0) {
                putchar(' ');
                ++i;
            }
        else	putchar(c);

	}
	return 0;
}