#include <iostream>
using namespace std;

// Sequential multiplier
class SequentialMultiplication {
public:
  int multiply(int a, int b) {
      int result = 0;
      while (b != 0) {
          if (b & 1) {
              result += a;
          }
          a <<= 1;
          b >>= 1;
      }
      return result;
  }
};

// Driver code
int main() {
  // Create two numbers
  int a = 11;
  int b = 11;

  // Multiply the numbers
  SequentialMultiplication multiplication;
  int product = multiplication.multiply(a, b);

  // Print the product
  cout << "The product of " << a << " and " << b << " is " << product << endl;

  return 0;
}
