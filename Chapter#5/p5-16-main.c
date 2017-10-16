#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define ALLOCSIZE 10000
#define MAXLEN 1000

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (* comp)(void *, void *), int reverse);
char *alloc(int);
int numcmp(char *, char*);
int cmp(char*, char*);

main(int argc, char *argv[]){ 
    int nlines; /* number of input lines read */
    int numeric = 0;
    int reverse = 0;
    static int fold = 0;
    static int dir = 0;

    while (--argc > 0){
        if (!strcmp(*++argv, "-n"))
            numeric = 1;
        else if (!strcmp(*argv, "-r"))
            reverse = 1;
        else if (!strcmp(*argv, "-f"))
            fold = 1;
        else if (!strcmp(*argv, "-d"))
            dir = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (numeric)
            qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numcmp),reverse);
        else 
            qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(cmp),reverse);
        writelines(lineptr, nlines);
        return 0;
    } else{
        printf("input too big to sort\n");
        return 1;
    }
}

int cmp(char *s1, char *s2){
    char a,b;
    
    do {
        if (dir){
            for(; *s1 != ' ' && !isalnum(*s1) && *s1 != '\0'; s1++)
            for(; *s2 != ' ' && !isalnum(*s2) && *s1 != '\0'; s2++)
        }
        a = fold ? tolower(*s1) : *s1;
        b = fold ? tolower(*s2) : *s2;
        s1++;
        s2++;
    } while (a == b);

    return a - b;
}

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

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc (len)) == NULL)
            return (-1);
        else {
            line[len - 1] = '\0'; 
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
        return (nlines);
}

void writelines(char *lineptr[] , int nlines){
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

    
void qsort(void *v[], int left, int right, int (* comp)(void *, void *), int reverse) {
    int i, last;
    void swap(void *v[], int i, int j);
    
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    if ( (!reverse && (*comp)(v[i], v[left]) < 0) ||
         ( reverse && (*comp)(v[i], v[left]) > 0))
        swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp, reverse);
    qsort(v, last+1, right, comp, reverse);
}
    
void swap(void *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}       

char *alloc(int n){
    if( allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    else return 0;
}
void afree(char *p){
    if (p >=  allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}