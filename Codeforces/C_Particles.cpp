#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int sol(pair<int,int> p,vector<int> &a,int k){
    
    int i = p.first, n= p.second;
    int j = i;
    
    int ans = 0,sum = 0;
    while(j<=n){
       if(sum<=k){
           ans = max(ans,abs(j-i));
           sum+=a[j];
           j++;
       }
       else{
           sum-=a[i];
           i++;
       }
    }
    
    if(sum<=k){
        ans = max(ans,abs(j-i));
    }
    return ans ;
    
    
}


class SegmentTree {
private:
    vector<int> tree;

    void build(int start, int end, int node, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(start, mid, 2 * node + 1, arr);
        build(mid + 1, end, 2 * node + 2, arr);
        tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
    }

    int query(int start, int end, int node, int left, int right) {
        if (left <= start && right >= end)
            return tree[node];
        if (left > end || right < start)
            return INT_MAX;
        int mid = start + (end - start) / 2;
        int left_result = query(start, mid, 2 * node + 1, left, right);
        int right_result = query(mid + 1, end, 2 * node + 2, left, right);
        return left_result & right_result;
    }

public:
    SegmentTree(vector<int>& arr) {
        int n = arr.size();
        tree.resize(4 * n);
        build(0, n - 1, 0, arr);
    }

    int findMaxIndex(int start, int end, int k) {
        int left = start;
        int right = end;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int query_result = query(0, end, 0, start, mid);
            if (query_result >= k) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        if (ans >= 0)
            ans += 1;
        return ans;
    }
};

int main() {
   int t;
   cin>>t;
   while(t--){
       int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int q;
        cin >> q;

        SegmentTree segmentTree(arr);

        while (q--) {
            int start, k;
            cin >> start >> k;
            start--;
            int result = segmentTree.findMaxIndex(start, n - 1, k);
            cout << result << " ";
        }
        cout << endl;
       
   }
   return 0;
}