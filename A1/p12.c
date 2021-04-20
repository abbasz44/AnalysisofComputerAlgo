/*Zachery Abbas 
  1019463
  Assignment 2
  Due: Feb 10
*/
#include <stdio.h>

//this function is to merge it needs the array (data_1) needs the starter, ender and the middle to be able to sort the array
int merge(int array[], int starter, int middle, int ender)
{
//declare variables up top 
    int inversion = 0;
    int left = 0;
    int midr;
    int right;
    int buf =0;
    int temp[ender - starter + 1];
    
//set the midr left and right
    
    left = starter;
    midr = (starter + ender) / 2;
    right = midr + 1;
    
      
//create the loop too sperate the array 
    while (left <= midr && right <= ender)
    {
        if(array[left] <= array[right])
        {
            temp[buf] = array[left];
            left++;
            buf++;
        }
        else
        {
            temp[buf] = array[right];
            right++;
            buf++;

            inversion += midr - left + 1;
        }
    }
//get right 
      while (right < ender + 1)
    {
        temp[buf] = array[right];
        right++;
        buf++;
    } 
//get left 
    while (left < midr + 1)
    {
        temp[buf] = array[left];
        left++;
        buf++;
    }
    

    for(int i = 0; i < (ender - starter + 1); i++)
    {
        array[starter + i] = temp[i];
    }

//return inversions 
    return inversion;
}

int mergeSort(int array[], int start, int end) {
    if (start >= end) return 0;

    int inversion = 0;

    int middle = (end + start) / 2;
    
//call mergesort and merge recursivley
    inversion += merge(array, start, middle, end);
    inversion += mergeSort(array, start, middle);
    inversion += mergeSort(array, middle + 1, end);

    return inversion;
}

