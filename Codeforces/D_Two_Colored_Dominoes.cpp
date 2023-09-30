#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int n = a.length();
        vector<int> hash(n, 0);
        int j = 0;
        int s = -1;
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '+')
            {
                hash[j] = 0;
                j++;
            }
            else if (a[i] == '-')
            {
                j--;
                if (s == j)
                    s--;
            }
            else if (a[i] == '1')
            {

                for (int i = s + 1; i < j; i++)
                {
                    if (hash[i] == 2)
                    {
                        pos = false;
                        break;
                    }
                    hash[i] = 1;
                }
                s = j - 1;
            }
            else
            {
                if (j <= 1 || hash[j - 1] == 1)
                {
                    pos = false;
                    break;
                }
                hash[j - 1] = 2;
            }
        }
        if (pos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}