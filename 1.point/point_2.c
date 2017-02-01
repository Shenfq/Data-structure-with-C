#include <stdio.h>

void f(int *p){
    *p=100;
}

int main(void){
    int i=9;
    f(&i);
    printf("i=%d\n",i);
    return 0;
}
