#include <iostream>
#include <vector>

#include <bits/stdc++.h>
using namespace std;
// bool comparator(pair<int,pair<int,char>> p, pair<int,pair<int,char>> q){
//   if(p.first == q.first){
//     if(p.second.second == 'l' && q.second.second == 'p'){
//       return true;
//     }
//   }
//   else return p.first < q.first;
// }

vector<long long> naive_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points)
{
  vector<long long> cnt(points.size());
  for (long long unsigned int i = 0; i < points.size(); i++)
  {
    for (long long unsigned int j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points){
  vector<long long> cnt(points.size());
  vector<pair<int,pair<int,int>>> number_line;
  for(int i = 0; i < starts.size(); i++){
    number_line.push_back(make_pair(starts[i],make_pair(0,-1)));
  }
  for(int i = 0; i < ends.size(); i++){
    number_line.push_back(make_pair(ends[i],make_pair(2,-1)));
  }
  for(int i = 0; i < points.size(); i++){
    number_line.push_back(make_pair(points[i],make_pair(1,i)));
  }
  sort(number_line.begin(),number_line.end());
  int count = 0;
  for(int i = 0; i < number_line.size(); i++){
    if(number_line[i].second.first == 0){
      count++;
    }
    if(number_line[i].second.first == 2){
      count--;
    }
    if(number_line[i].second.first == 1){
      cnt[number_line[i].second.second] = count;
    }
  }
  return cnt;
}

int main()
{
  long long n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (long long unsigned int i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (long long unsigned int i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<long long> cnt = fast_count_segments(starts, ends, points);
  for (long long unsigned int i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}