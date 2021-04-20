/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void brute(char *searcher, char **searcherArr){
//declare varibales 
  int sign[10] = {0};
  int search[10]={0};
  int counter = 0;
  int i; 
  int j; 

  for (j = 0; j < 30000; j++)
    {
        if (strcmp(searcher, searcherArr[j]) != 0) {
            for (i = 0; i < strlen(searcherArr[j]); i++){
              switch (searcherArr[j][i]){
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

            if( sign[9] == search[9] && sign[8] == search[8] && sign[7] == search[7]  && sign[6] == search[6] && sign[5] == search[5] && sign[4] == search[4] && sign[3] == search[3] && sign[2] == search[2] && sign[1] == search[1] && sign[0] == search[0]){
              counter++;
              printf("count : %d: %s\n", counter, searcherArr[j]);
            } 

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
  for (i = 0; i < strlen(searcher); i++) {
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