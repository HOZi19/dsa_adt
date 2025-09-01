#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }
    int i;
    for (i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }
    int i; 
    for (i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data) {
    int i;
    for (i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data) {
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }
    int pos = 0;
    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }
    insertPos(L, data, pos);
}

void display(EPtr L) {
    printf("List: ");
    int i;
    for (i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L) {
    free(L);
    printf("Memory List cleared\n\n");
}

int main() {
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);
    display(L);

    printf("After inserting 4 at position 2:\n");
    insertPos(L, 4, 2);
    display(L);

    printf("After deleting position 1:\n");
    deletePos(L, 1);
    display(L);

    printf("Locate 5: %d\n", locate(L, 5));
    printf("Retrieve at pos 2: %d\n", retrieve(L, 2));

    printf("Insert 8 in sorted order:\n");
    insertSorted(L, 8);
    display(L);

    makeNULL(L);
    return 0;
}


