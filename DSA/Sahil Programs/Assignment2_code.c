/*
Question 3:
Write a menu-driven program that utilizes a singly linked list to handle operations such as adding, removing, and displaying books, as well as searching for specific books and counting the total number of books available.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define max 100
struct node{
    char name[max];
    struct node *next;
}*head=NULL;

void createbook();
void addbook();
void removebook();
void displaybooks();
void searchbook();
void counttotalbooks();


void main(){
    int choice;
    
    while(1){
        printf("\n----Libaray Management Using Linked List----\n\n");
        printf("1: Create list of books :\n");
        printf("2:Add a Book :\n");
        printf("3:Remove a book :\n");
        printf("4:Display all Books :\n");
        printf("5:Search for Book :\n");
        printf("6:Count total books :\n");
        printf("7:Exit book libaray :\n");
        printf("\n Enter your choice :\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                createbook();
                break;
            case 2:
                addbook();
                break;
            case 3:
                removebook();
                break;
            case 4:
                displaybooks();
                break;
            case 5:
                searchbook();
                break;
            case 6:
                counttotalbooks();
                break;
            case 7:
                printf("\nExiting the program \n");
                exit(0);
            default :
                printf("Invalid choice! Try again.\n");
                
        }   
        
    }
        
}

void createbook()
{
    struct node *newnode,*temp;
    int n,i;
    printf("\n Enter number of nodes to create ! \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the name of book for book number %d ! ",i+1);
        scanf("%s",&newnode->name);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;           
        }
        else
        {
        temp->next=newnode;
        temp=newnode;
        
        }
    }
    printf("Linked list is created you can add books :");
    
}

void addbook()
{
struct node *newnode,*temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
if(!newnode)
{
    printf("Memory allocation failed ! ");
}
printf("\n Enter book name : \n");
scanf("%s",newnode->name);
newnode->next=NULL;


if(head==NULL)
{
    printf("list is empty ! ");
    head=newnode;
}
else{
    while(temp->next!=NULL)
    {
        temp=temp->next;    
    }
    temp->next=newnode;
}
    printf("New Book Added Successfully !");
} 

void displaybooks()
{
struct node *temp=head;
int i=0;
printf("---------BOOKS-BY-NUMBER---------\n");
while(temp!=NULL)
{
    printf("\n Book no %d Name: %s",i+1,temp->name);
    temp=temp->next;
    i++;
}   
} 

void removebook()
{
struct node *temp=head,*temp2;
char dbook[max];
printf("Enter book name to delete a book \n");
scanf("%s",dbook);
if(temp==NULL)
{
    printf("library is empty !");
}
if(strcmp(head->name,dbook)==0){
    temp=head;
    head=head->next;
    free(temp);
    printf("book deleted it was first book !");
    return;
}
while(temp!=NULL&&strcmp(temp->name,dbook)!=0)
{
    temp2=temp;
    temp=temp->next;
}
if(temp==NULL)
{
    printf("Not Found! ");
    return;
}
temp2->next=temp->next;
free(temp);
printf("Book deleted successfully ! ");

} 

void searchbook()
{
    struct node *temp=head;
    char sbook[max];
    int pos=1,found=0;
    
    printf("enter a book name to search : ");
    scanf("%s",sbook);
    while(temp!=NULL)
    {
        if(strcmp(temp->name,sbook)!=0)
        {
            temp=temp->next;
            pos++;
        }
        else
        {
            printf("book found ! %s at position : %d",temp->name,pos);
            found=1;
            break;
        }
    }   
    if(!found)
    {
            printf("Book not found!");
    }

}

void counttotalbooks()
{
    struct node *temp=head;
    int count=1;
    if(head==NULL)
    {
        printf("There is no books in library ");
    }
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("Total Number of books are : %d ",count-1);
    
}



