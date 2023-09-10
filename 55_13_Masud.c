/*Circular-queue*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 13
SE-IT
2023-24
*/


#include <stdio.h>
#define size 5
int cqueue[size];
int front = -1;
int rear = -1;


void enqueue(int x){
    if((rear==size-1 && front==0) || front==rear+1){
        printf("Queue Full");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front++;
            rear++;
            cqueue[rear]=x;
        }
        else{
            rear=(rear+1)%size;
            cqueue[rear]=x;
        }
    }
}

void dequeue()
{
    if(front==-1 && rear==-1){
        printf("Queue Empty");
        return;
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue empty");
    }
    else{
        for(int i=front; i!=rear; i=(i+1)%size){
        printf("%d\n", cqueue[i]);
        } 
        printf("%d\n", cqueue[rear]);   
    }
    
}

void main(){
    int x, ch;
    while (ch!=4)
    {
        printf("\n---Menu---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &x);
            enqueue(x);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            break;

            default: printf("Invalid choice");
        }
    }
}