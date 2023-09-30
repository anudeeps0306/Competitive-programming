 #include <bits/stdc++.h>
using namespace std;
#define fastIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define mod 1000000007
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define ispowoftwo(n) (!(n & (n - 1)))
#define pb push_back
#define ppb pop_back
#define int long long
#define FOR(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
int maxi = 1e16; 

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

bool clean(string s)
{
    bool flag = false;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            flag = true;
        }
        else if (s[i] == 'B' && s[i + 1] == 'B')
        {
            flag = true;
        }
    }
    return flag;
}

int check(int i, vector<int> ans)
{
    for (auto it : ans)
    {
        if (it % i != 0)
        {
            return -1;
        }
    }

    if (i == 1)
        return 2;

    for (int j = 2; j < i; j++)
    {
        if (i % j != 0)
        {
            return j;
        }
    }

    return i + 1;
}

char get(int i)
{
    return 'a' + i - 1;
}

const int INF = 1e9 + 7;

int myans(int n)
{
    int pow = 1;
    while (pow <= n)
    {
        pow *= 2;
    }
    return pow;
}

int bpow(int base, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int badd(int a, int b)
{
    return (a + b) % mod;
}
int bsub(int a, int b)
{
    return (((a - b) % mod) + mod) % mod;
}
int bmul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}

int binv(int base)
{
    return bpow(base, mod - 2);
}

int bdiv(int a, int b)
{
    return bmul(a, binv(b));
}

int pow2(int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= 2;
    }
    return ans;
}

void dfs(vector<vector<pair<int,int>>>& v,vector<int>& visited, int pos,vector<int>& ans){
    visited[pos]=1;


    for(auto it : v[pos]){
        if(!visited[it.first]){
            ans[it.first] = ans[pos] + it.second;
            dfs(v,visited,it.first,ans);
        }
    }
}


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool comparePairs(const pair<int, int> &a, const pair<int, int> &b) {
    return a > b;
}

void sortAndReversePairs(vector<pair<int, int>> &pairs) {
    sort(pairs.begin(), pairs.end(), comparePairs);
}

int help(const vector<int>& b) {
    int n = b.size();
    int sum_terms = 0;
    int max_term = numeric_limits<int>::min();
    
    for (int i = 0; i < n; ++i) {
        sum_terms += b[i] * (i + 1);
        max_term = max(max_term, b[i] * (i + 1));
    }
    
    return sum_terms - max_term;
}

pair<int,int> find2(int a,int k){
    int cnt=0;
    while(a%2==0 && a!=k){
        a/=2;
        cnt++;
    }
    return {a,cnt};
}

int brute(int n,int m){
    int cnt=0;
    
    while(n > m){
        m*=2;
        cnt++;
    }

    return cnt+(m-n);
}

int find(int n,int m){

    pair<int,int> p = find2(m,n);

    if(p.first > n){
        return brute(p.first, n);
    }
    else if(p.first < n){
        return n-p.first+p.second;
    }
   
    return p.second;

}

vector<vector<vector<int>>> memo;

int f(int w,int k,vector<int>&v,int pos,int w1,int f1){
    if(pos >= v.size()){
        return 0;
    }
    if (memo[pos][w1][f1] != -1) {
        return memo[pos][w1][f1];
    }


    int water=INT_MAX,fire=INT_MAX;

    if(w1 >= v[pos]){
        water = f(w,k,v,pos+1,w1-v[pos],f1);
    }
    else{
        int time = (v[pos] - w1 + w - 1) / w;
        water = time+f(w,k,v,pos+1,w1+time*w-v[pos],f1+time*k);
    }
    if(f1 >= v[pos]){
        fire = f(w,k,v,pos+1,w1,f1-v[pos]);
    }
    else{
        int time = (v[pos] - f1 + k - 1) / k;
        fire = time+f(w,k,v,pos+1,w1+time*w,f1+time*k-v[pos]);
    }
    return memo[pos][w1][f1] = min(water,fire);
}

