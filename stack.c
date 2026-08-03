#include <stdio.h>
#define MAX 10

int push(int [], int);
int pop(int [], int);
void peek(int [], int);
int is_empty(int);
int is_full(int);
void traverse(int [], int);

int main()
{
    int arr[MAX];
    int ch, Top = -1;

    do
    {
        printf("\nMenu\n1.Push\n2.Pop\n3.Peek\n4.Display\nEnter Your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                Top = push(arr, Top);
                break;

            case 2:
                Top = pop(arr, Top);
                break;

            case 3:
                peek(arr, Top);
                break;

            case 4:
                traverse(arr, Top);
                break;
        }

    } while (ch >= 1 && ch <= 4);

    return 0;
}

int is_full(int Top)
{
    if (Top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty(int Top)
{
    if (Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int arr[], int Top)
{
    int x = 0;
    int y = is_full(Top);

    if (y == 1)
    {
        printf("\nStack is Full\n");
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d", &x);

        Top++;
        arr[Top] = x;
    }

    return Top;
}

int pop(int arr[], int Top)
{
    int x = 0;
    int y = is_empty(Top);

    if (y == 1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        x = arr[Top];
        printf("\nPopped Value: %d", x);
        Top--;
    }

    return Top;
}

void peek(int arr[], int Top)
{
    if (is_empty(Top))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("Value at the top: %d", arr[Top]);
    }
}

void traverse(int arr[], int Top)
{
    if (is_empty(Top))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (int i = Top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
    }
}