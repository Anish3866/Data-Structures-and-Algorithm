#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *tail = NULL;

Node *new_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));

    if (n == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n->data = data;
    n->next = n;

    return n;
}

void insert_end(int data) {
    Node *n = new_node(data);

    if (tail == NULL) {
        tail = n;
    } else {
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }

    printf("Inserted %d.\n", data);
}

void insert_begin(int data) {
    Node *n = new_node(data);

    if (tail == NULL) {
        tail = n;
    } else {
        n->next = tail->next;
        tail->next = n;
    }

    printf("Inserted %d at beginning.\n", data);
}

void insert_position(int data, int pos) {
    Node *curr;
    Node *n;
    int i;

    if (pos <= 1) {
        insert_begin(data);
        return;
    }

    curr = tail->next;

    for (i = 1; i < pos - 1; i++) {
        curr = curr->next;

        if (curr == tail->next) {
            printf("Position out of range. Inserting at end.\n");
            insert_end(data);
            return;
        }
    }

    n = new_node(data);

    n->next = curr->next;
    curr->next = n;

    if (curr == tail) {
        tail = n;
    }

    printf("Inserted %d at position %d.\n", data, pos);
}

void delete_begin() {
    Node *head;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    head = tail->next;

    if (head == tail) {
        printf("Deleted %d.\n", head->data);
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next;
        printf("Deleted %d.\n", head->data);
        free(head);
    }
}

void delete_end() {
    Node *head;
    Node *curr;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    head = tail->next;

    if (head == tail) {
        printf("Deleted %d.\n", tail->data);
        free(tail);
        tail = NULL;
    } else {
        curr = head;

        while (curr->next != tail) {
            curr = curr->next;
        }

        printf("Deleted %d.\n", tail->data);

        free(tail);

        tail = curr;
        tail->next = head;
    }
}

void delete_value(int data) {
    Node *head;
    Node *curr;
    Node *prev;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    head = tail->next;
    curr = head;
    prev = tail;

    do {
        if (curr->data == data) {

            if (curr == tail && curr == head) {
                tail = NULL;
            } else {
                prev->next = curr->next;

                if (curr == tail) {
                    tail = prev;
                }
            }

            free(curr);

            printf("Deleted node with value %d.\n", data);
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != head);

    printf("Value %d not found in list.\n", data);
}

void display() {
    Node *head;
    Node *curr;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    head = tail->next;
    curr = head;

    printf("\nCircular Linked List:\n");
    printf("HEAD -> ");

    do {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("(HEAD)\n");
}

void free_list() {
    Node *head;
    Node *curr;
    Node *temp;

    if (tail == NULL) {
        return;
    }

    head = tail->next;
    tail->next = NULL;

    curr = head;

    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    tail = NULL;
}

void print_menu() {
    printf("\n========================================\n");
    printf("     CIRCULAR LINKED LIST MENU\n");
    printf("========================================\n");
    printf("1. Insert at End\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete by Value\n");
    printf("7. Display List\n");
    printf("8. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int data;
    int pos;

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
                display();
                break;

            case 8:
                free_list();
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1-8.\n");
        }
    }

    return 0;
}
