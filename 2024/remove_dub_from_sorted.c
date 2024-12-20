#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b){
  int int_a = *(int *)a;
  int int_b = *(int *)b;
  return int_a - int_b;
}

void print_arr(int *arr, int size){
  printf("{");
  for(int i = 0; i< size; i++){
    printf("%d, ", arr[i]);
  }
  printf("} \n");
}


int remove_duplicates_from_sorted_array(int *arr, int size){
  int reader = 1;
  int writer = 1;
  int prev = arr[0];
  int unique_count = 0;
  while (reader != size) {
    if (prev != arr[reader]){
      arr[writer++] = arr[reader];
    }
    prev = arr[reader++];
  }
  return writer;
}

int main(){
  int a[] = {0,0,1,1,1,2,2,3,3,4};
  int b[] = {1, 1, 2};
  print_arr(a, sizeof(a)/sizeof(a[0]));
  qsort(a, sizeof(a)/sizeof(a[0]),sizeof(a[0]),  compare_ints);
  print_arr(a, sizeof(a)/sizeof(a[0]));
  int res = remove_duplicates_from_sorted_array(a, sizeof(a)/sizeof(a[0]));
  print_arr(a, sizeof(a)/sizeof(a[0]));
  printf("N unique = %d \n", res);
  return 0;
}
