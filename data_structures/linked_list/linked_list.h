#ifndef __LIST__
#define __LIST__

typedef struct ListNode *Node;

struct ListNode {
    void *val;
    Node next;
};

extern      Node List_init(void);
extern      Node List_push(Node head, void *val);
extern int    List_length(Node head);
extern void **List_toArray(Node head);
extern      Node List_append(Node head, Node node);
extern      Node List_list(Node head, void *val, ...);
/* TODO */
extern      Node List_copy(Node head);
extern int    List_pop(Node *head);

#endif
