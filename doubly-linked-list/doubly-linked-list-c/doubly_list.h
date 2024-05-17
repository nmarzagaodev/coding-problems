#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

typedef struct DoublyLinkedNode {
    char* data;
    struct DoublyLinkedNode* prev;
    struct DoublyLinkedNode* next;
} 
DoublyLinkedNode;

typedef struct DoublyLinkedList {
    DoublyLinkedNode* first_node;
    DoublyLinkedNode* last_node;
} 
DoublyLinkedList;

DoublyLinkedNode* dnode_new(char* new_data);
DoublyLinkedList* dlist_new(); 
void destroy_dlist(DoublyLinkedList* list);

void insert_after(DoublyLinkedList* list, DoublyLinkedNode* node, DoublyLinkedNode* new_node);
void insert_before(DoublyLinkedList* list, DoublyLinkedNode* node, DoublyLinkedNode* new_node); 
void insert_beginning(DoublyLinkedList* list, DoublyLinkedNode* new_node); 
void insert_end(DoublyLinkedList* list, DoublyLinkedNode* new_node);

void delete(DoublyLinkedList* list, DoublyLinkedNode* node);

DoublyLinkedNode* find(DoublyLinkedList* list, char* target);
void print_doubly_linked_list(DoublyLinkedList* list);

#endif

