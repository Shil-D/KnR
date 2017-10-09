#include <stdio.h>
#define TAB 4

main(){
	int i,c;
	int tab = TAB;
	int starttab = 0;

	i=0;
	while (--argc > 0)
		switch (c = *++argv[0]){
            case '+':
                tab = atoi(argv[1]);
                break;
            case '-':
                starttab = atoi(argv[1]);
                break;
            default:
                printf("Illegal argument\n");
                return 0;
        }
	
	while ((c = getchar()) != EOF){
		if (c == '\n') i = 0;
		if (c == ' ') {
			i++ ;
			if ((i-starttab) % tab == 0) {
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
