#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> fun(vector<int>& a, int n) {
  map<int, int> m;
  vector<int> copy = a;
  sort(copy.begin(), copy.end());
  for (int i = 0; i < n; i++) {
    m[copy[i]] = i + 1;
  }
  int moves = 0;
  vector<pair<int, int>> swaps;  

  for (int i = 0; i < n; i++) {
    if (i + 1 != m[a[i]]) {
      swaps.push_back({i, m[a[i]] - 1}); 
      swap(a[i], a[m[a[i]] - 1]);
      moves++;
    }
  }
  return swaps;
}

int main() {
  int t;
  cin>>t;

  while(t--){
        int k;
    cin>>k;


    vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin>>arr[i];
        }
    int n = arr.size();
    vector<pair<int, int>> swaps = fun(arr, n);

    cout<<swaps.size()<<endl;
    
    for (auto p : swaps) {
        cout<<p.first+1<<" "<<p.second+1<<endl;
        cout<<p.second+1<<" "<<p.first+1<<endl;
        cout<<p.first+1<<" "<<p.second+1<<endl;
    }
  }
  return 0;
}
