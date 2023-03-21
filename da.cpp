#include <iostream>

using namespace std;

// Sequential binary multiplier
class SequentialMultiplier {

private:

  // Multiplicand and multiplier
  int multiplicand;
  int multiplier;

  // Partial products
  int partialProducts[10];

  // Sum of partial products
  int sumOfPartialProducts;

public:

  // Constructor
  SequentialMultiplier(int multiplicand, int multiplier) {
    this->multiplicand = multiplicand;
    this->multiplier = multiplier;
  }

  // Multiply two numbers
  int multiply() {
    // Initialize partial products
    for (int i = 0; i < 10; i++) {
      partialProducts[i] = 0;
    }

    // Iterate over the bits of the multiplicand
    for (int j = 9; j >= 0; j--) {
      // Multiply the bit of the multiplicand by the bit of the multiplier
      for (int k = 0; k < 10; k++) {
        partialProducts[k] += (multiplicand & (1 << j)) * (multiplier & (1 << k));
      }

      // Add the partial products
      sumOfPartialProducts += partialProducts[j];
    }

    // Return the sum of partial products
    return sumOfPartialProducts;
  }
};

int main() {

  // Get the multiplicand and multiplier from the user
  int multiplicand, multiplier;
  cin >> multiplicand >> multiplier;

  // Create a sequential multiplier
  SequentialMultiplier seqMultiplier(multiplicand, multiplier);

  // Multiply the two numbers
  int product = seqMultiplier.multiply();

  // Print the product
  cout << product << endl;

  return 0;
}
