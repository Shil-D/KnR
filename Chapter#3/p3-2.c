#include <stdio.h>

int escape(char s[], char t[]);
int descape(char s[], char t[]);

main(){
    char t[] = "mama\tmila\nramy";
    char s[20];
    char f[20];

    
    printf("Text: %s\n", t);
    escape(s,t);
    printf("Escape Text: %s\n", s);
    descape(f,s);
    printf("Descape Text: %s\n", f);
    return 0;
}

int escape(char s[], char t[]){
    int i,j;
    i=j=0;

    while(t[j] != '\0'){
        switch (t[j]){
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            case '\\':
                s[i++] = '\\';
                s[i++] = '\\';
                break;
            default:
                s[i++] = t[j];
        }
        j++;
    }
    s[i] = '\0';
}

int descape(char s[], char t[]){
    int i,j;
    char next;
    i=j=0;

    while(t[j] != '\0'){
        switch (t[j]){
            case '\\':
                next = t[++j];
                switch (next){
                    case 'n':
                        s[i++] = '\n';
                        break;
                    case 't':
                        s[i++] = '\t';
                        break;
                    default:
                        s[i++] = '\\';
                        s[i++] = t[j];
                }
                break;
            default:
                s[i++] = t[j];
        }
        j++;
    }
    s[i] = '\0';
}
