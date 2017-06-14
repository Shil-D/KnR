#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 20

main(){
  int c, state, n, i,j, maxlen;
  int len[MAX];

  n = i = maxlen = 0;
  for ( i = 0; i < MAX; i++)
    len[i] = 0;

  while ((c = getchar()) != EOF){
    if ( c == ' ' || c == '\n' || c == '\t'){
      if (state = IN){
        state = OUT;
        ++len[n];
        if (maxlen < len[n] && n !=0) maxlen =len[n];
        n = 0;
      }
    }
    else {
       ++n;
       state = IN;
    }
  }
  ++len[n];
  if (maxlen < len[n]) maxlen =len[n];

  putchar('\n');

  for (j = maxlen; j> 0; --j){
    printf("\n%4d|", j);
    for ( i = 1; i < MAX; ++i){
      if (len[i] >= j) printf(" *");
      else printf("  ");
    }
  }
  printf("\n    ");
  for ( i = 1; i < MAX; ++i){
    printf("--");
  }
  printf("\n      ");
  for ( i = 1; i < MAX; ++i){
  printf("%d ",i);
  }
  putchar('\n');
}
