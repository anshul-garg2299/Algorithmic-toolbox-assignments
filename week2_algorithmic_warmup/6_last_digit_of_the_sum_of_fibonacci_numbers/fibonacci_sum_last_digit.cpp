#include <iostream>

// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
//     }

//     return sum % 10;
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

int fibonacci_sum_last_digit(long long n){
    if(n<=1){
        return n;
    }
    long long period = pisanoPeriod(10);
    n = (n+2)%period;
    if(n==1){
        return n-1;
    }
    if(n==0){
        return 9;
    }
    long long prev = 0;
    long long prev1 = 1;
    long long ans = 0;
    for(long long i = 2; i <=n; i++){
        ans = (prev + prev1);
        ans = ans%10;
        prev = prev1;
        prev1 = ans;
    }
    if(ans==0){
        return 9;
    }
    return ans-1;
}
int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_last_digit(n) << '\n';
}
