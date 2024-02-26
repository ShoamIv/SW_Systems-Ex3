#include <stdio.h>
#include "StrList.h"
#include <ctype.h>
/**
 * The function that responsible to scan and allocate space for a single word.
 * each word that the function return added to the List.
 * This function will reallocate space for each character.
 * @return
 */

char* scan_word()
{
    char* word = NULL;
    int word_size = 0;
    char ch;
    do{
    }while (scanf("%c", &ch) == 1 && isspace(ch));
    
        while (!isspace(ch)){
        char* temp = realloc(word, (word_size + 1) * sizeof(char));
        if(temp==NULL){
            free(word);return NULL;
        }
        word=temp;
        word[word_size++] = ch;
        if (scanf("%c", &ch) != 1)
        {
            break;
            }
        }
    char* temp = realloc(word, (word_size + 1) * sizeof(char));
    if(temp==NULL){
        free(word);return NULL;
    }
    word=temp;
    word[word_size] = '\0';
    return word;
}
/**
 * The main function that responsible for our "menu".
 * in order to shut down press 0.
 * customize each digit to the required action.
 * @return
 */
int main()
{
    StrList* myList= StrList_alloc();
    int user;
    scanf( "%d", &user);
    while (user != 0)
    {
        if(user == 1)
        {
            int user_input;
            scanf( "%d", &user_input);
            for(int i = 0; i < user_input; i++)
            {
                char* word = scan_word();
                StrList_insertLast(myList ,word);
            }
        }

     if(user==2){
        int index;
        char* word ;
        scanf(  "%d",&index);
        word = scan_word();
        StrList_insertAt(myList,word,index);
     }

     if(user==3){
       StrList_print(myList);
     }

     if(user==4){
         int s= StrList_size(myList);
      printf("%d\n", s);
     }

     if(user==5){
      int index; scanf("%d",&index);
      StrList_printAt(myList,index);
     }

     if(user==6){
       int len=StrList_printLen(myList);
       printf("%d\n",len);
     }

     if(user==7){
      char* word;
      word=scan_word();
      int repeat=StrList_count(myList,word);
      printf("%d\n",repeat);
     }

     if(user==8){
         char* word;
         word=scan_word();
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
        while(StrList_size(myList)>0){
            StrList_removeAt(myList, StrList_size(myList)-1);
        }
     }

     if(user==12){
      StrList_sort(myList);
     }

     if(user==13){
      int b=StrList_isSorted(myList);
      if(b==0){printf("false\n");}else{
              printf("true\n");
          }
        }
     scanf("%d",&user);
  }
    StrList_free(myList);
  return 0;
}