#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define ALLOCSIZE 10000
#define DEFLINES 10
#define MAXLINES 100

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static char *allocend = allocbuf + ALLOCSIZE;

int getline(char* s, int lim){
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		*s++ = c;
	if (c == '\n'){
        *s++ = c;
        i++;
    }
	*s = '\0';
	return i;
}

main(int argc, char *argv[]){
    int n = DEFLINES;
    int len;
    int nlines = 0;
    int last = 0;
    char line[MAXLEN];
    char *lineptr[MAXLINES];
    int c, i;


    if (argc > 1){
        if ((c = **++argv) == '-'){
            switch ((*argv)[1]){
                case 'n':
                    n = atoi(*++argv);
                    break;
                default:
                    printf("Illegal argument");
                    return 0;
            }
        }
    }

    while ((len = getline(line, MAXLEN)) > 0){
        if (allocp + len + 1> allocend){
            allocp = allocbuf;
        }
        lineptr[last++] = allocp;
        strcpy(allocp, line);
        allocp += len + 1;
        nlines++;
    }

    n = (nlines > n) ? n : nlines;
    putchar('\n');
    for (i = last - n; n-- > 0; i++){
        printf("%s", lineptr[i]);
    }
}