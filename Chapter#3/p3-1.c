#include <stdio.h>
#include <time.h>
#define N 1000
#define VAL 900

int binsearch(int, int v[], int n);
int binsearch2(int, int v[], int n);

main(){
    int testarray[N];
    int i;
    int index;
    clock_t t;

    for (i = 0; i < N; i++)
        testarray[i] = i;

    t = clock();
    for (i = 0; i < N; i++){
        index = binsearch(VAL, testarray, N);
    }
    t = clock() - t;
    printf("Time for binsearch = %lu, index = %d\n", (unsigned long)t, index);

    t = clock();
    for (i = 0; i < N; i++){
        index = binsearch2(VAL, testarray, N);
    }
    t = clock() - t;
    printf("Time for binsearch = %lu, index = %d\n", (unsigned long)t, index);

    return 0;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid]) return mid;
    else return -1;
}