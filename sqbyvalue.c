#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int SQEnq(int[],int);
int SQDeq(int[],int,int);
void peek(int[],int);
void disp(int[],int,int);

int main(){
    int SQ[MAX];
    int F=-1,R=-1,ch;
    do{
        printf("\nMENU \n1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                R=SQEnq(SQ,R);
                if(F==-1)
                    F=0;
                break;
            case 2:
                F=SQDeq(SQ,F,R);
                break;
            case 3:
                peek(SQ,F);
                break;
            case 4:
                disp(SQ,F,R);
                break;
        }
    }while(ch>=1 && ch<=4);
}


int SQEnq(int SQ[], int R){
    int x=0;
    if(R==MAX-1){
        printf("\nOVERFLOW\n");
    }
    else{
        printf("\nEnter number:");
        scanf("%d",&x);
        R++;
        SQ[R]=x;
    }
    return R;
}

int SQDeq(int SQ[], int F,int R){
    int x=0;
    if(F==-1 && R==-1){
        printf("\nUnderflow\n");
    }
    else{
        x=SQ[F];
        printf("\nDequeued Element:%d",x);
        if(F==R){
            F=-1;
        }
        else{
            F++;
        }
    }
    return F;
}

void peek(int SQ[],int F){
    if(F==-1){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nElement at Front:%d",SQ[F]);
    }
}

void disp(int SQ[], int F, int R){
    if(F==-1 && R==-1){
        printf("\nUnderflow\n");
    }
    else{
        while(F<=R){
            printf("%d  ", SQ[F]);
            F++;
        }
    }
}