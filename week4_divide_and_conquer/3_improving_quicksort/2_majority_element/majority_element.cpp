#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  sort(a.begin(),a.end());
    int count = 1;
    for(int  i = 1; i < a.size(); i++){
      if(a[i]==a[i-1]){
        count++;
      }
      else count = 1;
      if(count > a.size()/2){
        return 1;
      }
    }
    return -1;
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
