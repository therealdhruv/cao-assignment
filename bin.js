// Sequential multiplier
class SequentialMultiplication {
  multiply(a, b) {
    let x = parseInt(a, 2);
    let y = parseInt(b, 2);
    let result = 0;
    while (y != 0) {
      if (y & 1) {
        result += x;
      }
      x <<= 1;
      y >>= 1;
    }
    let binaryResult = "";
    while (result != 0) {
      binaryResult = (result % 2 == 0 ? "0" : "1") + binaryResult;
      result = Math.floor(result / 2);
    }
    return binaryResult;
  }
}

// Driver code
// Create two numbers
let a = "1011";
let b = "1011";

// Multiply the numbers
let multiplication = new SequentialMultiplication();
let product = multiplication.multiply(a, b);

// Print the product
console.log(`The product of ${a} and ${b} is ${product}`);
