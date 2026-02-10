#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    char info;
    struct node *lchild, *rchild;
} NODE;
NODE *create_tree(char postfix[])
{
    NODE *newnode, *stack[50];
    int i = 0, top = -1;
    char ch;

    while ((ch = postfix[i++]) != '\0')
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->info = ch;
        newnode->lchild = newnode->rchild = NULL;
        if (isalpha(ch) || isdigit(ch))
        {
            stack[++top] = newnode;
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid postfix expression\n");
                exit(1);
            }

            newnode->rchild = stack[top--];
            newnode->lchild = stack[top--];
            stack[++top] = newnode;
        }
    }

    return stack[top];
}
float eval(NODE *root)
{
    float num;
    if (root == NULL)
        return 0;
    switch (root->info)
    {
    case '+':
        return eval(root->lchild) + eval(root->rchild);
    case '-':
        return eval(root->lchild) - eval(root->rchild);
    case '*':
        return eval(root->lchild) * eval(root->rchild);
    case '/':
        return eval(root->lchild) / eval(root->rchild);
    case '^':
        return pow(eval(root->lchild), eval(root->rchild));
    default:
        if (isalpha(root->info))
        {
            printf("\nEnter value of %c : ", root->info);
            scanf("%f", &num);
            return num;
        }
        else
        {
            return (root->info - '0');
        }
    }
}

int main()
{
    char postfix[30];
    float result;
    NODE *root = NULL;
    printf("\nEnter a valid postfix expression: ");
    scanf("%s", postfix);
    root = create_tree(postfix);
    result = eval(root);
    printf("\nResult = %.2f\n", result);
    return 0;
}
