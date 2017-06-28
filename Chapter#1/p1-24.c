#include <stdio.h>
#define MAXLEN 1000

int index;
int arr[MAXLEN];
int check(char d);

main(){
	int c, inC, inDQ, inQ, exit, result, get;
	index = 0;
	inC = inQ = inDQ = exit = 0;
	result = 1;
	get = 1;
	
	while (!exit){
		if (get) c = getchar();
		else get = 1;
		if (c == EOF) exit = 1;
		else if( !inDQ && !inC && !inQ){
			if (c == '/' ){
				putchar('/');
				if ((c=getchar()) == '*')
					inC = 1;
				else{
					get = 0;
				}
			}
			else if (c == '"'){
				inDQ = 1;
			}
			else if (c == '\''){
				inQ = 1;
			}
			if (result == 1){
				if (c == '(' || c == '{'|| c == '[') {  arr[index] = c; index++;}
				else if (c == ')') result = check('(');
				else if (c == '}') result = check('{');
				else if (c == ']') result = check('[');
			}
		}
		else if (inC){
			if (c == '*'){
				putchar('*');
				if ((c=getchar()) == '/')
					inC = 0;
				else {
					get = 0;
				}
			}

		}

		else if (inQ){
			if (c == '\'') inQ = 0;
		}
		else if (inDQ){
			if (c == '"') inDQ = 0;
		}
		if (c != EOF) putchar(c);
	}
	if (result == 0 || index != 0) printf(":(\n");
	else printf("OK\n");
	
	return 0;
}


int check(char d){
	if (index == 0) return 0;
	else if (arr[index-1] == d){
		index--;
		return 1;
	}
	else return 0;
}
