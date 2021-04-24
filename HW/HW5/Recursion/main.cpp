#include <iostream>

using std::cout;
using std::endl;

int fib(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  return fib(n-1) + fib(n-2);
}

int fib_loop(int n) {
  if(n < 1) return 0;
  if(n == 1 || n == 2) return 1;

  int total = 0;
  int one = 1;
  int two = 1;

  for(int i = 2; i < n; i++) {
    total = one + two;
    one = two;
    two = total;
  }

  return total;
}

int ack(int m, int n) {
  if(m == 0) return n + 1;

  if(m > 0 && n == 0) return ack( m - 1, 1 );

  if(m > 0 && n > 0) return ack( m - 1, ack( m, n - 1 ) );

  return -1;
}

int main() {
  cout << "Fibonacci Sequence" << endl;

  for(int i = 0; i < 20; i++) {
    cout << "fib(" << i << "): " << fib(i) << " == " << fib_loop(i) << " :fib_loop(" << i << ")" << endl;
  }

  cout << endl << endl;

  cout << "ACK" << endl;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 6 - i; j++) {
      cout << "ack(" << i << ", " << j << ") = " << ack(i, j) << endl;
    }
  }
}
