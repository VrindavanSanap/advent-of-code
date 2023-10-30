#include <stdio.h>
void update_top3_elfs(int *top3_elfs, int total_elf_calories){
    int t = 2
    

}
void print_int_arr(int arr[], int len){

    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d, ", arr[i]);
    }
    printf("] \n");
}

int main(){
    int top3_elfs[3] = {2,1,4};
    update_top3_elfs(top3_elfs, 3);
    print_int_arr(top3_elfs,3);
}
