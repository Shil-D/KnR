#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define BUFSIZE 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
int readlines2(char *lineptr[], int nlines, char* buf);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

main(){ 
    char buf[BUFSIZE];
    int nlines; /* number of input lines read */
    if ((nlines = readlines2(lineptr, MAXLINES, buf)) >= 0) {
        qsort(lineptr, 0, nlines-1 );
        writelines(lineptr, nlines);
    } else{
        printf("input too big to sort\n");
        return 1;
    }
}


#define MAXLEN 1000
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
/*char *alloc(int);

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
*/
int readlines2(char *lineptr[], int maxlines, char* buf){
    int len, nlines;
    char *p = buf, line[MAXLEN];
    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p + len) > (buf + BUFSIZE))
            return (-1);
        else {
            line[len - 1] = '\0'; /* zap newline */
            printf("Line = %s\n", line);
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
        return (nlines);
}


void writelines(char *lineptr[] , int nlines){
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

    
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
    
void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}    