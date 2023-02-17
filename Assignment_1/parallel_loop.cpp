#include <iostream>
#include <vector>
int main() {
  std::vector<int> vector_a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::vector<int> vector_b = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  int dot_product = 0;
  int number_of_elements = 16;
  // Add vectors a and b and store the result in c
#pragma omp parallel for
  for (int i = 0; i < number_of_elements; i++) {
    #pragma omp critical
    dot_product += vector_a[i] * vector_b[i];
  }
   // Print dot product
  std::cout << dot_product << std::endl;
}