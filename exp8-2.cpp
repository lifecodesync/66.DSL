#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// ENQUEUE → Insert at END
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d inserted into queue\n", x);
}

// DEQUEUE → Delete from BEGINNING
void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = head;
    printf("%d deleted from queue\n", temp->data);

    head = head->next;
    free(temp);
}

// DISPLAY
void display() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
