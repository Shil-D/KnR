#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main(){
	int len;
	int i;
	char line[MAXLINE];
	char temp[MAXLINE];

	while((len = getline(line, MAXLINE)) > 0) {
		for (i = len-2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i )
			;
		if (i != -1) {
			line[i+1] = '\n';
			line[i+2] = '\0';
			printf("%s", line);
		}
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
