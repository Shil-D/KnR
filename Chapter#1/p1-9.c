#include <stdio.h>

main(){
	int c, sc;

	sc = 0;
	while ((c = getchar()) != EOF){
		if ( c == ' '){
			if (sc < 1)
				putchar(c);
			++sc;
		}
		if ( c != ' ') {
			putchar(c);
			sc = 0;
		}
	}
}
