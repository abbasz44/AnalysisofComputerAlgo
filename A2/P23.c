/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 52
int table1[MAX];
int table2[MAX];

void suffix(char *need, int buf, int *suf){
//declated variables 
  int i; 
  int j; 
  int k = 0; 
//set varibales   
  suf[buf-1] = buf;
  j = buf -1;

//create a for loop with if and elses with the constraints needed for the suffix function 
  for(i = buf-2; i>= 0; --i){
    if (suf[i + buf - 1 - k] < i - j && i > j)
            suf[i] = suf[i + buf - 1 - k];
        else{
            if (i < j){
                j = i;
                i = k;
            }
//loop has two constraints
            while (need[j] == need[j + buf - 1 - k] && j >= 0)
                --j;
            suf[i] = k - j;
        }
    }
}
void charTable(char *need){
//declare variables 
  int i; 
  int j; 
  int len = strlen(need);

//create loop when j is less than the max
  for(j = 0; j < MAX; j++){
    table1[j] = len;
  }
//create loop that is less than len - 1 
  for(i = 0;i < len -1; i++){
    if (need[i] >= 'A' && need[i] <= 'Z')
      table1[(int)need[i] - 65] = len - i - 1;
    else if (need[i] >= 'a' && need[i] <= 'z')
      table1[(int)need[i] - 97] = len - i - 1;
  }
//this algorithm is the same one that was used for P21.c
}
void suffixTable(char *need){
  int i; 
  int j; 
  int suf[60];
  int len = strlen(need);

  suffix(need, len, suf);
  
      for (i = 0; i < len; ++i){
        table1[i] = len;
    }

    j = 0;
    for (i = len - 1; i >= 0; --i){
      if (suf[i] == i + 1){
            for (j = 0; j < len - 1 - i; ++j){
                if (table1[j] == len)
                    table1[j] = len - 1 - i;
            }
        }
    }
    for (i = 0; i <= len - 2; ++i){
      table1[len - 1 - suf[i]] = len - 1 - i;
    }
}
int algoBm(char *need, char *hay){
//declare variables
  int i = 0; 
  int j = 0;
  int len1 = strlen(hay); 
  int len2 = strlen(need); 
  int counter; 
  int shifter; 

//use above function helpers 
  charTable(need);
  suffixTable(need);

//create loop with the constraint bellow
  while (j <= len1 - len2){
        for (i = len2 - 1; need[i] == hay[i + j] && i >= 0; --i);
        if (i < 0){
            shifter++;
            j += table1[0];
            counter++;
        }
        
    }
  printf("The amount of Boyer-Moore Matches that are found: %d\n", counter);
  return shifter;
}
/*the fucntion above doesnt work completly for some reason I got a seg fault and my logic was off*/  