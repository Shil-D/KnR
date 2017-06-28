#include <stdio.h>
#include <limits.h>
#include <float.h>

main(){
    printf("Unsigned char max = %d\n", UCHAR_MAX);
    printf("Signed char min = %d, max = %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Char min = %d, max = %d\n", CHAR_MIN, CHAR_MAX);
	
    printf("Unsigned short max = %u\n", USHRT_MAX);
    printf("Short min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);

    printf("Unsigned int max = %u\n", UINT_MAX);
    printf("Int min = %d, max = %d\n", INT_MIN, INT_MAX);

    printf("Unsigned long max = %ld\n", ULONG_MAX);
    printf("Long min = %ld, max = %ld\n", LONG_MIN, LONG_MAX);

    printf("Float min = %e, max = %e\n", FLT_MIN , FLT_MAX);
    printf("Double min = %e, max = %e\n", DBL_MIN , DBL_MAX);
return 0;
}

