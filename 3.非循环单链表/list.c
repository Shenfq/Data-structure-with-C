#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,*PNODE;

//函数声明
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
    pHead = create_list(); //创建一个非循环单链表
    //traverse_list(pHead);  //遍历链表
    //printf("长度为%d",length_list(pHead));
    //sort_list(pHead);
    //traverse_list(pHead);

    traverse_list(pHead);

    //insert_list(pHead,4,55);

    if(delete_list(pHead,3,&val)){
        printf("删除成功，删除的值为：%d \n",val);
    }else{
        printf("删除失败\n");
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
        printf("内存分配失败!\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("请输入你要生成链表结点的个数：len=");
    scanf("%d", &len);

    for(i=0;i<len;i++){
        printf("请输入第%d个结点的值：",i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew){
            printf("内存分配失败!\n");
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
        printf("动态分配内存失败!\n");
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
