#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
 

int partition(int A[], int n){
    int j = 0;
    int pivot = 0;    
 
    for (int i = 0; i < n; i++){
        if (A[i] < pivot){
            swap(A[i], A[j]);
            j++;
        }
    }
    return j;
}
 
int rearrange(int A[], int size)
{
    int p = partition(A, size);
    for (int n = 0; (p < size && n < p); p++, n += 2) {
        swap(A[n], A[p]);
    }
}
 
int main()
{
    int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int n = sizeof(A)/sizeof(A[0]);
 
    rearrange(A, n);
 
    // print the rearranged array
    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i];
    }
 
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// class Solution{
// public:

// 	void rearrange(int arr[], int n) {
//         int input,sizep=0,sizen=0;
// 	    vector<int> p;
//         vector<int> neg;
//         for(int i=0;i<n;i++){
//             input=*(arr+i);
//             if(input>=0){
//                 p.push_back(input);
//                 sizep++;
//             }
//             else{
//                 neg.push_back(input);
//                 sizen++;
//             }
//         }
//         int positive=0,negtive=0,positionx=0,positony=0;
//         for(int i=0;i<n;i++){
//             if(i%2==0 && positive<sizep){
//                 arr[i]=p[positive];
//                 positive++;
//             }
//             else if(i%2!=0 && negtive<=sizen){
//                 arr[i]=neg[negtive];
//                 negtive++;
//             }
//             else{
//                 if(positive>=sizep){
//                     arr[i]=neg[negtive];
//                     negtive++;
//                 }
//                 else{
//                     arr[i]=p[positive];
//                     positive++;
//                 }
//             }
//         }
// 	}
// };



// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, i;
//         cin >> n;
//         int arr[n];
//         for (i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         Solution ob;
//         ob.rearrange(arr, n);
//         for (i = 0; i < n; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
