#include <stdio.h>

void hannuota(int n, char A, char B, char C){
    /*
    如果是1盘子
        直接将A柱子盘子从移动到C
    否则
        先将A柱子上的n-1个盘子借助C移动到B
        直接将A柱子上的盘子从A移动到C
        最后将B柱子上的n-1个盘子借助A移动到C
    */
    if(1 == n){
        printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
    } else {
        hannuota(n-1,A,C,B);
        printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
        hannuota(n-1,B,A,C);

    }
}

int main(void){
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int n;
    printf("请输入要移动的盘子数： ");
    scanf("%d", &n);

    hannuota(n,ch1,ch2,ch3);

    return 0;
}
