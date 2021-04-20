/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//create struct
typedef struct anagram{
  char sort[20];
  char orig[20];
}str; 

//fucntion prototypes
void brutepre(char *searcher, str *searcherarr);
void insertionSort1(str *Sort);
char *insertionSort2(char *Sort);

char *insertionSort2(char *Sort){
//declare variables
//malloc space for buffer
  char *buf = malloc(sizeof(char) * 20);
  char check; 
  int i; 
  int j;
//copy sort to buf
  strcpy(buf, Sort);

//constraint has to be less then buf
  for (j = 1; j < strlen(buf); j++){
    check = buf[j]; 
    i = j - 1;

// in for loop while loop with two constraints 
    while((buf[i]) < (check) && i <= 0){
      buf[i + 1] =buf[i]; 
        i = i - 1;
    }
    buf[i + 1] = check;
  } 
//return buf
  return buf;
} 
void insertionSort1(str *Sort){
//declare varibales 
  int i;
  int j; 
  str check; 

//for loop with the constraint 30000 which is about the size of the file
  for(j =1; j<30000; j++){
    Sort[j] = check; 
    i = j -1;

//while loop in the for loop with two constraints  
    while(strcmp(check.sort, Sort[i].sort) < 0 && i >= 0){
      Sort[i + 1] = Sort[i]; 
      i = i -1;

    }
    Sort[i+1] = check;
  }
}
void brutepre(char *searcher, str *searcherArr){
  //declare vatibales
  int sign[10] = {0};
  int search[10]={0};
  int counter = 0;
  int i; 
  int j; 

  for (j = 0; j < 30000; j++)
    {
        if (strcmp(searcher, searcherArr[j].orig) != 0) {
            for (i = 0; i < strlen(searcherArr[j].sort); i++){
  
  //switch cases checking each number 0-9
              switch (searcherArr[j].sort[i]){
                 case '9':
                    sign[9]++;
                    break;
                  case '8':
                    sign[8]++;
                    break;
                  case '7':
                    sign[7]++;
                    break;
                  case '6':
                    sign[6]++;
                    break;
                  case '5':
                    sign[5]++;
                    break;
                  case '4':
                    sign[4]++;
                    break;
                  case '3':
                    sign[3]++;
                    break;
                  case '2':
                    sign[2]++;
                    break;
                  case '1':
                    sign[1]++;
                    break;
                  case '0':
                    sign[0]++;
                    break;

                default: 
                  break;

              }
            }
//checking if all the signs match with the search 
            if( sign[9] == search[9] && sign[8] == search[8] && sign[7] == search[7]  && sign[6] == search[6] && sign[5] == search[5] && sign[4] == search[4] && sign[3] == search[3] && sign[2] == search[2] && sign[1] == search[1] && sign[0] == search[0]){
              counter++;
              //printf("count : %d: %s\n", counter, searcherArr[j].orig);
            } 
//if they don't then it = 0
            sign[9] = 0;
            sign[8] = 0;
            sign[7] = 0;
            sign[6] = 0;
            sign[5] = 0;
            sign[4] = 0;
            sign[3] = 0;
            sign[2] = 0;
            sign[1] = 0;
            sign[0] = 0;
        }
    }
//for loop with the constraint of string length 
    for (i = 0; i < strlen(searcher); i++) {
//switch cases checking each number 0-9
        switch (searcher[i]){
           case '9':
              search[9]++;
              break;
            case '8':
              search[8]++;
              break;
            case '7':
              search[7]++;
              break;
            case '6':
              search[6]++;
              break;
            case '5':
              search[5]++;
              break;
            case '4':
              search[4]++;
              break;
            case '3':
              search[3]++;
              break;
            case '2':
              search[2]++;
              break;
            case '1':
              search[1]++;
              break;
            case '0':
              search[0]++;
              break;
         }
    }
    printf("the total amount of anagrams of %s is %d\n", searcher, counter);
}
void sortPre(char *search, char **searcherArr){
//declare variables 
  clock_t begin;
  clock_t stop;
  int j; 
  int i ; 
//malloc space for the varibale list
  str *list = malloc(sizeof(str) * 30000);
//start clock
    begin = clock();

//do the sorting 
    for(i = 0; i < 3000; i++){
      strcpy(list[i].sort, insertionSort2(searcherArr[i]));
      strcpy(list[i].orig, searcherArr[i]);  
    }
    for (j = 0; j < 30000; j++){
      insertionSort1(list);
    }
 
//stop clock    
    stop = clock(); 
    printf("The Presort runtime for this file is: %f seconds\n\n", ((double)(stop - begin)) / CLOCKS_PER_SEC);

//call the bruteforce and start and stop clock 
    printf("Presort search using bruteforce for question 1.2:\n");
    begin = clock();
    brutepre(search, list);
    stop = clock();
    printf("Presort search runtime for this file: %f seconds\n\n", ((double)(stop - begin)) / CLOCKS_PER_SEC);



}