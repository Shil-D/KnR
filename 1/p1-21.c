#include <stdio.h>
#define TAB 4

main(){
	int i,j,c;
	
	while ((c = getchar()) != EOF){
		if (c == '\n') i = 0;
		if (c == ' ') {
			i++ ;
			if (i % TAB == 0) {
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
