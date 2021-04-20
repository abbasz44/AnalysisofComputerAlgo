/*Zachery Abbas 
  1019463
  Assignment 4
  March 30
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
//define structs 
typedef struct stuctW{
    char *keyS;
    float frequency;
}word;

typedef struct binary{
    struct binary *left;
    struct binary *right;
    struct stuctW *key;
}binarySearch;

//function prototype 
int sum(struct binary *root, int i, int j);

//calculates the sum
int sum(struct binary *root, int i, int j){
    int x = 0;
    for (int k = i; k <=j; k++){
       x += root->key->frequency;
     }

    return x;
}

//go left than go right then deal with the node this is a recursive fucnction
void printorder(struct binary* node){
     if (node == NULL)
        return;

     printorder(node->left);
     printorder(node->right);
     printf("String is: %s frequency is: %2f \n", node->key->keyS, node->key->frequency );
}

struct binary *newNode(char *key){   
    struct binary *temp;
    
//malloc space for temp 
    temp =  (struct binary *)malloc(sizeof(struct binary));

//malloc space for the size of word
    temp->key = malloc(sizeof(word));
    temp->key->frequency = 1;
//calloc sapce
    temp->key->keyS = calloc(999, sizeof(char));

//copy strng  
    strcpy(temp->key->keyS,key);    
    temp->left = temp->right = NULL;
    
    return temp;
}

//orders the BST calls recursively
void inorder(struct binary *root){
    if (root != NULL){
        inorder(root->left);
        inorder(root->right);
    }
}

//inserter fucntion for BST recursive function compares it in the staments then inserts to the respected area
struct binary* inserter(struct binary* node, char *key){
//if == NULL returns the new node
    if (node == NULL) return newNode(key);

//compares strings if less than 0 then inserters 
    if(strcmp(key, node->key->keyS) < 0){
        node->left  = inserter(node->left, key);
      
    }
//compares string = 0 then inserters 
    else if(strcmp(key, node->key->keyS) == 0){
        node->key->frequency++;
    }
//compares strings greater than 0 then inserters 
    else if(strcmp(key, node->key->keyS) > 0){
        node->right = inserter(node->right, key);

    }
 
    return node;
}

void searchNode(char *stringWord, struct binary *n){
//statment sees if the string is null if this is true than it doesnt exist
    if (n == NULL)
        printf("\nString isn't in DATA_7.txt\n");

//sees what string compared to then goes to right subtree 
    else if(strcmp(stringWord, n->key->keyS) > 0){
        printf("String is compared with %s (%2f), go to the right subtree\n", n->key->keyS, n->key->frequency/600);
     
        searchNode(stringWord, n->right);
      }

//sees if string is found  
    else if(strcmp(n->key->keyS, stringWord) == 0){
        printf("string %s found\n ", stringWord);
    }
//if not found and not right subtree is goes to left
    else{
          printf("String is compared with %s (%2f), go to the left subtree\n", n->key->keyS, n->key->frequency/600);
        searchNode(stringWord, n->left);
      }
}

//recursive function that call
int optCost(struct binary *root, int i, int j){
    int min = INT_MAX;
    int summer;

     if (j == i){    
     return  root->key->frequency;
     }
     if (j < i)  {   
     return 0;
    }
  //call sum function
   summer = sum(root, i, j);

   for (int r = i; r <= j; ++r){
       int cost = optCost(root, i, r-1) +
                  optCost(root, r+1, j);
       if (cost < min){
          min = cost;
       }
   }

   return min + summer;
 }


int optimalSearchTree(struct binary *root, int n){
    
     return optCost(root, 0, n-1);
}
/*next two functions are the file opener and the parser 
  these two functions are here to open the file and parse 
  through the file
*/
//file opener
char *fileOpen(char *filename){
   FILE *fp;
   int length;
   char* s;
   
    fp = fopen("data_7.txt", "r");

    fseek (fp, 0, SEEK_END);
    length = ftell (fp);
    s = calloc(1,(length));
    fseek (fp, 0, SEEK_SET);

    if (s){
    fread (s, 1, length, fp);
    }

    fclose(fp);

    return s;

}

//fucntion to parser through the string
size_t string_parser( const char *input, char ***word_array){
    size_t buf = 0;
    const char *temp = input;

      while ( *temp ){
        while ( isspace(( char)*temp)) ++temp;
        buf += *temp != '\0';
        while ( *temp && !isspace( ( char)*temp)) ++temp;
    }
    if ( buf ){
        size_t i = 0;

        *word_array = calloc(1, buf * sizeof( char * ) );

        temp = input;

        while ( *temp ){
            while (isspace((char)*temp )) ++temp;
            if ( *temp ){
                const char *q = temp;
                while (*temp && !isspace((char)*temp)) ++temp;
                size_t length = temp - q;

                (*word_array )[i] = (char *)calloc(1, length + 1 );

                strncpy( ( *word_array )[i], q, length );
                    (*word_array)[i][length] = '\0';

                ++i;
            }
        }
    }


    return buf;
}


int main(){

    char **word_array;
    struct binary *root;
    char *s = fileOpen("data_7.txt");
    int i;
    char keyEntered[100];
 
    string_parser(s, &word_array);
    root = newNode(word_array[0]);

    for(i=1; i< 2045; i++){
        inserter(root, word_array[i]);
  }

    printf("pretned this is correct couldn't figure out how to do kept getting seg fault :(  \n");
    printf("Enter a string to search: ");
    scanf("%s", keyEntered );
    searchNode(keyEntered, root);


return 0;
}