#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct HashTableItem {
    char* key;
    char* value;
} HashTableItem;

typedef struct HashTable {
    HashTableItem** items; // array of pointers to items
    unsigned long size;
    unsigned long count;
} HashTable;

HashTableItem* HashTableItem_new(char* key, char* value) {
    HashTableItem* item = malloc(sizeof(HashTableItem));
    item->key = malloc(strlen(key) + 1);
    item->value = malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* HashTable_new(unsigned long size) {
    HashTable* table = malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = calloc(table->size, sizeof(HashTableItem*));

    for (int i = 0; i < table->size; i++) 
        table->items[i] = NULL;

    return table;
}

void HashTableItem_destroy(HashTableItem* item) {
    free(item->key);
    free(item->value);
    free(item);
}

void HashTable_destroy(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        HashTableItem* item = table->items[i];
        if (item != NULL)
            HashTableItem_destroy(item);
    }

    free(table->items);
    free(table);
}

void HashTable_forEach(HashTable* table, void (*function)(HashTableItem*)) {
    for (int i = 0; i < table->size; i++)
        if (table->items[i] != NULL) function(table->items[i]);
}

unsigned long HashTable_hashFunction(HashTable* table, char* hash_key) {
    unsigned long total = 0;

    for (int i = 0; i < strlen(hash_key); i++) {
        int ascii_code = hash_key[i];
        total += ascii_code;
    }

    return total % table->size;
}

void HashTable_handleCollision(HashTable* table, HashTableItem* item) {
    // TODO
}

void HashTable_insert(HashTable* table, char* key, char* value) {
    HashTableItem* item = HashTableItem_new(key, value);
    unsigned long index = HashTable_hashFunction(table, key);

    HashTableItem* current_item = table->items[index];

    if (current_item == NULL) {
        // Key does not exist
        if (table->count == table->size) {
            printf("Insert Error: Hash Table is full\n");
            HashTableItem_destroy(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    } else {
        // Scenario 1: Update the value
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value, value);
            return;
        } else {
            // Scenario 2: Handle Collision
            HashTable_handleCollision(table, item);
            return;
        }
    }

}


void main(void) {
    printf("Hello C!\n");

    int result = hash_integer(23, 97);
    printf("hash int = %d\n", result);

    printf("Hash String = %d\n", hash_string("B7MF", 97));
}
