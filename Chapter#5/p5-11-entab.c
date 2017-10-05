#include <stdio.h>
#define TAB 4

main(){
    int i,j,c;
    int tab = TAB;
    
    if (argc >= 2)
        tab = atoi(argv[1]);
	
	while ((c = getchar()) != EOF){
		if (c == '\n') i = 0;
		if (c == ' ') {
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
