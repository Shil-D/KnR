#include <stdio.h>

main(){

	long sc, tc, nc;
	int c, lastchar;
	
	lastchar = 0;
	sc = 0;
	tc = 0;
	nc = 0;
	while ( (c = getchar()) != EOF){
		if (c == ' ')
			++sc;
		if (c == '\t')
			++tc;
		if (c == '\n')
			++nc;
		lastchar = c;
	}
	if (lastchar == '\n') ++nc;
	printf("SpaceCounter = %ld\n", sc);
	printf("TabCounter = %ld\n", tc);
	printf("NewLineCounter = %ld\n", nc);
}
