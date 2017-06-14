#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

main(){
	int len;
	int i;
	char line[MAXLINE];

	while((len = getline(line, MAXLINE)) > 0) {
		if (line[len-1] != '\n' && len != 1) {
			putchar('\n');
			line[len] = '\n';
			line[len + 1] = '\0';
		}
		reverse(line);
		printf("%s", line);
	}
	return 0;

}

int getline(char s[], int lim){
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[]){
	int len, i;
	char tmp;
	for (len = 0; s[len] != '\n'; len++) ;
	for (i = len-1; i >= len / 2 ; --i){
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i -1] = tmp;
	}
}
