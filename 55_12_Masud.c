/*Queue*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 12
SE-IT
2023-24
*/

#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear, front;

void init();
void enqueue(int);
void dequeue();
void display();

void init(){
    front=0;
    rear=-1;
}

void enqueue(int x){
    if(rear==size-1){
        printf("Queue Overflow!");
    }
    else{
        rear=rear+1;
        queue[rear]=x;
    }
}

void dequeue(){
    if(rear<front){
        printf("Queue is empty!");
    }
    else{
        printf("\n %d is deleted", queue[front++]);
    }
}

void display(){
    int i;
    if(rear<front){
        printf("\nQueue is Empty\n");
    }
    else{
        for(i=front; i<=rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

void main(){
    int ch;
    int x;
    init();
    while(1){
        printf("\nQueue Operations\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display the queue elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("\nEnter the elements to be enqueued: ");
                    scanf("%d", &x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default: printf("\n Wrong Choice");
                     break; 
        }
    }
}