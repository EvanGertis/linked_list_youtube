#include "stdlib.h"
#include "stdio.h"

struct node {
    int info;
    struct node *link;
};

struct node *createList(struct node *start);
struct node *insertInBeginning(int info, struct node *start);
struct node *insertAfter(int info, struct node *start);
void showList(struct node *start);

int main(){

    struct node *start;
    start = (struct node *)malloc(sizeof(struct node));
    start = NULL;

    start = createList(start);
    showList(start);

    return 0;
}

struct node *createList(struct node *start){
    int info, n;

    printf("Please enter the number of elements that you would like to insert: \n");
    scanf("%d", &n);

    printf("Enter the info for the first node\n");
    scanf("%d", &info);
    start = insertInBeginning(info, start);

    for(int i = 1; i < n; i++){
        printf("Please enter the info for node %d\n", i+1);
        scanf("%d", &info);
        start = insertAfter(info, start);
    }

    return start;

}

struct node *insertInBeginning(int info, struct node *start){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;

    temp->link = start;
    start = temp;

    return start;
}

struct node *insertAfter(int info, struct node *start){
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;

    p = start;
    while(p->link != NULL){
        p = p->link;
    }

    p->link = temp;
    temp->link = NULL;

    return start;
}

void showList(struct node *start){
    struct node *p;

    if(start == NULL){
        printf("the list is empty");
        return;
    }

    p = start;
    while(p != NULL){
        printf("%d | ", p->info);
        p = p->link;
    }
}



