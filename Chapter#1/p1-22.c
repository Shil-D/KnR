#include <stdio.h>
#define COL 10
#define MAXLINE 1000

char buf[MAXLINE];
int end;

int main()
{
    int c, i, First;
    void printline(void);
    
    First = 1;
    i = 0;
    end = i;
    while ((c = getchar()) != EOF){
        if (c != '\n' && (i % COL != 0 || First) ){
            buf[i] = c;
            i++;
            if (c != ' ' && c != '\t' && c != '\n'){
                end = i;
            }

            First = 0;
        }
        else{
            if (c != ' ' && c != '\t' && c != '\n'){
                buf[i] = c;
                i++;
                end = i;
                printline();
                 while ((c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t'){
                     putchar(c);
                 }
            }
            else{
                printline();
            }
            i = 0;
            end = 0;
            putchar('\n');
            First = 1;
        }
    }
}

void printline(){
    int i;
    for (i = 0; i < end; i++)
        putchar(buf[i]);
}
