#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    float coeff;
    float powx;
    float powy;
    int flag;
    struct node *next;
} NODE;
NODE *ins_last(NODE *first, float cf, float px, float py)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->coeff = cf;
    newnode->powx = px;
    newnode->powy = py;
    newnode->flag = 0;
    newnode->next = NULL;
    if (first == NULL)
        return newnode;
    temp = first;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return first;
}
NODE *read_P(NODE *first)
{
    float cf, px, py;
    printf("\nEnter the coefficient (999 to stop): ");
    scanf("%f", &cf);
    while (cf != 999)
    {
        printf("Enter power of x: ");
        scanf("%f", &px);
        printf("Enter power of y: ");
        scanf("%f", &py);
        first = ins_last(first, cf, px, py);
        printf("\nEnter the coefficient (999 to stop): ");
        scanf("%f", &cf);
    }

    return first;
}
void display(NODE *first)
{
    if (first == NULL)
    {
        printf("Empty Polynomial\n");
        return;
    }
    while (first->next != NULL)
    {
        printf("%.0fx^%.0fy^%.0f + ",
               first->coeff, first->powx, first->powy);
        first = first->next;
    }
    printf("%.0fx^%.0fy^%.0f\n",
           first->coeff, first->powx, first->powy);
}
NODE *add_p(NODE *p1, NODE *p2, NODE *p3)
{
    NODE *temp = p2;
    float cf;
    while (p1 != NULL)
    {
        p2 = temp;
        while (p2 != NULL)
        {
            if (p1->powx == p2->powx && p1->powy == p2->powy)
                break;
            p2 = p2->next;
        }
        if (p2 == NULL)
        {
            p3 = ins_last(p3, p1->coeff, p1->powx, p1->powy);
        }
        else
        {
            cf = p1->coeff + p2->coeff;
            if (cf != 0)
            {
                p3 = ins_last(p3, cf, p1->powx, p1->powy);
                p2->flag = 1;
            }
        }
        p1 = p1->next;
    }
    p2 = temp;
    while (p2 != NULL)
    {
        if (p2->flag == 0)
            p3 = ins_last(p3, p2->coeff, p2->powx, p2->powy);
        p2 = p2->next;
    }
    return p3;
}
int main()
{
    NODE *p1 = NULL, *p2 = NULL, *p3 = NULL;
    printf("\nEnter the first polynomial:\n");
    p1 = read_P(p1);
    printf("\nEnter the second polynomial:\n");
    p2 = read_P(p2);
    p3 = add_p(p1, p2, p3);
    printf("\nFirst Polynomial:\n");
    display(p1);
    printf("\nSecond Polynomial:\n");
    display(p2);
    printf("\nResultant Polynomial:\n");
    display(p3);
    return 0;
}
