#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Add a print job to the queue */
void addJob() {
int job;

if ((rear + 1) % MAX == front) {
printf("\nQueue Overflow! Printer queue is full.\n");
return;
}

printf("Enter Print Job ID: ");
scanf("%d", &job);

if (front == -1) {
front = 0;
}

rear = (rear + 1) % MAX;
queue[rear] = job;

printf("Print job %d added successfully.\n", job);
}

/* Process/delete a print job */
void processJob() {
int job;

if (front == -1) {
printf("\nQueue Underflow! No print jobs waiting.\n");
return;
}

job = queue[front];

printf("Processing print job: %d\n", job);

if (front == rear) {
/* Queue becomes empty */
front = -1;
rear = -1;
} else {
front = (front + 1) % MAX;
}
}

/* Display number of waiting jobs */
void displayCount() {
int count;

if (front == -1) {
count = 0;
} else if (rear >= front) {
count = rear - front + 1;
} else {
count = MAX - front + rear + 1;
}

printf("\nNumber of print jobs waiting: %d\n", count);
}

/* Display all jobs in the queue */
void displayQueue() {
int i;

if (front == -1) {
printf("\nPrinter queue is empty.\n");
return;
}

printf("\nPrint jobs currently in queue:\n");

i = front;

while (1) {
printf("%d ", queue[i]);

if (i == rear)
break;

i = (i + 1) % MAX;
}

printf("\n");
}

int main() {
int choice;

do {
printf("\n========== PRINTER QUEUE ==========\n");
printf("1. Add Print Job\n");
printf("2. Process Print Job\n");
printf("3. Display Number of Waiting Jobs\n");
printf("4. Display Queue\n");
printf("5. Exit\n");
printf("===================================\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
addJob();
break;

case 2:
processJob();
break;

case 3:
displayCount();
break;

case 4:
displayQueue();
break;

case 5:
printf("\nExiting program...\n");
break;

default:
printf("\nInvalid choice! Please try again.\n");
}

} while (choice != 5);

return 0;
}
