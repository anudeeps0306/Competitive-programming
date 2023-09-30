#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl


    int n;
    cin >> n;
    vector<int> nums(n), diff;
    

    FOR(i, n) {
        cin >> nums[i];
    }

   

    diff.resize(n + 1, 0);

    FOR(i, n) {
        diff[nums[i]]--;
    }
    
    int sum = n;
    FOR(i, n) {
        if (nums[i] != diff[i] + sum) {
            isValid = 0;
            break;
        }
        sum += diff[i];
        diff[i] = 0;
    }

    if (isValid == 1) {
        YES;
    } else {
        NO;
    }

    return 0;
}
