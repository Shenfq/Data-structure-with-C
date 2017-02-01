#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,*PNODE;

//��������
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int * val);
void sort_list(PNODE pHead);

int main(void){
    int val;
    PNODE pHead = NULL;
    pHead = create_list(); //����һ����ѭ��������
    //traverse_list(pHead);  //��������
    //printf("����Ϊ%d",length_list(pHead));
    //sort_list(pHead);
    //traverse_list(pHead);

    traverse_list(pHead);

    //insert_list(pHead,4,55);

    if(delete_list(pHead,3,&val)){
        printf("ɾ���ɹ���ɾ����ֵΪ��%d \n",val);
    }else{
        printf("ɾ��ʧ��\n");
    }

    traverse_list(pHead);
    return 0;
}


PNODE create_list(void){
    int len;
    int val;
    int i;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead){
        printf("�ڴ����ʧ��!\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("��������Ҫ����������ĸ�����len=");
    scanf("%d", &len);

    for(i=0;i<len;i++){
        printf("�������%d������ֵ��",i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew){
            printf("�ڴ����ʧ��!\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }

    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE pNew = pHead->pNext;
    while(NULL != pNew){
        printf("%d   ",pNew->data);
        pNew = pNew->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead){
    if(pHead->pNext == NULL){
        return true;
    }else{
        return false;
    }
}

int length_list(PNODE pHead){
    int len = 0;
    PNODE pNew = pHead->pNext;
    while(NULL != pNew){
        pNew = pNew->pNext;
        len++;
    }
    return len;
}

void sort_list(PNODE pHead){
    int i,j,t;
    PNODE p,q;
    int len = length_list(pHead);
    for(i=0,p=pHead->pNext;i<len-1;p=p->pNext,i++){
        for(j=i+1,q=p->pNext;j<len;q=q->pNext,j++){
            if(p->data > q->data){
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return;
}

bool insert_list(PNODE pHead, int pos, int val){
    int i=0;
    PNODE p = pHead;
    while(NULL!=p && i<pos-1) {
        p = p->pNext;
        ++i;
    }
    if(NULL==p || i>pos-1) {
        return false;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL==pNew) {
        printf("��̬�����ڴ�ʧ��!\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}


bool delete_list(PNODE pHead, int pos, int * val){
    int i=0;
    PNODE p = pHead;
    while(NULL!=p->pNext && i<pos-1) {
        p = p->pNext;
        ++i;
    }
    if(NULL==p->pNext || i>pos-1) {
        return false;
    }
    PNODE q = p->pNext;
    *val = q->data;

    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;
}
