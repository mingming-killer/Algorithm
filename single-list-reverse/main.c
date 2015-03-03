/**
 * This wandoujia 1st test. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    struct list_t* next;
    int data; 
} list;

#define LIST_SIZE (sizeof(list))

list* init_list() {
    list* head = (list*)malloc(LIST_SIZE);
    if (NULL != head) {
        memset(head, 0, LIST_SIZE);
    }
    return head;
}

void free_list(list* head) {
    if (NULL == head) {
        return;
    }

    list* tmp = NULL;
    list* node = head;
    while(NULL != node) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

void print_list(list* head) {
    if (NULL == head) {
        return;
    }

    printf("list is: ");
    while(NULL != head) {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

int list_size(list* head) {
    if (NULL == head) {
        return 0;
    }

    int count = 0;
    while(NULL != head) {
        count++;
        head = head->next;
    }
    return count;
}

void insert_node(list* head, int data) {
    if (NULL == head) {
        return;
    }

    list* node = (list*)malloc(LIST_SIZE);
    node->next = NULL;
    node->data = data;

    list* last = head;
    while(NULL != last->next) {
        last = last->next;
    }
    last->next = node;
}

list* get_node(list* head, int pos) {
    if (NULL == head || pos < 0) {
        return NULL;
    }

    int i;
    list* node = head;
    for (i = 0; i < pos; i++) {
        node = node->next;
        if (NULL == node) {
            return NULL;
        }
    }
    return node;
}

list* rev_list(list* head, int s, int e) {
    list* next = NULL;
    list* pos = NULL;

    list* s_prev_node = get_node(head, s - 1);
    list* s_node = get_node(head, s);
    list* e_node = get_node(head, e);
    list* e_next_node = get_node(head, e + 1);
    if (NULL == s_node || NULL == e_node) {
        printf("your input is invaild!! \n");
        return head;
    }

    int i, j;
    int c1 = e - s;
    int c2 = c1;
    pos = s_prev_node;
    for (i = 0; i < c1; i++) {
        next = s_node;
        for (j = 0; j < c2; j++) {
            next = next->next;
        }
        // the s_prev_node is NULL the s is the head.
        if (NULL != pos) {
            pos->next = next;
        }
        pos = next;
        c2--;
    }
    pos->next = s_node;
    s_node->next = e_next_node;

    // the s is head, the new head should be the reverse end node
    if (NULL == s_prev_node) {
        return e_node;
    } else {
        return head;
    }
}

int main(int argc, char** argv) {
    int i = 0;
    list* head = init_list();
    head->next = NULL;
    head->data = 1;

    for (i = 1; i < 5; i++) {
        insert_node(head, i + 1);
    }
    print_list(head);

    head = rev_list(head, 1, 3);
    //head = rev_list(head, 0, 2);
    //head = rev_list(head, 2, 4);
    print_list(head);

    free_list(head);
    return 0;
}
