#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[20];
    char usn[20];
    char branch[20];
    int year;
    struct node *lptr;
    struct node *rptr;
} NODE;


NODE *ins_first(NODE *first)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));

    printf("\nEnter the details of the student...\n");
    printf("Name: ");
    scanf("%19s", newnode->name);

    printf("USN: ");
    scanf("%19s", newnode->usn);

    printf("Branch: ");
    scanf("%19s", newnode->branch);

    printf("Year of admission: ");
    scanf("%d", &newnode->year);

    newnode->lptr = NULL;
    newnode->rptr = first;

    if (first != NULL)
        first->lptr = newnode;

    first = newnode;

    printf("\nStudent added successfully\n");
    return first;
}


void display1(NODE *first)
{
    NODE *temp;
    char branch[20];
    int flag = 0;

    if (first == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }

    printf("\nEnter the branch: ");
    scanf("%19s", branch);

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->branch, branch) == 0)
        {
            if (flag == 0)
            {
                printf("\nStudents from branch %s\n", branch);
                printf("Name\tUSN\tYear\n");
                flag = 1;
            }
            printf("%s\t%s\t%d\n",
                   temp->name, temp->usn, temp->year);
        }
        temp = temp->rptr;
    }

    if (flag == 0)
        printf("\nNo students found from branch %s\n", branch);
}


void display2(NODE *first)
{
    NODE *temp;
    int count = 0;

    if (first == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }

    printf("\nName\tUSN\tBranch\tYear\n");

    temp = first;
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%d\n",
               temp->name, temp->usn,
               temp->branch, temp->year);
        count++;
        temp = temp->rptr;
    }

    printf("\nTotal number of students = %d\n", count);
}


NODE *delete_student(NODE *first)
{
    NODE *temp;
    char usn[20];

    if (first == NULL)
    {
        printf("\nEmpty list, nothing to delete\n");
        return first;
    }

    printf("\nEnter the USN of the student to delete: ");
    scanf("%19s", usn);

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->usn, usn) == 0)
        {
            if (temp->lptr == NULL && temp->rptr == NULL)
            {
                first = NULL;
            }
            else if (temp->lptr == NULL)
            {
                first = temp->rptr;
                first->lptr = NULL;
            }
            else if (temp->rptr == NULL)
            {
                temp->lptr->rptr = NULL;
            }
            else
            {
                temp->lptr->rptr = temp->rptr;
                temp->rptr->lptr = temp->lptr;
            }

            printf("\nStudent %s (%s) deleted successfully\n",
                   temp->name, temp->usn);
            free(temp);
            return first;
        }
        temp = temp->rptr;
    }

    printf("\nStudent with USN %s not found\n", usn);
    return first;
}


int main()
{
    NODE *first = NULL;
    int choice;

    while (1)
    {
        printf("\n-----------------------------");
        printf("\n1. Add student");
        printf("\n2. Display based on branch");
        printf("\n3. Display all students");
        printf("\n4. Delete student");
        printf("\n5. Exit");
        printf("\n-----------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            first = ins_first(first);
            break;

        case 2:
            display1(first);
            break;

        case 3:
            display2(first);
            break;

        case 4:
            first = delete_student(first);
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}