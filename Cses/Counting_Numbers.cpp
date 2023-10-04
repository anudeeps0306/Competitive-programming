#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(ll num, vector<ll>& dp) {
    if (num < 1)
        return num == 0 ? 1 : 0;
    string numString = to_string(num);
    ll result = 0;
   
    for (int i = 0; i < numString.size(); i++) {
        result += dp[i];
    }

    int prevDigit = 0;
    for (int i = 0; i < numString.size(); i++) {
        int digit = numString[i] - '0';
        int diff = numString.size() - i - 1;
        int below = prevDigit < digit ? digit - 1 : digit;
        result += (digit == 0) ? 0 : below * dp[diff];
        if (digit == prevDigit)
            return result;
        prevDigit = digit;
    }
    return result + 1;
}

int main() {
    ll a, b;
    cin >> a >> b;

    vector<ll> dp(19);
    dp[0] = 1;
    ll multiplier = 1;
    for (int i = 1; i < 19; i++) {
        multiplier *= 9;
        dp[i] = multiplier;
    }

    cout << (f(b, dp) - f(a - 1, dp));

    return 0;
}
