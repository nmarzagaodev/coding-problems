#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

// List Functions
int* generate_random_list(size_t size);
void print_list(int* list, size_t size);

// Bubble Sort Functions
void swap_integers(int* a, int* b);
void bubble_sort(int* list, size_t size);

int main() {
    size_t list_size = 3;
    int* list = generate_random_list(list_size);

    printf("Random List: ");
    print_list(list, list_size);

    bubble_sort(list, list_size);

    printf("Bubble Sorted List: ");
    print_list(list, list_size);

    free(list);

    return 0;
}


int* generate_random_list(size_t size) {
    int* list = calloc(size, sizeof(int));

    srand(time(NULL));
    for (size_t i = 0; i < size; i++)         
        list[i] = rand() % 50;

    return list;
}

void print_list(int* list, size_t size) {
    printf("[");

    for (size_t i = 0; i < size; i++)
        printf(" %d, ", list[i]);

    printf("]\n");
}


void swap_integers(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void bubble_sort(int* list, size_t size) {
    bool swapped;

    for (size_t i = 0; i < size - 1; i++) {
        swapped = false;

        for (size_t j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap_integers(&list[j], &list[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) break;
    }
}

