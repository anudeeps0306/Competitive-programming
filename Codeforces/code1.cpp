#include<bits/stdc++.h>

using namespace std;

bool safe(int row, int col,int n,int m){
    if(row>=0 && row<n && col>=0 && col<m){
        return true;
    }
    return false;
}

bool corner(int row,int col,int len,int a,int b){
    if(a-len/2==row && b-len/2==col){
        return false;
    }
     if(a-len/2==row && b+len/2==col){
        return false;
    }
     if(a+len/2==row && b-len/2==col){
        return false;
    }
     if(a+len/2==row && b+len/2==col){
        return false;
    }
    return true;
}


bool check(vector<vector<int>> m, int a, int b) {
    int len = m[a][b] * 2 + 1;

    int start = max(0, a - len / 2);
    int end = min(static_cast<int>(m.size()) - 1, a + len / 2);
    int col_s = max(0, b - len / 2);
    int col_e = min(static_cast<int>(m[0].size()) - 1, b + len / 2);

    for (int i = start; i <= end; i++) {
        for (int j = col_s; j <= col_e; j++) {
            if (safe(i, j, m.size(), m[0].size()) && corner(i, j, len, a, b) && (i != a || j != b)) {
                if (m[a][b] <= m[i][j]) {
                    return false;
                }
            }
        }
    }

    return true;
}



vector<vector<int>> f(vector<vector<int>> ma){

    int n = ma.size();
    int m = ma[0].size();

    vector<vector<int>> ans;

    

    for(int i=0 ;i<n ;i++){
        for(int j=0 ; j<m ;j++){
            vector<int> temp;
            if(ma[i][j]>0 && check(ma,i,j)){
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(),ans.end());

    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> ma(n,vector<int> (m,0));


    for(int i=0 ;i<n ;i++){
        for(int j=0; j<m; j++){
            cin>>ma[i][j];
        }
    }


    vector<vector<int>> ans = f(ma);

    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    return 0;
}