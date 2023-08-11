// Fibonacci number
#include <iostream>

using namespace std;

int fib(int n) {

  // base condition: if n is 0 return 0, if it is 1 return 1 > if n < 2 return n
  if (n < 2) {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main() {
  cout << "enter n?" << endl;

  int n;
  cin >> n;
  int fibo = fib(n);
  cout << fibo << endl;
  return 0;
}
