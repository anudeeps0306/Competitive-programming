#include <bits/stdc++.h>
using namespace std;

bool check(int i,int j,vector<vector<char>> &v){
    if(i>=0 && i<v.size() && j>=0 && j<v[0].size() && v[i][j]=='.'){
        return true;
    }
    return false;
}

void dfsv(int i,int j,vector<vector<char>> &v){
    v[i][j]='#';
    if(check(i+1,j,v)){
        dfsv(i+1,j,v);
    }
    if(check(i-1,j,v)){
        dfsv(i-1,j,v);
    }
    if(check(i,j+1,v)){
        dfsv(i,j+1,v);
    }
    if(check(i,j-1,v)){
        dfsv(i,j-1,v);
    }
}

void dfsa(){

}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> v(n,vector<char>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'){
                count++;
                dfsv(i,j,v);
            }
        }
    }

    cout<<count<<endl;
    return 0;
}