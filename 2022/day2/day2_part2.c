#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// you 
// A B C 
// R P S 

// X Y Z 
// L D W 


char rps[3] = {'R', 'P', 'S'};
int get_score(int your_move, int their_move){
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

int mod(int a, int b){
  int r = a % b;
  return r < 0 ? r + b : r;
}


int get_your_move(int their_move, int match_result){
  assert(match_result > -1 && match_result < 3);

  // Y -> 1 -> draw 
  if (match_result == 1){
    return their_move;
  }
  // X -> 0  -> lose
  if (match_result == 0){
    return mod((their_move - 1), 3);
  }
  // Z -> 2  -> win  
  if (match_result == 2){
    return mod((their_move + 1), 3);
  }
}

int get_score_from_line(char *line){
  // A B C
  // R P S 
  // 0 1 2  
 
 
  // 0 1 2  
  // X Y Z 
  // L D W

  int  their_move = line[0] - 65;
  int match_result = line[2] - 88;
  int your_move = get_your_move(their_move, match_result);
  int score = get_score(your_move, their_move);
  printf("%c %c score: %d",rps[your_move], rps[their_move], score);
  return score;
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
  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%d: %s",++count, line);
    int score = get_score_from_line(line);
    total_score += score;
    printf("score: %d total: %d\n", score, total_score);
  }
  
  fclose(file);
  return 0; 
}
