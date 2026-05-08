#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *new_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insert_end(int data) {
    Node *n = new_node(data);

    if (head == NULL) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    printf("Inserted %d at end.\n", data);
}

void insert_begin(int data) {
    Node *n = new_node(data);

    if (head == NULL) {
        head = tail = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }

    printf("Inserted %d at beginning.\n", data);
}

void insert_position(int data, int pos) {
    if (pos <= 1) {
        insert_begin(data);
        return;
    }

    Node *curr = head;
    int i;

    for (i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr == tail) {
        insert_end(data);
        return;
    }

    Node *n = new_node(data);

    n->next = curr->next;
    n->prev = curr;

    curr->next->prev = n;
    curr->next = n;

    printf("Inserted %d at position %d.\n", data, pos);
}

void delete_begin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *tmp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    printf("Deleted %d from beginning.\n", tmp->data);
    free(tmp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *tmp = tail;

    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    printf("Deleted %d from end.\n", tmp->data);
    free(tmp);
}

void delete_value(int data) {
    Node *curr = head;

    while (curr != NULL && curr->data != data)
        curr = curr->next;

    if (curr == NULL) {
        printf("Value %d not found.\n", data);
        return;
    }

    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        head = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    else
        tail = curr->prev;

    printf("Deleted %d.\n", data);
    free(curr);
}

void display() {
    Node *curr;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nForward  : NULL <-> ");
    curr = head;

    while (curr != NULL) {
        printf("[%d] <-> ", curr->data);
        curr = curr->next;
    }

    printf("NULL\n");

    printf("Backward : NULL <-> ");
    curr = tail;

    while (curr != NULL) {
        printf("[%d] <-> ", curr->data);
        curr = curr->prev;
    }

    printf("NULL\n");
}

void free_list() {
    Node *curr = head, *tmp;

    while (curr != NULL) {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    head = tail = NULL;
}

void print_menu() {
    printf("\n========================================\n");
    printf("      DOUBLY LINKED LIST MENU\n");
    printf("========================================\n");
    printf("1. Insert at End\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete by Value\n");
    printf("7. Display\n");
    printf("8. Exit\n");
    printf("========================================\n");
    printf("Enter choice: ");
}

int main() {
    int choice, data, pos;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &data);
                insert_end(data);
                break;

            case 2:
                scanf("%d", &data);
                insert_begin(data);
                break;

            case 3:
                scanf("%d %d", &data, &pos);
                insert_position(data, pos);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                scanf("%d", &data);
                delete_value(data);
                break;

            case 7:
                display();
                break;

            case 8:
                free_list();
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
