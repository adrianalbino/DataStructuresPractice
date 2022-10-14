#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char data;
    int link;
}Nodes;

typedef struct {
    Nodes myNodes[MAX];
    int avail;
}VH;

typedef int List;

void initialize(VH *heap);
void populate(VH *heap);
int allocSpace(VH *heap);
void initialize(VH *heap) {
    int x; 
    heap->avail = MAX - 1;
    for (x = 0; x < MAX; x++) {
        heap->myNodes[x].link = x - 1;
    }
}

int allocSpace(VH *heap) {
    int freeindex;
    if (heap->avail == -1) {
        return -1;
    } else {
        freeindex = heap->avail;
        heap->avail = heap->myNodes[freeindex].link;
        return freeindex;
    }
}

void populate(VH *heap) {
    int x;
    int y = 0;
    while (heap->avail != -1) {
        y += 2;
        x = allocSpace(heap);
        heap->myNodes[x].data = y;
    }
}

int main() {
    VH *heap, VirtualHeap;
    heap = &VirtualHeap;
    initialize(heap);
    populate(heap);
    return 0;
}