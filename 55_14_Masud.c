/*Double-ended queue*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 14
SE-IT
2023-24
*/


#include <stdio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;


void enqueuerear(int x){
    if((rear==size-1 && front==0) || front==rear+1){
        printf("Queue Full");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front++;
            rear++;
            queue[rear]=x;
        }
        else{
            rear=(rear++)%size;
            queue[rear]=x;
        }
    }
}

void enqueuefront(int x){
    if((rear==size-1 && front==0) || front==rear+1){
        printf("Queue Full");
        return;
    }
    if(front==-1){
        enqueuerear(x);
        return;
    }
    if(front==0){
        front=size-1;
        queue[front]=x;
        return;
    }
    front--;
    queue[front]=x;
}

void dequeuefront(){
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

void dequeuerear(){
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
            if(rear==0){
                rear=size-1;
            }
            else{
                rear--;
            }
        }
    }
}

void display(){
    if(front==-1){
        printf("Queue empty");
    }
    else{
        for(int i=front; i!=rear; i=(i+1)%size){
            printf("%d\n", &queue[i]);
        } 
        printf("%d\n", queue[rear]);   
    }
    
}

void main(){
    int x, ch;
    while (ch!=6)
    {
        printf("\n---Menu---\n1.Enqueue from rear\n2.Enqueue from front\n3.Dequeue from front\n4.Dequeue from rear\n5.Display\n6.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &x);
            enqueuerear(x);
            break;

            case 2:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &x);
            enqueuefront(x);
            break;

            case 3:
            dequeuefront();
            break;

            case 4:
            dequeuerear();
            break;

            case 5:
            display();
            break;

            case 6:
            break;

            default: printf("Invalid choice");
        }
    }
}