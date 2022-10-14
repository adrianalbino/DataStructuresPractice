#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}*LinkList;

void initialize(LinkList *L);
void display(LinkList L);
void populate(LinkList *L);
void populateB(LinkList *L);
void insert(LinkList *L, int x);
void delete(LinkList *L, int x);
int member(LinkList L, int x);
int subset(LinkList A, LinkList B);
LinkList unionset(LinkList A, LinkList B);
LinkList intersection(LinkList A, LinkList B);
LinkList difference(LinkList A, LinkList B);

void initialize(LinkList *L) {
    *L = NULL;
}

void display(LinkList L) {
    LinkList trav;
    for (trav = L; trav != NULL; trav = trav->link) {
        printf("%d", trav->data);
    }
    printf("\n");
}

void populate(LinkList *L) {
    *L = (LinkList)malloc(sizeof(struct node));
    (*L)->data = 2;
    (*L)->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->data = 4;
    (*L)->link->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->link->data = 6;
    (*L)->link->link->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->link->link->data = 8;
    (*L)->link->link->link->link = NULL;
}

void populateB(LinkList *L) {
    *L = (LinkList)malloc(sizeof(struct node));
    (*L)->data = 3;
    (*L)->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->data = 6;
    (*L)->link->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->link->data = 8;
    (*L)->link->link->link = (LinkList)malloc(sizeof(struct node));
    (*L)->link->link->link->data = 9;
    (*L)->link->link->link->link = NULL;
}

void insert(LinkList *L, int x) {
    LinkList *trav;
    LinkList temp;
    temp = (LinkList)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->data = x;
        for (trav = L; *trav != NULL && (*trav)->data < x; trav = &(*trav)->link){}
            if(*L == NULL) {
                *L = temp;
            }
            else if(x < (*trav)->data) {
                temp->link = *trav;
                *trav = temp;
            } else {
                printf("This element already belongs in the list.");
            }
    }
}

int member(LinkList L, int x) {
    LinkList trav;
    for (trav = L; trav != NULL && trav->data != x; trav = trav->link) {}
    return (trav == NULL) ? 0:1;
}

void delete(LinkList *L, int x) {
    LinkList *trav, temp;
    for (trav = L; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}
    if ((*trav)->data == x) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

LinkList unionset(LinkList A, LinkList B) {
    LinkList C;
    C = NULL;
    LinkList *cptr;
    cptr = &C;
    LinkList aptr = A;
    LinkList bptr = B;
    if (A != NULL && B != NULL) {
        while (aptr != NULL && bptr != NULL) {
            *cptr = (LinkList)malloc(sizeof(struct node));
            if (aptr->data < bptr->data) {
                (*cptr)->data = aptr->data;
                aptr = aptr->link;
            } else if (aptr->data > bptr->data) {
                (*cptr)->data = bptr->data;
                bptr = bptr->link;
            } else {
                (*cptr)->data = bptr->data;
                aptr = aptr->link;
                bptr = bptr->link;
            }
            cptr = &(*cptr)->link;
        }
        if (aptr != NULL) {
            while(aptr != NULL) {
                *cptr = (LinkList)malloc(sizeof(struct node));
                (*cptr)->data = aptr->data;
                aptr = aptr->link;
                cptr = &(*cptr)->link;
            }
        } else if(bptr != NULL) {
            while(bptr != NULL) {
                *cptr = (LinkList)malloc(sizeof(struct node));
                (*cptr)->data = bptr->data;
                bptr = bptr->link;
                cptr = &(*cptr)->link;
            }
        }
    }
    *cptr = NULL;
    return C;
}

LinkList intersection(LinkList A, LinkList B) {
    LinkList C, *cptr, aptr, bptr;
    C = NULL;
    aptr = A;
    cptr = &C;
    while(aptr != NULL) {
        for(bptr = B; bptr != NULL && aptr->data != bptr->data; ) {
            bptr = bptr->link;
        }
        if (bptr == NULL) {
            aptr = aptr->link;
        } else {
            *cptr = (LinkList)malloc(sizeof(struct node));
            (*cptr)->data = aptr->data;
            aptr = aptr->link;
            cptr = &(*cptr)->link;
        }
    }
    *cptr = NULL;
    return C;
}

LinkList difference(LinkList A, LinkList B) {
    LinkList C, *cptr, aptr, bptr;
    C = NULL;
    cptr = &C;
    aptr = A;
    while (aptr != NULL) {
        for (bptr = B; bptr != NULL && aptr->data != bptr->data; ) {
            bptr = bptr->link;
        }
        if (bptr == NULL) {
            *cptr = (LinkList)malloc(sizeof(struct node));
            (*cptr)->data = aptr->data;
            aptr = aptr->link;
            cptr = &(*cptr)->link;
        } else {
            aptr = aptr->link;
        }
    }
    *cptr = NULL;
    return C;
}

int subset(LinkList A, LinkList B) {
    LinkList aptr, bptr;
    aptr = A;
    while(aptr != NULL) {
        for (bptr = B; bptr != NULL && bptr->data != aptr->data; ) {
            bptr = bptr->link;
        }
        if (bptr == NULL) {
            return 0;
        } else {
            aptr = aptr->link;
        }
    }
    return 1;
}
int main() {
    LinkList A;
    LinkList B;
    initialize(&B);
    populateB(&B);
    initialize(&A);
    populate(&A);
    display(A);
    insert(&A, 3);
    display(A);
    printf("Member(3): %d\n", member(A, 3));
    delete(&A, 3);
    display(A);
    printf("------------------------\n");
    printf("Set A: ");
    display(A);
    printf("Set B: ");
    display(B);
    LinkList C = unionset(A, B);
    printf("Union set: ");
    display(C);
    LinkList D = intersection(A, B);
    printf("Intersection set: ");
    display(D);
    LinkList E = difference(A, B);
    printf("Difference set: ");
    display(E);
    printf("Subset?: %d", subset(A, B));
    return 0;
}

