/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function prototypes
char **parser1(char *name);
char *parser2(char *name2);
void brute(char *searcher, char **searcherArr);
void sortPre(char *search, char **searcherArr);
int searchBrute(char *need, char *hay);
int poolhors(char *need, char *hay);
int algoBm(char *need, char *hay);

char **parser1(char *name){
//declare all variables at the top
    FILE *namefile;
    int num; 
    int i = 0;
    char **string = malloc(sizeof(char *) * 35000);

//when entering name if statment checks if it the file is valid
    if (name == NULL){
        printf("The name that is entered is invalid\n");
        return NULL;
    }

//when passes the first erro handleing it opens the file
    namefile = fopen(name, "r");

//error handleing to see if the file == Null 
    if (namefile == NULL){
        printf("Sorry unable to open the file\n");
        fclose(namefile);
        return NULL;
    }

    while (fscanf(namefile, "%d", &num) == 1){

        string[i] = malloc(sizeof(char) * 10);
        sprintf(string[i], "%d", num);
        i++;
    }
//close file 
    fclose(namefile);
//return string 
    return string;

}
char *parser2 (char *name2){
//declare all variables
    FILE *file;
    char *buf;
    char c;
    int fileSize; 
    int index = 0;

//when entering name if statment checks if it the file is valid
    if (name2 == NULL){

        printf("The name that is entered is invalid\n");
        return NULL;
    }

//opens file once passses the first if statment
    file = fopen(name2, "r");

    if (file == NULL){
        printf("Could not open file %s\n", name2);
        return NULL;
    }

// finding size of file for malloc, had to do this because I was mallocing to much or to little space causing errors 
    fseek(file, 0L, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    buf = malloc((fileSize + 1) * sizeof(char));

    while ((c = fgetc(file)) != EOF){
        buf[index++] = c;
    }
    
    buf[index] = '\0';

    fclose(file);
    return buf;
}
int main(int argc, char **argv){
//declare variables in main 
clock_t begin;
clock_t stop;
char **array1 = parser1("data_4.txt");
char *array2 = parser2("data_5.txt");
char stringa[20];
char stringb[230];
int searcher;
int user;
int horspool1;
//int algo;

    printf("Welcome To Assignment 3! Press 1 for Part 1 Press 2 for Part 2\n\n");
    scanf("%d" , &user);

    if(user == 1){

    printf("P1: \nEnter String for Anagram\n");
    scanf("%s", stringa);

    printf("Bruteforce for Question 1: \n");

    begin = clock();
        brute(stringa, array1);
    stop = clock();
        printf("Runtime for Brute Force %f seconds\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
    
    printf("Presorting for 1.2: \n");
    sortPre(stringa, array1);
    }
    if(user == 2){
    printf("P2: \nEnter String for search\n");
    scanf("%s", stringb);
    
    begin = clock(); 
        searcher = searchBrute(stringb,array2);
    stop = clock();
        printf("Amount of Shifts: %d\n", searcher);
        printf("Runtime for Brute Force %f seconds\n\n", ((double)(stop - begin))/ CLOCKS_PER_SEC);
    }

    begin = clock();
        horspool1 = poolhors(stringb, array2);
    stop = clock();
        printf("Amount of Shifts: %d\n", horspool1);
        printf("Runtime for Horspool is %f seconds\n\n ", ((double)(stop - begin))/ CLOCKS_PER_SEC);

   /* begin = clock(); 
        algo = algoBm(stringb, array2);
    stop = clock(); 
        printf("Amount of Shifts: %d\n", algo); 
        printf("Runtime for Boyer-Moore is %f seconds\n\n ", ((double)(stop - begin))/ CLOCKS_PER_SEC);
    */



return 0;
}