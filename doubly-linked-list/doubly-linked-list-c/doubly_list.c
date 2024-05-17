#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_list.h"

DoublyLinkedNode* dnode_new(char* new_data) {
    // Creates a Doubly Linked Node
    DoublyLinkedNode* new_node = malloc(sizeof(DoublyLinkedNode));
    new_node->data = calloc(strlen(new_data), sizeof(char));
    strcpy(new_node->data, new_data);
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

DoublyLinkedList* dlist_new() {
    // Creates a Doubly Linked List
    DoublyLinkedList* new_list = malloc(sizeof(DoublyLinkedList));
    new_list->first_node = NULL;
    new_list->last_node  = NULL;

    return new_list;
}

void destroy_dlist(DoublyLinkedList* list) {
    DoublyLinkedNode* curr = list->first_node;
    DoublyLinkedNode* target;
    while (curr != NULL) {
        target = curr;
        curr = curr->next;

        free(target->data);
        free(target);
    }
    free(list);
}

// INSERTING NODES
void insert_after(DoublyLinkedList* list, DoublyLinkedNode* node, DoublyLinkedNode* new_node) {
    // inserts a node after a given node.
    new_node->prev = node;
    if (node->next == NULL) {
        new_node->next = NULL;
        list->last_node = new_node;
    } 
    else {
        new_node->next = node->next;
        node->next->prev = new_node;
    }
    node->next = new_node;
}

void insert_before(DoublyLinkedList* list, DoublyLinkedNode* node, DoublyLinkedNode* new_node) {
    // Inserts a node befoure a given node.
    new_node->next = node;
    if (node->prev == NULL) {
        new_node->prev = NULL;
        list->first_node = new_node;
    }
    else {
        new_node->prev = node->prev;
        node->prev->next = new_node;
    }
    node->prev = new_node;
}

void insert_beginning(DoublyLinkedList* list, DoublyLinkedNode* new_node) {
    // Inserts a node at the beginning of a list
    if (list->first_node == NULL) {
        list->first_node = new_node;
        list->last_node  = new_node;
        new_node->prev   = NULL;
        new_node->next   = NULL;
    }
    else insert_before(list, list->first_node, new_node);
}    

void insert_end(DoublyLinkedList* list, DoublyLinkedNode* new_node) {
    // Inserts a node at the end of a list
    if (list->last_node == NULL) insert_beginning(list, new_node);
    else insert_after(list, list->last_node, new_node);
}

// REMOVE 
void delete(DoublyLinkedList* list, DoublyLinkedNode* node) {
    if (node->prev == NULL) list->first_node = node->next;
    else node->prev->next = node->next;

    if (node->next == NULL) list->last_node = node->prev;
    else node->next->prev = node->prev;
}

// FIND
DoublyLinkedNode* find(DoublyLinkedList* list, char* target) {
    // Checks if data is present in the list, and returns its node
    DoublyLinkedNode* tmp = list->first_node;
    while (tmp != NULL) {
        if (strcmp(target, tmp->data) == 0) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void print_doubly_linked_list(DoublyLinkedList* list) {
    // Prints a doubly linked list to the terminal 
    DoublyLinkedNode* tmp = list->first_node;
    while (tmp != NULL) {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}
