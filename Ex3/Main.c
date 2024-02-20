#include <stdio.h>
#include "StrList.h"

int main(){

int user;
scanf("%d",&user);
StrList* myList= StrList_alloc();

while (user!=0){
    int len_words;
if(user==1){
    int word_size=100;
   char *word= (char*)(malloc)(word_size*sizeof(char));
    scanf("%d",&len_words);
    char ch;
    int j=0;
    int counter=0;
    while(counter!=len_words){
      scanf(" %c", &ch);
     while(ch!='\n' && ch!=EOF){
      while(j>=word_size){
        word_size*=2; 
        word=(char*)realloc(word,word_size*sizeof(char));
      }
          if(ch==' '){break;}
          word[j++]=ch;
          }
        word[j]='\0';
        StrList_insertLast(myList,word);
        counter++;
          }
          break;
        }
      
     if(user==2){
        int index;
        char* word = (char*)malloc(sizeof(char) * 50);
        scanf("%d",&index);
        scanf("%s\n",word);
        StrList_insertAt(myList,word,index);
     } 

     if(user==3){
        int size=StrList_size(myList);
          printf("%d",size);
     }

     if(user==4){
      int len=StrList_printLen(myList);
      printf(" %d",len);
     }

     if(user==5){
      int index; scanf("%d",&index);
      StrList_printAt(myList,index);
     }

     if(user==6){
       StrList_printLen(myList);
     }

     if(user==7){
      char* word = (char*)malloc(sizeof(char) * 50);
       scanf("%s\n",word);
      int repeat=StrList_count(myList,word);
      printf("%d",repeat);
     }

     if(user==8){
      char* word = (char*)malloc(sizeof(char) * 50);
      scanf("%s\n",word);
      StrList_remove(myList,word);
     }

     if(user==9){
       int index; scanf("%d",&index);
       StrList_removeAt(myList,index);
     }

     if(user==10){
      StrList_reverse(myList);
     }

     if(user==11){
      StrList_free(myList);
     }

     if(user==12){
      StrList_sort(myList);
     }

     if(user==13){
      StrList_isSorted(myList);
     }
     scanf("%d",&user);
  }
  return 0;  
}









