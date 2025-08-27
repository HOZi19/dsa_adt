


#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;


List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int pos) {
    if (pos <= L.count && L.count < MAX) {
        int i;
        for (i = L.count; i > pos; i--) {
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[pos] = data;
        L.count++;
    }
    return L;
}


List deletePos(List L, int pos) {
    if (pos < L.count) {
        int i;
        for (i = pos; i < L.count - 1; i++) {
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}


int locate(List L, int data) {
    int i;
    for (i = 0; i < L.count; i++) {
        if (L.elem[i] == data) return i;
    }
    return -1;
}


List insertSorted(List L, int data) {
    if (L.count < MAX) {
        int i = L.count - 1;
        while (i >= 0 && L.elem[i] > data) {
            L.elem[i + 1] = L.elem[i];
            i--;
        }
        L.elem[i + 1] = data;
        L.count++;
    }
    return L;
}

void display(List L) {
    int i;
    for (i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main() {
    List L;
    int pos;

    L = initialize(L);

    
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 2);
    printf("After insertions: ");
    display(L);

    
    L = deletePos(L, 1);
    printf("After deleting position 1: ");
    display(L);

    pos = locate(L, 30);
    if (pos != -1)
        printf("Element 30 found at position %d\n", pos);

    L = insertSorted(L, 25);
    L = insertSorted(L, 5);
    printf("After insertSorted operations: ");
    display(L);

    return 0;
}


