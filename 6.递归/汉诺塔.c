#include <stdio.h>

void hannuota(int n, char A, char B, char C){
    /*
    �����1����
        ֱ�ӽ�A�������Ӵ��ƶ���C
    ����
        �Ƚ�A�����ϵ�n-1�����ӽ���C�ƶ���B
        ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
        ���B�����ϵ�n-1�����ӽ���A�ƶ���C
    */
    if(1 == n){
        printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n",n,A,C);
    } else {
        hannuota(n-1,A,C,B);
        printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n",n,A,C);
        hannuota(n-1,B,A,C);

    }
}

int main(void){
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int n;
    printf("������Ҫ�ƶ����������� ");
    scanf("%d", &n);

    hannuota(n,ch1,ch2,ch3);

    return 0;
}
