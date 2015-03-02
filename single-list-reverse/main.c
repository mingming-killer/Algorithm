/**
 * This wandoujia 1st test. 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list_t {
    struct list_t* next;
    int data; 
} list;

void insert_node(list* head, int data) {
    list* node = (list*)malloc(sizeof(list));
    node->next = NULL;
    node->data = data;

    list* last = head;
    while(NULL != last->next) {
        last = last->next;
    }
    last->next = node;
}

list* get_node(list* head, int pos) {
    int i;
    list* node = head;
    for (i = 0; i < pos; i++) {
        node = node->next;
    }
    return node;
}

void rev_list(list* head, int s, int e) {
    list* next = NULL;
    list* pos = NULL;

    list* s_prev_node = get_node(head, s - 1);
    list* s_node = get_node(head, s);
    list* e_next_node = get_node(head, e + 1);

    int i, j;
    int c1 = e - s;
    int c2 = c1;
    pos = s_prev_node;
    for (i = 0; i < c1; i++) {
        next = s_node;
        for (j = 0; j < c2; j++) {
            next = next->next;
        }
        pos->next = next;
        pos = pos->next;
        c2--;
    }
    pos->next = s_node;
    s_node->next = e_next_node;
}

void print_list(list* head) {
    printf("list is: ");
    while(NULL != head) {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int i = 0;
    list* head = (list*)malloc(sizeof(list));
    head->next = NULL;
    head->data = 1;

    for (i = 1; i < 5; i++) {
        insert_node(head, i + 1);
    }
    print_list(head);

    rev_list(head, 1, 3);
    print_list(head);

    return 0;
}
