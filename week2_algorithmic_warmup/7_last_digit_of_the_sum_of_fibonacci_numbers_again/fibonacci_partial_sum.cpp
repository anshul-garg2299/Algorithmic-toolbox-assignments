include <iostream>
#include <vector>
using std::vector;

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

int get_fibonacci_partial_sum_range_last(long long from, long long to){
    if(from==0){
        return fibonacci_sum_last_digit(to);
    }
    int a = fibonacci_sum_last_digit(from-1);
    int b = fibonacci_sum_last_digit(to);
    return ((b-a) + 10)%10;
}

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_range_last(from,to) << '\n';
}
