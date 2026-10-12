#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void SQEnq(int[],int*,int*);
void SQDeq(int[],int*,int*);
void peek(int[],int);
void disp(int[],int,int);

int main(){
    int SQ[MAX],ch;
    int F=-1,R=-1;
    do{
        printf("\nMENU \n1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                SQEnq(SQ,&F,&R);
                break;
            case 2:
                SQDeq(SQ,&F,&R);
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


void SQEnq(int SQ[],int *F1, int *R1){
    int x=0;
    if(*R1==MAX-1){
        printf("\nOVERFLOW\n");
    }
    else{
        printf("\nEnter number:");
        scanf("%d",&x);
        if(*F1==-1){
            *F1=0;
        }
        *(R1++);
        SQ[*R1]=x;
    }
}

void SQDeq(int SQ[], int *F1,int *R1){
    int x=0;
    if(*F1==-1 && *R1==-1){
        printf("\nUnderflow\n");
    }
    else{
        x=SQ[*F1];
        printf("\nDequeued Element:%d",x);
        if(*F1==*R1){
            *F1=*R1=-1;
        }
        else{
            *F1++;
        }
    }
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