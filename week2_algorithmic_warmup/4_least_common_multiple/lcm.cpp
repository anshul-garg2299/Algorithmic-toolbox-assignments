#include <iostream>
using namespace std;

// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }
int gcd(int a, int b){
  if(a==0)
    return b;
  return gcd(b % a, a);
}

int main() {
  int a, b;
  cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  int g = gcd(a,b);
  long long ans = ((long long)a*b)/g;
  cout << ans << endl;
  return 0;
}