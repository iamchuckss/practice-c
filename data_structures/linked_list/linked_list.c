#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "linked_list.h"

#define L List_T

/* Initialize list */
L List_init (void) {
    L list;
    list = (L) malloc(sizeof(L));
    list->next = NULL;
    return list;
}

/* Push an element onto top of the list */
L List_push(L list, void *val) {
    L new_elem = (L) malloc(sizeof(L));
    new_elem->val = val;
    new_elem->next = list;
    return new_elem;
}

/* Get length of list */
int List_length(L list) {
    int n = 0;
    while (list != NULL) {
        n++;
        list = list->next;
    }
    return n;
}

/* Convert list to array */
void **List_toArray(L list) {
    int i,  n = List_length(list);
    void **array = (void **) malloc((n+1)*sizeof(*array));

    for (i = 0; i < n; i++) {
        array[i] = list->val;
        list = list->next;
    }
    array[i] = NULL;
    return array;
}
