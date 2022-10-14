#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int SET[MAX];

SET *initialize();
void display(SET A);
void insert(SET *A, int x);
void populateA(SET *A);
void populateB(SET *B);
void populateZ(SET *Z);
int member(SET *A, int x);
int subset(SET A, SET Z);
SET *unionset(SET A, SET B);
SET *intersection(SET A, SET B);
SET *difference(SET A, SET B);

SET *initialize() {
   SET *A = (SET *)malloc(sizeof(SET));
   return A; 
}

void display(SET A) {
    int x;
    printf("[");
    for (x = 0; x < MAX; x++) {
        printf("%d", A[x]);
    }
    printf("]");
}

void insert(SET *A, int x) {
    if ((*A)[x] == 1) {
        printf("This integer already exists on the list.");
    } else {
        (*A)[x] = 1;
    }
}

void populateA(SET *A) {
    int x;
    for (x = 0; x < MAX - 2; x++) {
        (*A)[x] = 1;
    }
}

void populateB(SET *B) {
    int x;
    for (x = 0; x < MAX - 4; x++) {
        (*B)[x] = 1;
    }
    (*B)[9] = 1;
}

void populateZ(SET *Z) {
    (*Z)[0] = 1;
}

int member(SET *A, int x) {
    return ((*A)[x] == 1) ? 1:0;
}

int subset(SET A, SET Z) {
    int x;
    for (x = 0; x < MAX; x++) {
        if (Z[x] != A[x])
            return 0;
    }
    return 1;
}

SET *unionset(SET A, SET B) {
    int x;
    SET *C = initialize();
    if (C != NULL) {
        for (x = 0; x < MAX; x++) {
            (*C)[x] = (A[x] == 1 || B[x] == 1) ? 1:0;
        }
    }
    return C;
}

SET *intersection(SET A, SET B) {
    SET *D = initialize();
    int x;
    for (x = 0; x < MAX; x++) {
        (*D)[x] = (A[x] == 1 && B[x] == 1) ? 1:0;
    }
    return D;
}

SET *difference(SET A, SET B) {
    SET *E = initialize();
    int x;
    for (x = 0; x < MAX; x++) {
        (*E)[x] = (A[x] == 1 && B[x] == 0) ? 1:0;
    }
    return E;
}
int main() {
    SET *A = initialize();
    SET *B = initialize();
    SET *Z = initialize();
    populateZ(Z);
    printf("Printing Set A: \n");
    display(*A);
    printf("\nPrinting Set B: \n");
    display(*B);
    insert(A, 3);
    printf("\nPrinting Set A: \n");
    display(*A);
    populateA(A);
    printf("\nPrinting Set A: \n");
    display(*A);
    populateB(B);
    printf("\nPrinting Set B: \n");
    display(*B);
    printf("\nMember?: %d\n", member(A, 3));
    SET *C = unionset(*A, *B);
    printf("Union:\n");
    display(*C);
    SET *D = intersection(*A, *B);
    printf("\nIntersection:\n");
    display(*D);
    SET *E = difference(*A, *B);
    printf("\nDifference:\n");
    display(*E);
    printf("\nIs it a subset?: %d", subset(*A, *Z));
    return 0;
}




