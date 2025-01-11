#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
  int data;          // data
  struct Node* next; // pointer
};
struct Node* create_node(int data){
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
    
}
int main(){
  FILE* file1 = fopen("day1.txt", "r");
  FILE* file2 = fopen("day1.txt", "r");
  FILE* file3 = fopen("day1.txt", "r");
  if(file1 == NULL){
    perror("Unable to open file");
    return 1; 
  }
  char line1[31];
  char line2[31];
  char line3[31];
  int n_found= false;  
  while(fgets(line1, sizeof(line1), file1) && !n_found){
    int n1 = atoi(line1);
    while(fgets(line2, sizeof(line2), file2)&& !n_found){
      int n2 = atoi(line2);

      while(fgets(line3, sizeof(line3), file3)&& !n_found){
        int n3 = atoi(line3);
        if (n1 + n2 + n3 == 2020){
          printf("%d * %d * %d = %d\n",n1, n2, n3 , n1*n2*n3);
          n_found = true;
        }
      }

      rewind(file3);
    }
    rewind(file2);
   
  }
  return 0;
}
