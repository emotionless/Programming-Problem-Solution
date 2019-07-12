#include <stdio.h>
#include <stdlib.h>


struct node
{
    int val;
    node *nxt;
};

void print(node *n)
{
    if(n == NULL) return;
    printf("%d ", n->val);
    print(n->nxt);

    return;
}

void insert(node* pre, int v)
{
    if((pre -> nxt) == NULL)
    {
        node *new_data = NULL;
        new_data = (struct node*)malloc(sizeof(struct node));

        new_data ->val = v;
        new_data -> nxt = pre -> nxt;
        pre -> nxt = new_data;
    }
    else
    {
        insert(pre->nxt, v);
    }
    return;
}

void deleteNode(node **head, int key)
{
    node *temp = *head, *prev;

    if(temp != NULL && temp -> val == key)
    {
        *head = temp->nxt;
        free(temp);
        return;
    }

    while(temp != NULL && temp -> val != key)
    {
        prev = temp;
        temp = temp->nxt;
    }

    if(temp == NULL) return;

    prev -> nxt = temp -> nxt;

    free(temp);

    return;
}

void insertFront(node **pre, int v)
{
    node *tmp = NULL;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp ->val = v;
    tmp -> nxt = (*pre);
    (*pre) = tmp;
return;
}

int main()
{
    node *fst = NULL;
    node *snd = NULL;
    node *third = NULL;

    fst = (struct node*)malloc(sizeof (struct node));
    snd = (struct node*)malloc(sizeof (struct node));
    third = (struct node*)malloc(sizeof (struct node));

    fst->val = 1;
    fst -> nxt = NULL;

    printf("here\n");

//    snd->val = 2;
//    snd -> nxt = third;
//
//    third->val = 3;
//    third -> nxt = NULL;

    insert(fst, 12);
    insert(fst, 13);
    insert(fst, 14);

    print(fst);

    deleteNode(&fst, 13);

    printf("\n");

    print(fst);

    printf("\n");

    insertFront(&fst, 20);

    print(fst);

    printf("\n");

    deleteNode(&fst, 20);

    print(fst);

    printf("\n");




    return 0;
}

