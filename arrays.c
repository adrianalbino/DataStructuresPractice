#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct array{
    int count;
    int elements[MAX];
} *SET; 

SET initialize();
void display(SET A);
void insert(SET A, int x);
void delete(SET A, int x);
void populate(SET A);
void populateB(SET B);
int member(SET A, int x);
SET unionset(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
int subset(SET A, SET B);

SET initialize() {
    SET A = (SET)malloc(sizeof(struct array));
    A->count = 0;
    return A;
}

void display(SET A) {
    int x;
    printf("[");
    for (x = 0; x < A->count; x++) {
        printf("%d ", A->elements[x]);
    }
    printf("]");
    printf("\nCount is: ");
    printf("%d\n", A->count);
}

void insert(SET A, int x) { // sorted
    int ctr, ctr2;
    int newCount = A->count + 1;
    if (A->count == MAX) {
        printf("This array is already full.");
    } else {
        for (ctr = 0; ctr < A->count && A->count != newCount; ctr++) {
            if (A->elements[ctr] == x) {
                printf("\n%d Already exists in the set.\n", A->elements[ctr]);
                break;
            }
            else if(A->elements[ctr] > x) {
                A->count++;
                for (ctr2 = A->count; ctr2 > ctr; ctr2--) {
                    A->elements[ctr2] = A->elements[ctr2 - 1];
                }
                A->elements[ctr] = x;
        }
    }
    }
}

void populate(SET A) {
    int x, value;
    value = 0;
    for (x = 0; x < MAX-5; x++) {
        A->elements[x] = value;
        value += 3;
        A->count++;
    }
}

void populateB(SET B) {
    int x, value;
    value = 0;
    for (x = 0; x < MAX-5; x++) {
        B->elements[x] = value;
        value += 2;
        B->count++;
    }
}

int member(SET A, int x) {
    int ctr;
    for (ctr = 0; ctr < A->count; ctr++) {
        if(A->elements[ctr] == x) 
            return 1;
    }
    return 0;
}

void delete(SET A, int x) {
    int ctr, ctr2;
    for (ctr = 0; ctr < A->count; ctr++) {
        if (A->elements[ctr] == x) {
            for (ctr2 = ctr; ctr2 < A->count; ctr2++) {
                A->elements[ctr2] = A->elements[ctr2 + 1];
            }
            A->count--;
            break;
        }
    }
}

SET unionset(SET A, SET B) {
    SET C = initialize();
    int ctr, x;
    for (ctr = 0; ctr < A->count; ctr ++) {
        C->elements[ctr] = A->elements[ctr];
        C->count++;
    }
    for (x = 0; x < B->count; x++) {
        insert(C, B->elements[x]);
    }
    return C;
}

SET intersection(SET A, SET B) {
    SET D = initialize();
    int x, y;
    int z = 0;
    for (x = 0; x < A->count; x++){
        for (y = 0; y < B->count; y++) {
            if(A->elements[x] == B->elements[y]) {
                D->elements[z] = A->elements[x];
                z++;
                D->count++;
            }
        }
    }
    return D;
}

int subset(SET A, SET B) {
    int x, y;
    int subsetcount = 0;
    for (x = 0; x < A->count; x++) {
        for (y = 0; y < B->count; y++) {
            if(A->elements[x] == B->elements[y]) {
                subsetcount++;
            }
        }
    }
    return (subsetcount == A->count) ? 1:0;
}

SET difference(SET A, SET B) {
    SET E = initialize();
    int x, y;
    int e = 0;
    for (x = 0; x < A->count; x++) {
        for (y = 0; y < B->count && A->elements[x] != B->elements[y]; y++) {}
        if (A->elements[x] != B->elements[y]) {
            E->elements[e] = A->elements[x];
            e++;
            E->count++;
        } 
    }
    return E;
}
int main() {
    SET A = initialize();
    SET B = initialize();
    populate(A);
    populateB(B);
    display(A);
    display(B);
    insert(A, 4);
    insert(A, 9);
    display(A);
    printf("Member? %d\n", member(A, 2));
    delete(A, 0);
    display(A);
    printf("--------------------------\n");
    printf("Set A:");
    display(A);
    printf("Set B:");
    display(B);
    SET C = unionset(A, B);
    printf("Union Set:");
    display(C);
    printf("Intersection:");
    SET D = intersection(A, B);
    display(D);
    printf("Set Difference:");
    SET E = difference(A, B);
    display(E);
    SET F = initialize();
    SET G = initialize();
    populate(F);
    populate(G);
    printf("Subset: %d", subset(F, G));
    return 0;
}