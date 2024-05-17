#include <stdio.h>
#include "doubly_list.h"

int main(void) {
    DoublyLinkedList* list = dlist_new();

    insert_end(list, dnode_new("Nicolas"));
    insert_end(list, dnode_new("Arthur"));

    print_doubly_linked_list(list);

    destroy_dlist(list);
    return 0;
}

