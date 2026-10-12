#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}sl;

sl* INSERT_Right(sl*);
sl* INSERT_Left(sl*);
//sl* INSERT_After(sl*);
sl* reverselist(sl*);
void disp(sl*);

int main(){
    sl *L=NULL, *R=NULL;
    int ch;
    do{
        printf("\nMENU \n1.Insert_Right \n2.Insert_Left \n3.Insert After node \n4.Reverse \n5.Display \nEnter Your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                R=INSERT_Right(R);
                if(L==NULL)
                    L=R;
                break;
            case 2:
                L=INSERT_Left(L);
                if(R==NULL){
                    R=L;
                }
                break;
            /*case 3:
                R=Insert_After(R);
                break;*/
            case 3:
                L=reverselist(L);
                break;
            case 4:
                disp(L);
                break;
        }
    }while(ch>=1 && ch<=4);
}

sl* INSERT_Right(sl* R){
    sl *P=NULL;
    int x;
    P=(sl*)malloc(sizeof(sl));
    if(P!=NULL){
        printf("\nEnter Data:");
        scanf("%d",&x);
        P->data=x;
        P->next=NULL;
        if(R==NULL){
            R=P;
        }
        else{
            R->next=P;
            R=R->next;
        }
    }
    return R;
}
sl* INSERT_Left(sl* L){
    sl *P=NULL, *head=L;
    int x;
    P=(sl*)malloc(sizeof(sl));
    if(P!=NULL){
        printf("\nEnter Data:");
        scanf("%d",&x);
        P->data=x;
        P->next=NULL;
        if(head==NULL){
            head=P;
            L=head;
        }
        else{
            P->next=head;
            L=P;
        }
    }
    return L;
}

/*sl* INSERT_After(sl *R)
{
    sl *P;
    int key, x;

    printf("Enter given node data: ");
    scanf("%d", &key);

    // Search for the given node
    while (R != NULL && R->data != key)
        R = R->next;

    if (R == NULL) {
        printf("Node not found\n");
        return NULL;
    }

    P = (sl*)malloc(sizeof(sl));

    if (P == NULL)
        return NULL;

    printf("Enter new data: ");
    scanf("%d", &x);

    P->data = x;
    P->next = R->next;
    R->next = P;
    while(R->next!=NULL){
        R=R->next;
    }

    return R;
}*/

void disp(sl*L){
    sl *temp=NULL;
    temp=L;
    if(temp==NULL){
        printf("\nEmpty list\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
}

sl* reverselist(sl *L)
{
    sl *P = NULL, *R = NULL;

    while (L != NULL)
    {
        P = L->next;  // Save next node
        L->next = R;  // Reverse the link
        R = L;        // Move R forward
        L = P;        // Move L forward
    }

    return R;         // Return new head
}