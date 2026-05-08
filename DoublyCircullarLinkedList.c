#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *new_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->prev = n;
    n->next = n;
    return n;
}

void insert_end(int data) {
    Node *n = new_node(data);
    if (head == NULL) {
        head = n;
    } else {
        Node *tail = head->prev;
        tail->next = n;
        n->prev = tail;
        n->next = head;
        head->prev = n;
    }
    printf("Inserted %d at end.\n", data);
}

void insert_begin(int data) {
    Node *n = new_node(data);
    if (head == NULL) {
        head = n;
    } else {
        Node *tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
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

    if (head == NULL) {
        insert_end(data);
        return;
    }

    Node *curr = head;
    int len = 1;

    while (curr->next != head) {
        curr = curr->next;
        len++;
    }

    if (pos > len + 1) {
        printf("Position out of range. Inserting at end.\n");
        insert_end(data);
        return;
    }

    curr = head;

    int i;
    for (i = 1; i < pos - 1; i++) {
        curr = curr->next;
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

    Node *tail = head->prev;

    if (head == tail) {
        printf("Deleted %d.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    Node *tmp = head;
    tail->next = head->next;
    head->next->prev = tail;
    head = head->next;

    printf("Deleted %d from beginning.\n", tmp->data);
    free(tmp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *tail = head->prev;

    if (head == tail) {
        printf("Deleted %d.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    Node *new_tail = tail->prev;
    new_tail->next = head;
    head->prev = new_tail;

    printf("Deleted %d from end.\n", tail->data);
    free(tail);
}

void delete_value(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *curr = head;

    do {
        if (curr->data == data) {
            if (curr->next == curr) {
                free(curr);
                head = NULL;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head) head = curr->next;
                free(curr);
            }
            printf("Deleted node with value %d.\n", data);
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Value %d not found.\n", data);
}

void display_forward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *curr = head;
    printf("\nForward  : HEAD -> ");

    do {
        printf("[%d] <-> ", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("(HEAD)\n");
}

void display_backward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *tail = head->prev;
    Node *curr = tail;

    printf("Backward : TAIL -> ");

    do {
        printf("[%d] <-> ", curr->data);
        curr = curr->prev;
    } while (curr != tail);

    printf("(TAIL)\n\n");
}

void free_list() {
    if (head == NULL) return;

    Node *curr = head->next;
    Node *tmp;

    while (curr != head) {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }

    free(head);
    head = NULL;
}

void print_menu() {
    printf("\n============================================\n");
    printf("   DOUBLY CIRCULAR LINKED LIST MENU\n");
    printf("============================================\n");
    printf(" 1. Insert at End\n");
    printf(" 2. Insert at Beginning\n");
    printf(" 3. Insert at Position\n");
    printf(" 4. Delete from Beginning\n");
    printf(" 5. Delete from End\n");
    printf(" 6. Delete by Value\n");
    printf(" 7. Display (Forward & Backward)\n");
    printf(" 8. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, data, pos;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_end(data);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_begin(data);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_position(data, pos);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                delete_value(data);
                break;

            case 7:
                display_forward();
                display_backward();
                break;

            case 8:
                free_list();
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1-8.\n");
        }
    }
}
