#include <stdio.h>
typedef struct main {
  int capacity;
  int durability;
  int flavor;
  int texture;
  int calories;
} ingredient;
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
ingredient cookie_properties(ingredient sprinkles, ingredient peanut_butter,
                             ingredient frosting, ingredient sugar,
                             int n_sprinkles, int n_peanut_butter,
                             int n_frosting, int n_sugar) {
  int total_capacity = (sprinkles.capacity * n_sprinkles);
  total_capacity += (peanut_butter.capacity * n_peanut_butter);
  total_capacity += (frosting.capacity * n_frosting);
  total_capacity += (sugar.capacity * n_sugar);

  int total_durability = (sprinkles.durability * n_sprinkles);
  total_durability += (peanut_butter.durability * n_peanut_butter);
  total_durability += (frosting.durability * n_frosting);
  total_durability += (sugar.durability * n_sugar);

  int total_flavor = (sprinkles.flavor * n_sprinkles);
  total_flavor += (peanut_butter.flavor * n_peanut_butter);

  total_flavor += (frosting.flavor * n_frosting);
  total_flavor += (sugar.flavor * n_sugar);

  int total_texture = (sprinkles.texture * n_sprinkles);
  total_texture += (peanut_butter.texture * n_peanut_butter);
  total_texture += (frosting.texture * n_frosting);
  total_texture += (sugar.texture * n_sugar);

  int total_calories = (sprinkles.calories * n_sprinkles);
  total_calories += (peanut_butter.calories * n_peanut_butter);
  total_calories += (frosting.calories * n_frosting);
  total_calories += (sugar.calories * n_sugar);

  ingredient cookie = {max(total_capacity, 0), max(total_durability, 0),
                       max(total_flavor, 0), max(total_texture, 0),
                       max(total_calories, 0)};
  return cookie;
}

int main() {
  ingredient sprinkles = {5, -1, 0, 0, 5};
  ingredient peanut_butter = {-1, 3, 0, 0, 1};
  ingredient frosting = {0, -1, 4, 0, 6};
  ingredient sugar = {-1, 0, 0, 2, 8};

  int highest_res = 0;
  for (int i = 0; i <= 100; i++) {
    int num_sprinkes = i;
    for (int j = 0; j <= 100 - i; j++) {
      int num_peanut = j;
      for (int k = 0; k <= 100 - i - j; k++) {
        int num_frosting = k;
        int num_sugar = 100 - i - j - k;

        ingredient cookie = cookie_properties(
            sprinkles, peanut_butter, frosting, sugar, num_sprinkes, num_peanut,
            num_frosting, num_sugar);
        if (cookie.calories == 500) {
          int res = cookie.capacity * cookie.durability * cookie.flavor *

                    cookie.texture;
          if (highest_res < res) {
            highest_res = res;
          }
        }
      }
    }
  }
  printf("%d", highest_res);
  return 0;
}