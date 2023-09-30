#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int a[5][5];
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin >> a[i][j];
                if(a[i][j]==1)
                {
                    printf("%d",abs(3-i)+abs(3-j));
                }
            }
        }

    }
	return 0;
}