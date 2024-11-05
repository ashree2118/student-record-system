#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct student // creating linked list
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct student *next;
};
struct student *head;
void insert(int rollnumber, char *name, char *phone, float percentage)
{
    struct student *student = (struct student *)
        malloc(sizeof(struct student)); // creating memory in heap
    // storing datas in nodes
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;

    if (head == NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
}
void search(int rollnumber)
{
    struct student *temp = head;
    while (temp != NULL)
    {
        if (temp->rollnumber == rollnumber)
        {
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("percentage: %0.4f\n", temp->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("student with roll number %d is not found !!!\n", rollnumber);
}
void update(int rollnumber)
{
    struct student *temp = head; // creating a temp
    // variable to traverse in the linked list
    while (temp != NULL)
    {
        // running loop for
        if (temp->rollnumber == rollnumber)
        { // checking roll no. is present or not
            printf("Record with roll number %d found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f", &temp->percentage);
            printf("updation succesful!!!\n");
            return;
        }
        temp = temp->next;
    } // below will be printed if roll no. is not found
    printf("student with roll number %d is not found !!!\n", rollnumber);
}
void Delete(int rollnumber)
{
    struct student *temp1 = head;
    struct student *temp2 = head;
    while (temp1 != NULL)
    {
        if (temp1->rollnumber == rollnumber)
        {
            printf("Record with roll number %d found !!!\n", rollnumber);
            if (temp1 == temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("Record successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("student with roll number %d is not found !!!\n", rollnumber);
}
void display()
{
    struct student *temp = head; // creating a temporary
    // pointer to traverse in a linked list
    while (temp != NULL)
    {
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("percentage: %0.4f\n\n", temp->percentage);
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details");
    do
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &rollnumber);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            printf("Enter percentage: ");
            scanf("%f", &percentage);
            insert(rollnumber, name, phone, percentage);
            break;
        case 2:
            printf("Enter roll number to search: ");
            scanf("%d", rollnumber);
            search(rollnumber);
            break;
        case 3:
            printf("Enter roll number to delete: ");
            scanf("%d", &rollnumber);
            Delete(rollnumber);
            break;
        case 4:
            printf("Enter roll number to update: ");
            scanf("%d", &rollnumber);
            update(rollnumber);
            break;
        case 5:
            display();
            break;
        }
    } while (choice != 0);
}