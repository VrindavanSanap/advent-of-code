#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct char_freq {
  char char_;
  int freq;
};

int compare_by_freq(const void *a, const void *b) {
  struct char_freq *char1 = (struct char_freq *)a;
  struct char_freq *char2 = (struct char_freq *)b;
  return char2->freq - char1->freq;
}

char *most_freq_five() {
  static char five_freq[6];
  return five_freq;
}

struct char_freq char_freqs[26];
char *itos = "abcdefghijklmnopqrstuvwxyz";
int stoi(char a) { return a - 'a'; }

char *get_checksum(char *encrypted_name, int room_len) {
  for (int i = 0; i < 26; i++) {
    char_freqs[i].char_ = itos[i];
    char_freqs[i].freq = 0;
  }

  for (int i = 0; i < room_len; i++) {
    if (encrypted_name[i] != '-') {
      char_freqs[stoi(encrypted_name[i])].freq += 1;
    }
  }

  qsort(char_freqs, 26, sizeof(struct char_freq), compare_by_freq);
  static char checksum[6];
  checksum[5] = '\0';
  for (int i = 0; i < 5; i++) {
    checksum[i] = char_freqs[i].char_;
  }
  return checksum;
}

int main() {
  FILE *file = fopen("day4.txt", "r");

  // Check if the file opened successfully
  if (file == NULL) {
    printf("Error: could not open file.\n");
    return 1;  // Exit if unable to open the file
  }
  char line[255];
  int str_len;
  int i = 0;
  char temp[255];
  char given_checksum[6];
  char sector_id_str[4];
  int sector_id;
  int n_real = 0;
  int sector_id_sum = 0;
  while (fgets(line, sizeof(line), file)) {
    str_len = strlen(line);
    printf("%d %d %s", i++, str_len, line);
    strncpy(given_checksum, line + str_len - 7, 5);
    given_checksum[5] = '\0';
    printf("Given checksum: %s\n", given_checksum);
    strncpy(sector_id_str, line + str_len - 11, 3);
    sector_id_str[3] = '\0';
    printf("Sector id: %s\n", sector_id_str);
    line[str_len - 12] = '\0';
    char *checksum = get_checksum(line, str_len - 12);
    printf("%s \n", line);
    printf("Real checksum: %s \n", checksum);
    if (!strcmp(checksum, given_checksum)) {
      printf("Real %d \n", ++n_real);
      sector_id_sum += atoi(sector_id_str);
    } else {
      printf("Fake %d \n", n_real);
    }

    printf("%d", sector_id_sum);
  }
  return 0;
}
