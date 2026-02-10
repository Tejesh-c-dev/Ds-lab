#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3

typedef struct
{
    char items[MAXSIZE];
    int f, r;
} QUEUE;

/* Function to check if queue is full */
int isfull(QUEUE q)
{
    if (q.r == MAXSIZE - 1)
        return 1;
    return 0;
}

/* Function to check if queue is empty */
int isempty(QUEUE q)
{
    if (q.f == -1)
        return 1;
    return 0;
}

/* Insert (Enqueue) operation */
void INSERT(QUEUE *q, char data)
{
    q->items[++q->r] = data;

    if (q->f == -1)
        q->f = 0;

    printf("\nCharacter '%c' is inserted into queue", data);
}

/* Delete (Dequeue) operation */
char DELETE(QUEUE *q)
{
    char data = q->items[q->f];

    if (q->f == q->r)
        q->f = q->r = -1;
    else
        q->f++;

    return data;
}

/* Display queue contents */
void DISPLAY(QUEUE q)
{
    int i;
    printf("\nQUEUE CONTENTS:\nFRONT->");
    for (i = q.f; i <= q.r; i++)
        printf("%c->", q.items[i]);
    printf("REAR");
}

int main()
{
    QUEUE q;
    int choice;
    char data;

    /* Initialize queue */
    q.f = q.r = -1;

    while (1)
    {
        printf("\n\n1: Insert");
        printf("\n2: Delete");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isfull(q))
                printf("\nQueue Overflow !!!");
            else
            {
                printf("\nEnter the character to be inserted: ");
                getchar();              // clear newline buffer
                scanf("%c", &data);
                INSERT(&q, data);
            }
            break;

        case 2:
            if (isempty(q))
                printf("\nQueue Underflow !!!");
            else
                printf("\nCharacter '%c' is deleted from queue", DELETE(&q));
            break;

        case 3:
            if (isempty(q))
                printf("\nQueue is Empty !!!");
            else
                DISPLAY(q);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}
