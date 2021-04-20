/*Zachery Abbas
  1019463
  Assignment 2
  Due: Feb 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int *parse_file(char *filename);
int *parse_file2(char *filename2);
int brute_force(int array[], int size);
int mergeSort(int array[], int starter, int ender);
int merge(int array[], int starter, int middle, int ender);
int brutehull(int array2[], int size2);
int qhull(int array2[], int size2);

//this function will Parse through the file and will return the array[], open the file, close the file, and error handle
int *parse_file(char *filename){

    FILE *fp; 
    int *array; 
    int buf = 0; 
    int i = 0; 
    

//error handeling if the file name = NULL then let user know
    if(filename == NULL){
        printf("file name is incorrect\n"); 
        return NULL;
    } 
//open file
	fp = fopen(filename, "r");

//error handle cannot opening the file
	if (fp == NULL) {
		printf("cannot open file\n");
		fclose(fp);
		return NULL;
	}
//malloc space   
    array = malloc(sizeof(int) * 50000);

    while (fscanf(fp,"%d", &buf)==1) {
        array[i] = buf;
        i++;
    }

    fclose(fp);

    return array;
}
int *parse_file2(char *filename2){

    FILE *fp; 
    int *array2; 
  
    int buf = 0; 
    int i = 0; 
    

//error handeling if the file name = NULL then let user know
    if(filename2 == NULL){
        printf("file name is incorrect\n"); 
        return NULL;
    } 
//open file
	fp = fopen(filename2, "r");

//error handle cannot opening the file
	if (fp == NULL) {
		printf("cannot open file\n");
		fclose(fp);
		return NULL;
	}
//malloc space   
    array2 = malloc(sizeof(int) * 100000);

    while (fscanf(fp,"%d", &buf)==1) {
        array2[i] = buf;
        i++;
    }

    fclose(fp);

    return array2;
}


int main(int argc, char **agrv){
//set up timer  
    clock_t begin;
    clock_t stop;

    int size = 50000;
    int size2 = 100000; 
    int *array = parse_file("data_1.txt");
    int *array2 = parse_file2("data_2.txt");
    int brute;
    int merger;
    int hull;
    //int qsort; 
    int user;

    printf("Press 1 for p11.c and p12.c. Press 2 for p21.c and p22.c\n");
    scanf("%d", &user); 

//user picks for program 1
    if(user == 1){

    brute  = brute_force(array, size);

    begin = clock();
        printf("Inversions for Brute Force: %d\n", brute);
    stop = clock(); 
        printf("Runtime for Brute Force %f seconds\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
        printf("\n");
    merger = mergeSort(array, 0, 49999);

    begin = clock();
        printf("Inversions for Mergesort: %d\n", merger);
    stop = clock();
        printf("Runtime for Mergesort: %f seconds\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
        printf("\n"); 
    }

//user picks program 2
    if(user == 2){
        
        hull = brutehull(array2, size2);

        begin = clock();
            printf("Brute force with convex hull answer: %d\n", hull); 
        stop = clock(); 
             printf("Runtime for Brute Force %f seconds\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
             printf("\n");
        /*begin = clock();
        qsort = qhull(array2, 100000);
            printf("Divide and Conquor with convex hull answer: %d\n", qsort);
        stop = clock(); 
             printf("Runtime for Brute Force %f seconds\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
             printf("\n");
        */

    }


}