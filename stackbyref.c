#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int is_empty(int);
int is_full(int);
void push(int*,int[]);
void pop(int*,int[]);
void peek(int,int[]);
void disp(int,int[]);

int main(){
    int st[MAX];
    int Top=-1,ch;
    do{
        printf("\n1.PUSH \n2.Pop \n3.Peek \n4.Display \nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push(&Top,st);
                break;
            case 2:
                pop(&Top,st);
                break;
            case 3:
                peek(Top,st);
                break;
            case 4:
                disp(Top,st);
                break;
        }
    }while(ch>=1 && ch<=4);
}

int is_empty(int Top){
    if (Top==-1)
        return 1;
    return 0;
}

int is_full(int Top){
    if (Top==MAX-1)
        return 1;
    return 0;
}

void push(int *Tp, int st[]){
    int x=0;
    if(is_full(*Tp)){
        printf("\nFull");
    }
    else{
        printf("\nEnter number:");
        scanf("%d",&x);
        (*Tp)++;
        st[*Tp]=x;
    }
}

void pop(int *Tp, int st[]){
    int x=0;
    if(is_empty(*Tp)){
        printf("\nEmpty");
    }
    else{
        x=st[*Tp];
        printf("\nPopped Element:%d",x);
        (*Tp)--;
    }
}

void peek(int Top,int st[]){
    if(is_empty(Top)){
        printf("\nEmpty");
    }
    else{
        printf("\nElement at top:%d",st[Top]);
    }
}

void disp(int Top, int st[]){
    if(is_empty(Top)){
        printf("\nEmpty");
    }
    else{
        while(Top>=0){
            printf("%d  ", st[Top]);
            Top--;
        }
    }
}