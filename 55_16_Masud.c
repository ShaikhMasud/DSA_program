/*Stack implementation using linked list*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 16
SE-IT
2023-24
*/

#include<stdio.h>
#include<stdlib.h>

int choice, x;

//strcture of a node of LL
struct node
{
    struct node *next;
    int info;
};

//to create memory for a node
struct node* getnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
}

//to free a node
void freenode(struct node* p)
{
    free(p);
}

//initializing the LL
struct node *list = NULL;

//to insert an element at end of LL
void push(int x)
{
    if(list==NULL)
    {
        //if empty
        struct node *newnode;
        newnode=getnode();
        newnode->info=x;
        newnode->next=list;
        list=newnode;
        return;
    }
    //attach node at the end
    struct node *nn, *temp;
    nn= getnode();
    nn->info = x;
    nn->next =NULL;
    temp = list;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next = nn;
}

//to delete last node
void pop()
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    if(list->next==NULL)
    {
        struct node *temp;
        temp =list;
        list = list->next;
        freenode(temp);
        return;
    }
    struct node *temp, *t2;
    temp=list;
    while(temp->next->next!=NULL)
    {
        t2=temp;
        temp =temp->next;
    }
    freenode(temp->next);
    temp->next=NULL;
}

//to display LL
void display()
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    struct node *temp;
    temp=list;
    while(temp->next!=NULL)
    {
        printf("%d\n", temp->info);
        temp=temp->next;
    }
    printf("%d", temp->info);
}

void main()
{

    /*calling the everlasting choices*/
    while(choice!=4)
    {
        /*description of menu bar*/
        printf("\n\n\n\n-----These are the menu panel-----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        printf("\nenter the option no.: ");
        scanf("%d", &choice);

        /*switch on entered choice*/
        switch(choice)
        {
            /*case-wise calling functions*/
            case 1: 
            printf("enter the number you want to push: ");
            scanf("%d", &x);
            push(x);
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4:
                break;
            default:
                printf("incorrect choice");
        }
    }/*end of while*/

    /*code execution completed*/
    printf("You got exit\n");
}