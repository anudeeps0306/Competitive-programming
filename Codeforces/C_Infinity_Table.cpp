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
    
    
    
    int lcm(int a, int b){
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

    bool issorted(vector<int> v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){
                return false;
            }
        }
        return true;
    }


    void solve(){
        int n;
        cin>>n;

        int col = sqrt(n);

        int number = col*col;

        int dif = n - number;

        if(number==n){
            cout<<col<<" "<<1<<endl;
            return;
        }

        // cout<<number<<" "<<n<<" "<<dif<<endl;

        // cout<<dif<<" "<<col+1<<endl;
        if(dif <= col+1 ){
            cout<<dif<<" "<<col+1<<endl;
        }
        else{
            cout<<col+1<<" "<<2*(col+1)-(dif)<<endl;
        }


      


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

