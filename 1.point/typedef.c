#include <stdio.h>
#include <stdlib.h>
//
//typedef struct Student{
//    int sid;
//    char name[20];
//}Stu;
//
//int main(void){
//    Stu st2;
//    st2.sid=200;
//    printf("%d\n",st2.sid);
//    return 0;
//}

//typedef struct Student{
//    int sid;
//    char name[20];
//}* pSt;
//
//int main(void){
//    struct Student st;
//    pSt pst = &st;
//
//    pst->sid=99;
//
//    printf("%d\n",st.sid);
//    return 0;
//}

typedef struct Student{
    int sid;
    char name[20];
}* pSt,St;

int main(void){
    St st;
    pSt pst = &st;

    pst->sid=99;

    printf("%d\n",st.sid);
    return 0;
}
