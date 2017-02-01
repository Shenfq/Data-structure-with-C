#include <stdio.h>


void editarr(int *p,int len){
    p[0]=100;
    *(p+2)=20;
}

int main(void){
    int a[5]={1,2,3,4,5};
    editarr(a,5);
    printf("%d\n",a[0]);
    printf("%d\n",a[2]);
    //printf("a0 address=%p\n",a);
    //printf("a1 address=%p\n",a+1);
    //printf("a2 address=%p\n",a+2);

    return 0;
}
