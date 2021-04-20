/*Zachery Abbas 
  1019463
  Assignment 2
  Due: Feb 10
*/
#include <stdio.h>

int brute_force(int array[], int size){
  int i; 
  int j; 
  int inversion;

//implement brute froce algo

  for (i = 0; i < size; i++){
    for (j = i+1; j < size; size++)
      if (array[i]>array[j]){
        inversion++;
      } 
  }
  //return number of inversions 
  return inversion;
}

