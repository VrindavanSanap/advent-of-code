#include <stdio.h>

int get_score(char *line){
  //  printf("%c %c ",line[0], line[2]);
  // A B C
  // R P S 
  // X Y Z 
  // 1 2 3 
  int  their_move = line[0] - 65;
  int your_move = line[2] - 88;
  char rps[3] = {'R', 'P', 'S'};
  printf("%c -vs- %c \n", rps[your_move], rps[their_move]);
  
  int game_res_arr[3][3] = {
    {0, -1, 1}, // Your R vs Their R P S 
    {1, 0, -1}, // Your P vs Their R P S 
    {-1, 1, 0}  // Your S vs Their R P S 
  };
  int game_res = game_res_arr[your_move][their_move];
  int total_score = 1;
  total_score += your_move;
  if (game_res > 0){
    printf("You won! YAY \n");
    total_score += 6;
  }
  if (game_res == 0){
    printf("Game draw \n");
    total_score += 3;
  }
  if (game_res < 0){
    printf("You Lost :( \n");
  }
  return total_score;
}

int main(){
  int win_pts = 6;
  int draw_pts = 3;
  int lose_pts = 0;


  int rock_pts = 1;
  int paper_pts = 2;
  int scissors_pts = 3;
  
  FILE *file;
  char line[10];

  file = fopen("day2.txt","r");
  if (file == NULL) {
    printf("Could not open the file.\n");
    return 1; 
  }

  int count = 0;
  int total_score = 0;
  get_score(line);
  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%d\n",++count);
    printf("%s", line);
    int score = get_score(line);
    total_score += score;
    printf("score: %d total: %d\n", score, total_score);
  }
  
  fclose(file);
}
