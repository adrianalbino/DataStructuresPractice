#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    struct node *link;
}*List;

typedef List Dictionary[MAX];

int hash(int x);
void initialize(Dictionary S);
void display(Dictionary S);
void insert(Dictionary S, int num);
void delete(Dictionary S, int x);
int member(Dictionary S, int x);

void initialize(Dictionary S) {
    int x;
    for (x = 0; x < MAX; x++) {
        S[x] = NULL;
    }
}

void display(Dictionary S) {
    int x;
    List ptr;
    for (x = 0; x < MAX; x++) {
        printf("%d : ", x);
        for (ptr = S[x]; ptr != NULL; ptr = ptr->link) {
            printf("%5d", ptr->data);
        }
        printf("\n");
    }
}
void insert(Dictionary S, int num) {
    List *ptr;;
    int place = hash(num);
    for (ptr = &(S[place]); *ptr != NULL; ptr = &(*ptr)->link){}
        *ptr = (List)malloc(sizeof(struct node));
        (*ptr)->data = num;
        (*ptr)->link = NULL;
}

void populate(Dictionary S) {
    insert(S, 3);
    insert(S, 63);
    insert(S, 33);
    insert(S, 19);
    insert(S, 9);
    insert(S, 99);
    insert(S, 22);
    insert(S, 15);
    insert(S, 71);
    insert(S, 31);
    insert(S, 44);
    insert(S, 36);
    insert(S, 58);
    insert(S, 20);
    insert(S, 47);
}

int member(Dictionary S, int x) {
    int place = hash(x);
    List ptr;
    for (ptr = S[place]; ptr != NULL && ptr->data != x; ptr = ptr->link) {}
    return (ptr == NULL) ? 0:1;
}

void delete(Dictionary S, int x) {
    int test = member(S, x);
    List temp, *trav;
    if (test == 1) {
        int place = hash(x);
        for (trav = &S[place]; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link){}
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    } else {
        printf("\nThis element does not exist in the list.");
    }
}
int hash(int x) {
    return (x % 10);
}
int main() {
    Dictionary S;
    initialize(S);
    populate(S);
    display(S);
    delete(S, 99);
    delete(S, 71);
    printf("---------------\n");
    display(S);
    return 0;
}