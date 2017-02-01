#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,* PNODE;

typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK,* PSTACK;

void init(PSTACK pS);
bool empty(PSTACK pS);
void push(PSTACK pS,int val);
bool pop(PSTACK pS,int * val);
void traverse(PSTACK pS);
void clear(PSTACK pS);

int main(void) {
    STACK S;
    int val;
    init(&S);
    push(&S,1);
    push(&S,2);
    push(&S,3);
    push(&S,4);
    traverse(&S);

    if(pop(&S,&val)){
        printf("出栈成功，值为：%d\n",val);
    }else{
        printf("出栈失败");
    }

    traverse(&S);

    clear(&S);
    traverse(&S);

    return 0;
}


void init(PSTACK pS){
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if(NULL==pS->pTop){
        printf("动态内存分配失败\n");
        exit(-1);
    }else{
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }

    return ;
}

bool empty(PSTACK pS){
    if(pS->pTop == pS->pBottom){
        return true;
    }else{
        return false;
    }
}


void push(PSTACK pS,int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL==pS->pTop){
        printf("动态内存分配失败\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop= pNew;

    return ;
}

bool pop(PSTACK pS,int * val){
    if( empty(pS) ){
        return false;
    }else{
        PNODE r = pS->pTop;
        pS->pTop = r->pNext;
        *val = r->data;
        free(r);
        r = NULL;

        return true;
    }

}

void traverse(PSTACK pS){
    PNODE p = pS->pTop;
    while(p != pS->pBottom){
        printf("%d  ",p->data);
        p = p->pNext;
    }
    printf("\n");

    return ;
}


void clear(PSTACK pS){
    if(empty(pS)){
        return ;
    }else{
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while(p!=pS->pBottom){
            q = p->pNext;
            free(p);
            p = q;
        }

        pS->pTop = pS->pBottom;
    }

}
