/*Zachery Abbas 
  1019463
  Assignment 2
  Due: Feb 10
*/
#include <stdio.h>

int qhull(int array2[], int size2){
    int left; 
    int right; 
    int temp[0]; 
    int buf = 0;
    int i; 
    int j;

   
//find left and right 
    for(i = 0; i<size2; i++){
        if(array2[i] < temp[buf]){
            temp[buf] = array2[i];
            
        }
        left++;
       
    }
    

    for(j = 0; j<size2; i++){
        if(array2[i] >temp[buf]){
            temp[buf] = array2[i];
            
        }
        right++;
    } 

    

    return right;
}



