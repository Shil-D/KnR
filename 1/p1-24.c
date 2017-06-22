#include <stdio.h>


main(){
	int c, inC, inDQ, inQ, exit, result, get;
	int p1, p2, p3;
	inC = inQ = inDQ = exit = 0;
	result = 1;
	get = 1;
	p1 = p2 = p3 = 0;
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
			else if (c == '(') p1++;
			else if (c == '{') p2++;
			else if (c == '[') p3++;
			else if (c == ')') p1--;
			else if (c == '}') p2--;
			else if (c == ']') p3--;
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
		if (p1 < 0 || p2 < 0 || p3 < 0) result = 0;
	}
	if (result == 0) printf(":(\n");
	else if (p1 == 0 && p2 == 0 && p3 == 0) printf("OK\n");
	else printf(":(");
	
	return 0;
}
