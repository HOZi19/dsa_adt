	#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L) {
    L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List resize(List L) {
    int newMax = L.max * 2;
    int *newElem = (int *)malloc(newMax * sizeof(int));
    int i;
    for (i = 0; i < L.count; i++) {
        newElem[i] = L.elemPtr[i];
    }
    free(L.elemPtr);
    L.elemPtr = newElem;
    L.max = newMax;
    return L;
}

List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count) {
        printf("Invalid position!\n");
        return L;
    }
    if (L.count == L.max) {
        L = resize(L);
    }
    int i;
    for (i = L.count; i > position; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position!\n");
        return L;
    }
    int i;
    for (i = position; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data) {
	int i;
    for (i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count == L.max) {
        L = resize(L);
    }
    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data) {
        pos++;
    }
    L = insertPos(L, data, pos);
    return L;
}

void display(List L) {
    printf("List: ");
    int i;
    for (i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\nCount: %d, Max: %d\n", L.count, L.max);
}

int main() {
    List L;
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L);

    L = insertPos(L, 4, 2);
    display(L);

    L = deletePos(L, 1);
    display(L);

    printf("Locate 5: %d\n", locate(L, 5));

    L = insertSorted(L, 8);
    display(L);

    free(L.elemPtr);
    return 0;
}
