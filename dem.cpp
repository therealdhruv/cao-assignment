#include <iostream>
using namespace std;

// Sequential multiplier
class SequentialMultiplication {
public:
  int multiply(int a, int b) {
    int temp[32] = {0};
    for (int i = 0; i < 32; i++) {
      if (b & 1) { // If the LSB of b is 1
        for (int j = 0; j <= i; j++) {
          temp[j] += a & 1; // Add the LSB of a to the jth partial product
          a >>= 1; // Shift a right by 1 bit
        }
      }
      b >>= 1; // Shift b right by 1 bit
      a = (a << 1) | (a >> 31); // Shift a left by 1 bit
    }
    int result = 0;
    for (int i = 31; i >= 0; i--) {
      result = (result << 1) | (temp[i] & 1); // Shift result left by 1 bit and add the LSB of the ith partial product
    }
    return result;
  }
};

// Driver code
int main() {
  // Create two numbers
  int a = 12;
  int b = 14;

  // Multiply the numbers
  SequentialMultiplication multiplication;
  int product = multiplication.multiply(a, b);

  // Print the product
  cout << "The product of " << a << " and " << b << " is " << product << endl;

  return 0;
}
