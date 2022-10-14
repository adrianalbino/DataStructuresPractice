#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
    int elem;
    struct node *link;
} *List;

typedef List Set[SIZE];

void createList(List *listptr);
void insertList(int num, List *listptr);
void displayList(List list);
Set *createSet(List list);
void initialiseD(Set D);
void displaySet(Set *setptr);

int main()
{
    List list = NULL;

    createList(&list);
    insertList(16, &list);
    insertList(120, &list);
    insertList(45, &list);
    insertList(30, &list);
    insertList(45, &list);
    insertList(30, &list);
    insertList(79, &list);
    insertList(0, &list);
    insertList(199, &list);
    insertList(41, &list);
    insertList(111, &list);
    insertList(96, &list);
    insertList(16, &list);
    insertList(32, &list);
    insertList(79, &list);
    insertList(5, &list);
    insertList(193, &list);
    insertList(903, &list);
    insertList(87, &list);
    insertList(7, &list);
    insertList(33, &list);
    insertList(573, &list);
    insertList(33, &list);
    insertList(111, &list);
    insertList(0, &list);
    insertList(28, &list);
    insertList(10498, &list);
    displayList(list);

    Set *setptr = createSet(list);

    displaySet(setptr);

    return 0;
}

void createList(List *listptr)
{
    *listptr = NULL;
}

void insertList(int num, List *listptr)
{
    List temp = (List)malloc(sizeof(struct node));

    temp->elem = num;
    temp->link = *listptr;
    *listptr = temp;
}

void displayList(List list)
{
    printf("\n");
    for ( ; list != NULL; list = list->link){
        printf("%d ", list->elem);
    }
    printf("\n");
}

Set *createSet(List L)
{
	Set *new = (Set *)malloc(sizeof(Set));

	if (new != NULL){
		initialiseD(*new);
		int ones;

		for ( ; L != NULL; L = L->link){
			ones = L->elem%10;
			List *trav, temp;

			for (trav = (*new)+ones; *trav != NULL && L->elem > (*trav)->elem; trav = &(*trav)->link){}
			if (*trav == NULL || L->elem != (*trav)->elem){
                temp = (List)malloc(sizeof(struct node));
				if (temp != NULL){
					temp->elem = L->elem;
					temp->link = *trav;
					*trav = temp;	
				}	
            } 
        }
	}

	return new;
}

void initialiseD(Set D)
{
	int idx;

	for (idx = 0; idx < SIZE; idx++){
		D[idx] = NULL;
	}
}

void displaySet(Set *setptr)
{
    int idx;
    List trav;

    for (idx = 0; idx < SIZE; idx++){
        printf("(*setptr)[%d] = ", idx);
        for (trav = (*setptr)[idx]; trav != NULL; trav = trav->link){
            printf("%d ", trav->elem);
        }
        printf("\n");
    }
}