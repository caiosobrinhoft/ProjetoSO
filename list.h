typedef struct ListNode {
    void *content;
    struct ListNode *next;
    struct ListNode *prev;
} list_node_t;

// Lista duplamente encadeada
typedef struct List {
    list_node_t *head;
    list_node_t *tail;
    int size;
} list_t;