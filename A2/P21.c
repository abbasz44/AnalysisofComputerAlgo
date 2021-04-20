/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchBrute(char *need, char *hay){

 int i; 
 int j; 
 int matcher = 0;
 int len1 = strlen(need);
 int len2 = strlen(hay);
 

for (i = 0; i < len2 - len1; i++){
        for (j = 0; j < len1; j++){
            if (hay[i + j] != need[j]){
                break;
        }
      }
        if (j == len1){
            matcher++;
    }

}
   printf("The Bruteforce matches found in the file is: %d\n", matcher);

    return i;
}