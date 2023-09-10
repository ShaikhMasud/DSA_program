/*Stack*/

/*
Name = Shaikh Masud
Roll No = 55
pid = 11
SE-IT
2023-24
*/


#include<stdio.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push(int);
void pop();
void display();
void main(){
    int ch;
    int n1;

    while(ch!=4){
        printf("\nStack Operation\n");
        printf("1.Push an element into the stack\n");
        printf("2.Pop an element from the stack\n");
        printf("3.Display the stack's element\n");
        printf("4.Exit\n");
        printf("Enter a choice:");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("\nEnter the element to be entered:");
                    scanf("%d", &n1);
                    push(n1);
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: exit(1);

            default: printf("Wrong choice!");
                     break;       
        }   
    }
}

void push(int n1){
    if(top==4){
        printf("Stack is full!");
    }
    else{
        top++;
        stack[top]=n1;
    }
}

void pop(){
    int a;
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        a=stack[top];
        top--;
        printf("%d element is popped out", a);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        printf("\nElements in the stack are:\n");
        for(i=top; i>=0; i--){
            printf("\n %d", stack[i]);
        }
    }
}