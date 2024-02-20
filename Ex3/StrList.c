#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"
typedef struct _node {
char * w;
struct _node * _next;
}Node;

typedef struct _StrList{
    Node* _head;
    size_t _size;
}StrList;


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

Node* last_node= Node_alloc(strdup(data),NULL);
if ((!last_node))
{
    return;    
}

Node* p= StrList->_head;
if(!StrList->_head){
    StrList->_head=last_node;
}
while(p->_next!=NULL){
    p=p->_next;
    }
    p->_next=last_node;
}
char* StrList_firstData(const StrList* StrList){
return StrList->_head->w;
}
void StrList_print(const StrList* StrList){
    Node* p=StrList->_head;
    while(p!=NULL){
    printf("%s\n",p->w);
        p=p->_next;
    }   
}
void StrList_printAt(const StrList* Strlist,int index){
    if(index>Strlist->_size)return;
    Node* p=Strlist->_head;
    int i=0;
    while(i!=index-1){
        p=p->_next;i++;
    }
    printf("%s\n",p->w);
}
int StrList_printLen(const StrList* Strlist){
    int len=0;
    Node* p=Strlist->_head;
    for(int i=0; i<Strlist->_size; i++){
      len+=strlen(p->w);   
    }
    return len;
}
int StrList_count(StrList* StrList, const char* data){
      int count=0;
    Node* p= StrList->_head;
    for(int i=0; i<StrList->_size; i++){
      if(strcmp(p->w,data)==0){count++;}
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
                free(p);StrList->_size--;return;    
        }
        prev=p;
        p=p->_next;
    }
}
void StrList_removeAt(StrList* StrList, int index){
 if(index>StrList->_size)return;
 Node* p= StrList->_head;
 Node* prev=NULL;
 for(int i=0; i<index; i++){
   if(i==index){
     if(prev==NULL){
        StrList->_head =p->_next;
    }else{
    prev->_next=p->_next;
    free(p);
        }
   }
   prev=p;
   p=p->_next;
 }  
}
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
Node* p1= StrList1->_head;
Node* p2= StrList2->_head;
while(p1){
    if(p2==NULL || p1->w!=p2->w)return 0;
   p1=p1->_next;
   p2=p2->_next;
}
if(p2==NULL)return 0;
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
void StrList_sort( StrList* StrList){
    Node* curr=StrList->_head;
    Node* comp=StrList->_head;
    Node* temp=NULL;
 for(int i=0; i<StrList->_size; i++){
    for(int j=0; j<StrList->_size; j++){
        if(strcmp(curr->w,comp->w)<0){
        temp=comp;
        comp=curr;
        curr=temp;
   }
  }
 }
}
int StrList_isSorted(StrList* StrList){
 Node* curr=StrList->_head;
    Node* comp=StrList->_head;
 for(int i=0; i<StrList->_size; i++){
    for(int j=0; j<StrList->_size; j++){
        if(strcmp(curr->w,comp->w)>0){
         return 0;
     }
    }
  }
  return 1;
}


