#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=3e5;
ll a[N];

ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}

ll maxSubArray(vector<int> nums) {
        ll m = INT_MIN;
        ll currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            
            if(currSum>m)
                m=currSum;
            
            if(currSum<0)
                currSum=0;
        }
        return m;
}

void fill(vector<vector<int>> &matrix,vector<int> &visit,vector<int> &numbers,int nrow[],int ncol[],int i,int j,int l){
    int n=matrix.size();
    int m=matrix[0].size();
    int x=i+nrow[l];
    int y=j+ncol[l];
    if(x>=0 && x<n && y>=0 && y<m && visit[numbers[x*m+y]]==0){
        matrix[x][y]=numbers[x*m+y];
        visit[numbers[x*m+y]]=1;
    }
    else{
        l=(l+1)%4;
        x=i+nrow[l];
        y=j+ncol[l];
        matrix[x][y]=numbers[x*m+y];
        visit[numbers[x*m+y]]=1;
    }

}

void solve(){
    int n;
    cin>>n;
    
    vector<int> v(n*n);
    int j=n*n,k=1;

    for(int i=0;i<n*n;i++){
        if(i%2==0){
            v[i]=k;
            k++;
        }
        else{
            v[i]=j;
            j--;
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i%2!=0){
                cout<<v[i*n+n-j-1]<<" ";
            }
            else
            cout<<v[i*n+j]<<" ";
        }
        cout<<endl;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(j%2==0){
    //             cout<<v[i*n+j]<<" ";
    //         }
    //         else{
    //             cout<<v[(i+1)*n-j-1]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    //reverse a vector after every n elements
    // int m=0;
    // for(int i=0;i<n*n;i+=4){
    //     if(m%2!=0){
    //         reverse(v.begin()+i,v.begin()+i+4);
    //     }
    //     m++;
    // }

    // int ni=0;

    // for(int i=0;i<n*n;i++){
    //     cout<<v[i]<<" ";
    // }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}