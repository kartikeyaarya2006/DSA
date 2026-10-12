#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int CQEnq(int[],int,int);
int CQDeq(int[],int,int);
void peek(int[],int);
void disp(int[],int,int);

int main(){
    int CQ[MAX];
    int F=-1,R=-1,ch;
    do{
        printf("\nMENU \n1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                R=CQEnq(CQ,F,R);
                if(F==-1)
                    F=0;
                break;
            case 2:
                F=CQDeq(CQ,F,R);
                break;
            case 3:
                peek(CQ,F);
                break;
            case 4:
                disp(CQ,F,R);
                break;
        }
    }while(ch>=1 && ch<=4);
}

void peek(int CQ[],int F){
    if(F==-1){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nElement at Front:%d",CQ[F]);
    }
}

void disp(int CQ[], int F, int R){
    if(F==-1 && R==-1){
        printf("\nUnderflow\n");
    }
    else{
        while(F!=R){
            printf("%d  ", CQ[F]);
            F=(F+1)%MAX;
        }
        printf("%d  ", CQ[F]);
    }
}

int CQEnq(int CQ[],int F,int R){
    int x=0;
    if((R+1)%MAX==F){
        printf("\nOverflow\n");
    }
    else{
        printf("\nEnter value:");
        scanf("%d",&x);
        R=(R+1)%MAX;
        CQ[R]=x;
    }
    return R;
}

int CQDeq(int CQ[],int F,int R){
    int x=0;
    if (F==-1 && R==-1){
        printf("\nUnderflow\n");
    }
    else{
        x=CQ[F];
        printf("Dequeued Element:%d",x);
        if(F==R){
            F=R=-1;
        }
        else{
            F=(F+1)%MAX;
        }
    }
    return F;
}