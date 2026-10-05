#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* Function declarations */
void push();
void pop();
void display();

int main()
{
int choice;

while (1)
{
printf("\n\n===== STACK MENU =====");
printf("\n1. Push an Element");
printf("\n2. Pop an Element");
printf("\n3. Display Stack");
printf("\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
push();
break;

case 2:
pop();
break;

case 3:
display();
break;

case 4:
printf("\nExiting program...");
exit(0);

default:
printf("\nInvalid choice! Please try again.");
}
}

return 0;
}

/* Function to push an element */
void push()
{
int item;

if (top == MAX - 1)
{
printf("\nStack Overflow!");
printf("\nStack is full. Cannot insert an element.");
}
else
{
printf("\nEnter the element to push: ");
scanf("%d", &item);

top++;
stack[top] = item;

printf("\n%d is pushed onto the stack.", item);
}
}

/* Function to pop an element */
void pop()
{
int item;

if (top == -1)
{
printf("\nStack Underflow!");
printf("\nStack is empty. Cannot delete an element.");
}
else
{
item = stack[top];
top--;

printf("\n%d is popped from the stack.", item);
}
}

/* Function to display the stack */
void display()
{
int i;

if (top == -1)
{
printf("\nStack is empty.");
}
else
{
printf("\nStack elements are:\n");

for (i = top; i >= 0; i--)
{
printf("| %d |\n", stack[i]);
}

printf("-----\n");
}
}
