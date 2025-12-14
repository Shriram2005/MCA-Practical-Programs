/*
Question 4:
Write a menu driven program which will maintain a list of car models, their price, name of the manufacture, engine capacity etc. as a doubly linked list. The menu should make provisions for inserting information pertaining to new car models, delete obsolete models, update data such as price besides answering queries such as listing all car models within a price range specified by the client and listing all details given a car model
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

struct node{
    char model[max];
    float price;
    char manuf[max];
    int cc;
    struct node *prev;
    struct node *next;
} *head = NULL;

void create();
void add();
void cdelete();
void update();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("\n------ CAR LIST AND INFO ------\n");
        printf("1. Create new list of cars\n");
        printf("2. Add new car\n");
        printf("3. Delete a car\n");
        printf("4. Update record\n");
        printf("5. Display all info\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d",&choice) != 1)
        {
            while(getchar()!='\n');
            continue;
        }

        switch(choice)
        {
            case 1: create(); break;
            case 2: add(); break;
            case 3: cdelete(); break;
            case 4: update(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Wrong choice!\n");
        }
    }
}

void create()
{
    struct node *newnode, *temp = NULL;
    int n, i;

    printf("Enter number of cars: ");
    if(scanf("%d",&n) != 1 || n <= 0)
        return;

    for(i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Model: ");
        scanf("%s", newnode->model);
        printf("Price: ");
        scanf("%f", &newnode->price);
        printf("Manufacturer: ");
        scanf("%s", newnode->manuf);
        printf("CC: ");
        scanf("%d", &newnode->cc);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            newnode->prev = NULL;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    printf("List created successfully!\n");
}

void add()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Model: ");
    scanf("%s", newnode->model);
    printf("Price: ");
    scanf("%f", &newnode->price);
    printf("Manufacturer: ");
    scanf("%s", newnode->manuf);
    printf("CC: ");
    scanf("%d", &newnode->cc);

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Car added successfully!\n");
}

void display()
{
    struct node *temp = head;
    int i = 1;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\nCar %d\n", i++);
        printf("Model: %s\n", temp->model);
        printf("Price: %.2f\n", temp->price);
        printf("Manufacturer: %s\n", temp->manuf);
        printf("CC: %d\n", temp->cc);
        temp = temp->next;
    }
}

void cdelete()
{
    struct node *temp = head;
    char dmodel[max];

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter model to delete: ");
    scanf("%s", dmodel);

    while(temp != NULL && strcmp(temp->model, dmodel) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Car not found!\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Car deleted successfully!\n");
}

void update()
{
    struct node *temp = head;
    char umodel[max];

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter model to update: ");
    scanf("%s", umodel);

    while(temp != NULL && strcmp(temp->model, umodel) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Car not found!\n");
        return;
    }

    printf("Enter new price: ");
    scanf("%f", &temp->price);
    printf("Enter new CC: ");
    scanf("%d", &temp->cc);

    printf("Record updated successfully!\n");
}



