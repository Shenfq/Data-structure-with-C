#include <stdio.h>

int main(void){
    int *p;
    int i=10;
    p=&i;
    printf("%d\n",*p);
    return 0;
}
