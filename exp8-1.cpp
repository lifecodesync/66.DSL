#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// PUSH → Insert at END
void push(int x) {
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

    printf("%d pushed into stack\n", x);
}

// POP → Delete from END
void pop() {
    if (head == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If only one node
    if (temp->next == NULL) {
        printf("%d popped from stack\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    // Traverse to last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("%d popped from stack\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// DISPLAY
void display() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN
int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    return 0;
}
