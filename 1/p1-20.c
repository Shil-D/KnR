#include <stdio.h>
#define TAB 7

main(){
	int i,c;
	
	while ((c = getchar()) != EOF){
		++i;
		if (c == '\n') i = 0;
		
		if (c == '\t') 
			while ( i % TAB != 0) {
				putchar(' ');
				++i;
			}
		else	putchar(c);
	}
	return 0;
}
