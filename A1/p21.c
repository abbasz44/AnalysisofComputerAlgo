/*Zachery Abbas 
  1019463
  Assignment 2
  Due: Feb 10
*/
#include <stdio.h>

int brutehull(int array2[], int size2){
    int i; 
    int j; 
    int k; 
    int hull; 

    for(i = 0; i < size2; i++){
        for(j = 0; array2[j] != array2[i]; j++){
            for(k = 0; k<size2; k++){
                if(array2[k] != array2[i] && array2[k] != array2[j]){
                    hull++;
                }
            }
        }
    }

    return hull;

}


