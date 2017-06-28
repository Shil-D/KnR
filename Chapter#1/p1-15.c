#include <stdio.h>

float fahrToCel(int fahr);

main()
{
    int fahr;
    
    printf("Fahrenheit to Celsius\n");
    printf("FAHR CELSIUS\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr,  fahrToCel(fahr));
}

float fahrToCel(int fahr){
	return  (5.0/9.0) * (fahr - 32);
}
