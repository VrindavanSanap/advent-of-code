#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_combinations(const std::vector<T>& pool, int r) {
    int n = pool.size();
    if (r > n || r < 0) return;

    // Create a boolean mask with r ones and n-r zeros
    std::vector<bool> mask(n, false);
    std::fill(mask.end() - r, mask.end(), true);

    do {
        std::cout << "(";
        for (int i = 0; i < n; ++i) {
            if (mask[i]) {
                std::cout << pool[i] << " ";
            }
        }
        std::cout << ")\n";
    } while (std::next_permutation(mask.begin(), mask.end()));
}

int main() {
    std::vector<char> data = {'A', 'B', 'C', 'A'};
    print_combinations(data, 2);
    return 0;
}
