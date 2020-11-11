//
// Created by 15613 on 2020/11/11.
//

#ifndef LINKLIST_BOOK_BOOK_H
#define LINKLIST_BOOK_BOOK_H
#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char name[128];
    char writer[128];
    int price;
    int id;
}book;

typedef struct Node{
    struct Node *next;
    book b;
}linklist;

void InitList(linklist **L) {
    (*L) = (linklist *)malloc(sizeof(linklist));
    (*L)->next = NULL;
}

void CreateList(linklist **L) {
    linklist *q = *L;
    char t;
    int i = 0;
    while (1) {
        linklist *p = (linklist *)malloc(sizeof(linklist));
        printf("book name:");
        gets(p->b.name);
        printf("book price:");
        scanf("%d",&p->b.price);
        getchar();
        printf("book writer:");
        gets(p->b.writer);
        p->b.id = ++i;
        q->next = p;
        q = p;
        printf("continue?");
        scanf("%c",&t);
        getchar();
        if(t=='n'){
            q->next = NULL;
            break;
        }
    }
}

void InsertBook(linklist **L,int pos) {
    linklist *p = (linklist *)malloc(sizeof(linklist));
    printf("book name:");
    gets(p->b.name);
    printf("book price:");
    scanf("%d",&p->b.price);
    getchar();
    printf("book writer:");
    gets(p->b.writer);
    p->b.id = pos;
    linklist *q = *L;
    int i = 0;
    for (i=0;i<pos-1;i++) {
        if (q == NULL) {
            exit(-1);
        }
        if (q->b.id == pos){
            printf("exist,cannot do");
        }
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

void DeleteBook (linklist **L,int pos) {
    int i;
    linklist *q = *L;
    for (i=0;i<pos-1;i++) {
        q = q->next;
    }
    linklist *p = q->next->next;
    q->next = p;
}

void ShowList(linklist **L){
    linklist *p = (*L)->next;
    while(p) {
    	printf("book name:");
    	puts(p->b.name);
    	printf("book price:");
    	printf("%d\n",p->b.price);
    	printf("book writer:");
    	puts(p->b.writer);
    	printf("book id:");
    	printf("%d\n",p->b.id);
    	p=p->next;
	}
}

#endif //LINKLIST_BOOK_BOOK_H
