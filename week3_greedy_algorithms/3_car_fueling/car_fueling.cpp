#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int stop = 0;
    int cur_pos = 0;
    int next_tank = 0;
    while(dist - cur_pos > tank){
        if(stops[next_tank] - cur_pos > tank){
            return -1;
        }
        else{
            while(stops[next_tank]-cur_pos <= tank ){
                next_tank++;
                if(next_tank==stops.size()){
                    break;
                }
            } 
            cur_pos = stops[next_tank-1];
            stop++;
        }
    }
    return stop;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

