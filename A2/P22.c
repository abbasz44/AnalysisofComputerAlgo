/*Zachery Abbas
  1019463
  Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 52
int table[MAX];

void shifter(char *needle)
{
    int i, j, m;
    m = strlen(needle);
    for (i = 0; i < MAX; i++)
        table[i] = m;
    for (j = 0; j < m - 1; j++)
    {
        if (needle[j] >= 'a' && needle[j] <= 'z')
            table[(int)needle[j] - 97] = m - j - 1;
        else if (needle[j] >= 'A' && needle[j] <= 'Z')
            table[(int)needle[j] - 65] = m - j - 1;
    }
}
int poolhors(char *need, char *hay){
//declare variables up top
int k = 0; 
int len1 = strlen(hay); 
int len2 = strlen(need);
int i;
int counter = 0;
int shift = 0;

shifter(need);

i = len2 - 1;

while(i < len1){
  k = 0;
  while((need[len2-1-k] == hay[i-k]) && (k<len2)){
    k++;
  }
       if (k != len2) {
           if (hay[i] >= 'a' && hay[i] <= 'z')
              i += table[(int)hay[i] - 97];
            else if (hay[i] >= 'A' && hay[i] <= 'Z')
              i += table[(int)hay[i] - 65];
            else
              i += len2;

            shift++;  
        }
        else{
           counter++;
            i += len2;
            shift++;
        }

    }
printf("The amount of horspool found that are matches: %d\n", counter);
return shift;

}


