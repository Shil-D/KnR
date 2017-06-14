#include <stdio.h>
#define LO 32
#define UP 127

main(){
	int c, i,j, maxval;

	int ch[UP-LO];
	maxval = 0;
	for (i = 0; i < UP-LO; ++i){
		ch[i]=0;
	}

	while( (c=getchar()) != EOF ){
		if (c >= LO && c <= UP){
			++ch[c-LO];
			if (ch[c-LO] > maxval) maxval = ch[c-LO];
		}
	}

	for (i = maxval; i > 0; i--){
		printf("\n%4d|", i);
		for (c = LO; c < UP; c++){
			if (i <= ch[c-LO]) printf("*");
			else printf(" ");
		}
	}
	printf("\n    ");
	for (c = LO; c < UP; c++){
		printf("-");
	}
	printf("\n     ");
	
	for (c = LO; c < UP; c++){
		putchar(c);
	}
	putchar('\n');
}
