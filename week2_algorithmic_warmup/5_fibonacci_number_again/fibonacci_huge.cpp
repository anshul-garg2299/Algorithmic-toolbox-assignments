#include <iostream>

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }
long long pisanoPeriod(long long m){
    long long prev = 0;
    long long prev1 = 1;
    long long p = 2;
    while(true){
        long long next = (prev + prev1)%m;
        prev = prev1;
        prev1 = next;
        if(prev == 0 && prev1 == 1){
            return p-1;
        }
        p++;
    }
    return -1;
}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;
    long long period = pisanoPeriod(m);
    n = n % period;
     if (n <= 1)
        return n;
    long long prev = 0;
    long long prev1 = 1;
    long long ans = 0;
    for(long long i = 2; i <=n; i++){
        ans = (prev + prev1);
        ans = ans%m;
        prev = prev1;
        prev1 = ans;
    }
    return ans;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
     std::cout << get_fibonacci_huge(n,m) << '\n';
   

}