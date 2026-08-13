#include <ATen/ATen.h>
#include <iostream>

int main() {
    // Create a 2x3 tensor filled with random values
    at::Tensor x = at::rand({2, 3});

    // Create a matrix of ones with a specific datatype
    at::Tensor y = at::ones({3, 2}, at::kFloat);

    // Perform matrix multiplication
    at::Tensor z = at::matmul(x, y);

    // Print tensor properties and contents
    std::cout << "Result shape: " << z.sizes() << std::endl;
    std::cout << "Result tensor:\n" << z << std::endl;

    // CUDA example (check availability first)


    return 0;
}
