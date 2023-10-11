#include <bits/stdc++.h>
using namespace std;
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mod             1000000007
#define PI              3.1415926535897932384626
#define endl            "\n"
#define YES             cout << "YES" << "\n"
#define NO              cout << "NO" << "\n"
#define ispowoftwo(n)   (!(n & (n-1)))
#define pb              push_back
#define ppb             pop_back
#define int              long long
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;


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
int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
 
 
 


bool clean(string s){
    bool flag = false;

    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            flag=true;
        }
        else if(s[i]=='B' && s[i+1]=='B'){
            flag=true;
        }
    }
    return flag;
}


int check( int i , vector<int> ans){
    for(auto it : ans){
        if(it%i != 0){
            return -1;
        }
    }

    if(i==1) return 2;

    for(int j=2;j<i;j++){
        if(i%j != 0){
            return j;
        }
    }

    return i+1;
}

string v[200];


void solve(){

    int n, co;
    cin >> n >> co;
    vector<int> a(n),b(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int i=0 ;i<n ;i++){
        ans.push_back({b[i], a[i]});
    }
    
    sort(ans.begin(), ans.end(), [](const pair<long long, char> &a, const pair<long long, char> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
});


    
    if(co > ans[0].first)
    {
        int ap = co, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (ans[i].first >= co)
            {
                ap += (co * (n - count));
                count = n;
                break;
            }
            else
            {
                int aj = count + ans[i].second;
                if (aj<= n)
                {
                    ap += (ans[i].second * ans[i].first);
                    count += ans[i].second;
                }
                else
                {
                    ap += (ans[i].first * (n - count));
                    count = n;
                    break;
                }
            }
        }
        cout << ap << endl;
        return;
    }
  
    cout << co * n << endl;
    
    

    
}

 
int32_t main(){
 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now();
 
    int t;
    cin>>t;
    while(t--) solve();
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s"<< endl;
    // #endif
    return 0;
}

