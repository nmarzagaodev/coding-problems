#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Experimenting with Void Pointers

enum DataType {
    NONE,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_FLOAT,
    TYPE_STRING
};

typedef struct GenericArrayItem {
    void* value;
    enum DataType type;
} GenericArrayItem;

typedef struct GenericArray {
    GenericArrayItem** items; 
    int length;
} GenericArray;

GenericArrayItem* GenericArrayItem_new(enum DataType type) {
    GenericArrayItem* item = malloc(sizeof(GenericArrayItem));
    item->value = NULL;
    item->type = type;

    return item;
}

GenericArray* GenericArray_new(int array_len) {
    GenericArray* ga = malloc(sizeof(GenericArray));
    ga->items = calloc(array_len, sizeof(GenericArrayItem*));
    ga->length = array_len;

    for (int i = 0; i < array_len; i++) 
        ga->items[i] = NULL;

    return ga;
}

void GenericArray_insertString(GenericArrayItem* item, void* data, enum DataType type) {
    item = GenericArrayItem_new(type);

    item->value = malloc(strlen((char*) data + 1));
    strcpy(item->value, (char*) data);
}

void GenericArray_insertInt(GenericArrayItem* item, void* data, enum DataType type) {
    item = GenericArrayItem_new(type);

    item = malloc(sizeof(int));
    item->value = (int*) data;
}

void GenericArray_insert(GenericArray* array, void* data, enum DataType type, int index) {
    switch(type) {
        case TYPE_STRING:
            GenericArray_insertString(array->items[index], data, type);
            break;
        case TYPE_INT:
            GenericArray_insertInt(array->items[index], data, type);
            break;
        
    }
}

void GenericArray_forEach(GenericArray* array, void (*function)(GenericArrayItem*)) {
    for (int i = 0; i < array->length; i++)
        function(array->items[i]);
}

void array_print(GenericArrayItem* item) {
    if (item != NULL) {
        switch (item->type) {
            case TYPE_STRING:
                printf("%s\n", (const char*) item->value);
                break;
            case TYPE_INT:
                printf("%d\n", (*(int*) item->value));
                break;
        }
    }
}


int main(void) {
    GenericArray* array = GenericArray_new(10);

    char* name = "Nicolas";
    int value = 10;

    GenericArray_insert(array, name, TYPE_STRING, 0);
    GenericArray_insert(array, &value, TYPE_INT, 1);

    GenericArray_forEach(array, array_print);

    //printf("array[0] = %s\n", (const char*)array->items[0]->value);
    // printf("array[1] = %d\n", (*(int*) array->items[1]->value));

    return 0;
}
