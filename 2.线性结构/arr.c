#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include <stdbool.h>


struct Arr{
    int * pAdr;//存储数组的第一个元素的地址
    int len;//数组所能容纳的最大元素个数
    int cnt;//当前数组的有效位
};

void init_arr(struct Arr * parr,int length);
bool append_arr(struct Arr * parr,int val);
bool insert_arr(struct Arr * parr,int pos,int val);
bool delete_arr(struct Arr * parr,int pos);
int get(struct Arr * parr,int key);
bool is_emp(struct Arr * parr);
void show_arr(struct Arr * parr);

void sort_arr();
void inversion_arr();


int main(void){
    struct Arr arr;
    init_arr(&arr,10);
    //printf("%d\n",arr.len);
    show_arr(&arr);
    append_arr(&arr,0);
    append_arr(&arr,1);
    append_arr(&arr,2);
    append_arr(&arr,3);
    append_arr(&arr,4);

    show_arr(&arr);
    insert_arr(&arr,2,10);
    show_arr(&arr);
    delete_arr(&arr,1);
    show_arr(&arr);
    //int oneval=get(&arr,1);
    //printf("%d\n",oneval);

    return 0;
}


void init_arr(struct Arr * parr,int length){
    parr->pAdr = (int *)malloc(sizeof(int) * length);
    if( NULL == parr->pAdr ){
        printf("动态内存分配失败\n");
        exit(-1);
    }else{
        parr->len = length;
        parr->cnt = 0;
    }
    return ;
}

bool is_emp(struct Arr * parr){
    if( 0==parr->cnt ){
        return true;
    }else{
        return false;
    }
}
bool is_full(struct Arr * parr){
    if( parr->len==parr->cnt ){
        return true;
    }else{
        return false;
    }
}

void show_arr(struct Arr * parr){
    if(is_emp(parr)){
        printf("当前数组为空\n");
    }else{
        int i;
        for(i=0;i<parr->cnt;++i){
            printf("%d   ", parr->pAdr[i]);
        }
        printf("\n");
    }
}


bool append_arr(struct Arr * parr,int val){
	if( is_full(parr) ){
		return false;
	}else{
	    parr->pAdr[parr->cnt]=val;
	    (parr->cnt)++;
        return true;
	}
}

bool insert_arr(struct Arr * parr,int pos,int val){
    if(is_full(parr)){
        return false;
    }
    if( pos>parr->cnt || pos<0 ){
        return false;
    }
    int i;
    for(i=parr->cnt-1;i>=pos;--i){
        parr->pAdr[i+1]=parr->pAdr[i];
    }
    (parr->cnt)++;
    parr->pAdr[pos]=val;
    return true;
}
bool delete_arr(struct Arr * parr,int pos){
    if(is_full(parr)){
        return false;
    }
    if( pos>parr->cnt || pos<0 ){
        return false;
    }
    int i;
    for(i=pos;i<=parr->cnt-1;++i){
        parr->pAdr[i]=parr->pAdr[i+1];
    }
    (parr->cnt)--;
    return true;
}
int get(struct Arr * parr,int key){
    return parr->pAdr[key];
}



