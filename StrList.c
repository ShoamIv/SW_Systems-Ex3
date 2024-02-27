#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"
/**
 * Execute StrList.h as required.
 */

typedef struct node {
    char* w;
    struct node* _next;
}Node;

struct _StrList{
    Node* _head;
    size_t _size;
};


StrList* StrList_alloc(){
    StrList* p =(StrList*)malloc(sizeof(StrList));
    p->_head=NULL;
    p->_size=0;
    return p;
}
Node* Node_alloc(char* data,Node* next) {
    Node* p= (Node*)malloc(sizeof(Node));
    p->w= data;
    p->_next= next;
    return p;
}
void Node_free(Node* node) {
    free(node);
}
void StrList_free(StrList* StrList){
    if(StrList==NULL)return;
    Node* p1= StrList->_head;
    Node* p2;
    while(p1) {
        p2= p1;
        p1= p1->_next;
        Node_free(p2);
    }
    free(StrList);
}
size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}
void StrList_insertAt(StrList* StrList,const char* data,int index){
    Node* new = Node_alloc((char*)data,NULL);
    if(index==0){
        new->_next=StrList->_head;
        StrList->_head=new;return;
    }
    Node* p= StrList->_head;

    for(int i=0; i<index-1 && p!=NULL; i++){
        p=p->_next;
    }
    if(p==NULL)return;else{
        new->_next=p->_next;
        p->_next=new;
    }

}
void StrList_insertLast(StrList* StrList,const char* data){
    Node* new = Node_alloc((char*)data,NULL);
    if(StrList->_head==NULL){
        StrList->_head=new;
        StrList->_size++;
    }
    else {
        Node *p = StrList->_head;

        while (p->_next != NULL) {
            p = p->_next;
        }
        p->_next = new;
        StrList->_size++;
    }
}
char* StrList_firstData(const StrList* StrList){
    return StrList->_head->w;
}
void StrList_print(const StrList* StrList){
    Node* p=StrList->_head;
    while(p!=NULL){
        if(p->_next!=NULL){
            printf("%s ",p->w);
        }else{
            printf("%s",p->w);
        }
        p=p->_next;
    }

    printf("\n");
}
void StrList_printAt(const StrList* Strlist,int index){
    if(index>Strlist->_size)return;
    Node* p=Strlist->_head;
    for(int i=0; i<index; i++){
        p=p->_next;
    }
    printf("%s\n",p->w);
}
int StrList_printLen(const StrList* Strlist){
    int len=0;
    Node* p=Strlist->_head;
    while(p!=NULL){
        int word_len = strlen(p->w);
        len+=word_len;
        p=p->_next;
    }
    return len;
}
int StrList_count(StrList* StrList, const char* data){
    int count=0;
    Node* p= StrList->_head;
    if(p!=NULL){
        for(int i=0; i<StrList->_size; i++) {
            if (strcmp(p->w, data) == 0) { count++; }
            p = p->_next;
        }
    }
    return count;

}
void StrList_remove(StrList* StrList, const char* data){
    Node* p= StrList->_head;
    Node* prev = NULL;
    while(p!=NULL){
        if(strcmp(p->w,data)==0){
            if(prev==NULL){
                StrList->_head =p->_next;
            }else{
                prev->_next=p->_next;
            }
            p=p->_next;
            StrList->_size--;
        }else {
            prev = p;
            p = p->_next;
        }
    }
}
void StrList_removeAt(StrList* StrList, int index){
    if(index>StrList->_size)return;
    Node* p= StrList->_head;
    Node* prev=NULL;
    for(int i=0; i< StrList->_size; i++){

        if(i==index){
            if(prev==NULL){
                StrList->_head =p->_next;
                StrList->_size--;
                return;
            }else{
                prev->_next=p->_next;
                free(p);
                StrList->_size--;
                return;
            }
        }
        prev=p;
        p=p->_next;
    }
}
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->_size!=StrList2->_size)return 0;
     Node* p1= StrList1->_head;
     Node* p2= StrList2->_head;
    while(p1){
        if(strcmp(p1->w,p2->w)!=0)return 0;
        p1=p1->_next;
        p2=p2->_next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList){
    if(!StrList->_head || !StrList){
        return NULL;
    }
    struct _StrList* clone =(struct _StrList*) StrList_alloc();
    Node* self= StrList->_head;
    while(self){
        char* data= strdup(self->w);
        StrList_insertLast(clone,data);
        self=self->_next;
    }
    return clone;
}
void StrList_reverse( StrList* StrList){
    Node* current = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }
    StrList->_head = prev;
}
/**
 * Simple bubble sort in order to sort the list in lexicographic order.
 */
void StrList_sort( StrList* StrList){
    if(StrList ==NULL || StrList->_size<=1){return;}
    Node* curr=StrList->_head;
    while(curr!=NULL){
        Node* curr_in=StrList->_head;
        while(curr_in->_next!=NULL){
            if (strcmp(curr_in->w, curr_in->_next->w) > 0) {
                char* tmp=curr_in->w;
                curr_in->w=curr_in->_next->w;
                curr_in->_next->w=tmp;
            }
            curr_in=curr_in->_next;
        }
        curr=curr->_next;
    }
}
/*
checks if the list sorted.
*/
int StrList_isSorted(StrList* StrList){
    Node* curr=StrList->_head;
    while(curr->_next!=NULL){
        if(strcmp(curr->w, curr->_next->w) > 0){
            return 0;
        }
        curr=curr->_next;
    }
    return 1;
}