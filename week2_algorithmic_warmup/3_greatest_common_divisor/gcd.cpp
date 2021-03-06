#include <iostream>
using namespace std;

// int gcd_naive(int a, int b) {
//   int current_gcd = 1;
//   for (int d = 2; d <= a && d <= b; d++) {
//     if (a % d == 0 && b % d == 0) {
//       if (d > current_gcd) {
//         current_gcd = d;
//       }
//     }
//   }
//   return current_gcd;
// }

int gcd(int a, int b){
  if(a==0)
    return b;
  return gcd(b % a, a);
}

int main() {
  int a, b;
  cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  cout << gcd(a,b) << endl;
  return 0;
}
