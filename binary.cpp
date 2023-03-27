#include <iostream>
#include <string>
using namespace std;

// Sequential multiplier
class SequentialMultiplication {
public:
  string multiply(string a, string b) {
    int x = stoi(a, nullptr, 2);
    int y = stoi(b, nullptr, 2);
    int result = 0;
    while (y != 0) {
      if (y & 1) {
        result += x;
      }
      x <<= 1;
      y >>= 1;
    }
    string binaryResult = "";
    while (result != 0) {
      binaryResult = (result % 2 == 0 ? "0" : "1") + binaryResult;
      result /= 2;
    }
    return binaryResult;
  }
};

// Driver code
int main() {
  // Create two numbers
  string a = "1011";
  string b = "1011";

  // Multiply the numbers
  SequentialMultiplication multiplication;
  string product = multiplication.multiply(a, b);

  // Print the product
  cout << "The product of " << a << " and " << b << " is " << product << endl;

  return 0;
}