void printchar(string odd_chars,string even_chars){
    int i=0,j=0;
    while (i < even_chars.size() || j < odd_chars.size()) {
            if (i != even_chars.size()) {
                cout << even_chars[i];
                i++;
            }
            if (j != odd_chars.size()) {
                cout << odd_chars[j];
                j++;
            }
        }
        cout << endl;
}



int binarySearchPower(int x) {
    int lower_bound = 0, upper_bound = 31, power = -1;

    while (lower_bound <= upper_bound) {
        int mid = (lower_bound + upper_bound) / 2;
        int power_of_2 = 1;

        for (int i = 0; i < mid; i++) {
            power_of_2 *= 2;
        }

        if (power_of_2 <= x) {
            power = mid;
            lower_bound = mid + 1;
        } else {
            upper_bound = mid - 1;
        }
    }

    return power;
}

void updateMatrix(vector<vector<char>>& input, const vector<vector<int>>& indices, bool updateRows) {
    int n = input.size();
    int m = input[0].size();

    for (int i = 0; i < indices.size(); i++) {
        for (int k = 0; k < indices[i].size(); k += 2) {
            int j1 = indices[i][k];
            int j2 = indices[i][k + 1];
            if (updateRows) {
                input[i][j1] = 'W';
                input[i][j2] = 'B';
                input[i + 1][j1] = 'B';
                input[i + 1][j2] = 'W';
            } else {
                input[j1][i] = 'W';
                input[j2][i] = 'B';
                input[j1][i + 1] = 'B';
                input[j2][i + 1] = 'W';
            }
        }
    }
}

bool isprime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void solve() {

       
//   string s;
//   cin >> s;

//   int n = s.length();

//   int j = 0;
//   int sum = 0, ap = 0, ap1 = 0, sort_count = 0;

//   for (int i = 0; i < n; i++) {
//     if (s[i] == '1') {
//       int temp = sum;
//       int add = 0, sub = 0;
//       bool flag = false;
//       while (j <= i) {
//         if (s[j] == '-') {
//           temp--;
//           sub++;
//         }
//         if (s[j] == '+') {
//           temp++;
//           add++;
//         }
//         if (temp == sort_count || temp == 1) {
//           flag = true;
//           break;
//         }
//       }
//       if (!flag) {
//         cout << "NO" << endl;
//         return;
//       }
//       j = i + 1;
//       sum += (add - sub);
//       sort_count = temp;
//     } 
//     if (s[i] == '0') {
//       int add = 0, sub = 0, temp = sum;
//       while (j <= i) {
//         if (s[j] == '-') {
//           sub++;
//           temp--;
//         }
//         if (s[j] == '+') {
//           add++;
//           temp++;
//         }
//       }
//       if (add < sub || (sort_count <= sum && add == sub)) {
//         cout << "NO" << endl;
//         return;
//       }
//       if (temp < sort_count) {
//         sort_count = temp;
//       }
//       sum += (add - sub);
//     }
//   }

//   cout << "YES" << endl;

    string s;
    cin>>s;

    int n = s.size();
    vector<int> dp(n,-1);

    int pos=-1;
    int sum=0;

    int sorted=0;

    for(int i=0 ;i<n;i++){
        if(s[i]=='-'){
            sum--;
            if(pos==sum){
                pos--;
                // if(sorted >= pos){
                //     cout<<"YES"<<endl;
                //     return;
                // }
            }
            // sorted=min(sorted,sum);
        }
        else if(s[i]=='+'){
            dp[sum]=-1;
            sum++;
        }
        else if(s[i]=='0'){
            if(sum<=1 || dp[sum-1]==0){
                cout<<"NO"<<endl;
                return;
            }
            dp[sum-1]=1;
        }
        else{
            for(int i=pos+1; i<sum ;i++){
                if(dp[i]==1){
                    cout<<"NO"<<endl;
                    return;
                }
                dp[i]=0;
            }
            pos=sum-1;
        }

    }

    cout<<"YES"<<endl;


}

   






int32_t main()
{
    fastIO;
    auto start = chrono::high_resolution_clock::now();
    int t;
    cin >> t;
    while (t--)
        solve();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s" << endl;
    // #endif
    return 0;
}
