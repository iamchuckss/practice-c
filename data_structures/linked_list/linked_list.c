#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "linked_list.h"


/* Initialize list */
Node List_init (void) {
    Node head;
    head = (Node) malloc(sizeof(struct ListNode));
    head->next = NULL;
    return head;
}

/* Push an element onto top of the list */
Node List_push(Node head, void *val) {
    Node new_node = (Node) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

/* Get length of list */
int List_length(Node head) {
    int n = 0;
    while (head != NULL) {
        n++;
        head = head->next;
    }
    return n;
}

/* Convert list to array */
void **List_toArray(Node head) {
    int i,  n = List_length(head);
    void **array = (void **) malloc((n+1)*sizeof(*array));

    for (i = 0; i < n; i++) {
        array[i] = head->val;
        head = head->next;
    }
    array[i] = NULL;
    return array;
}
