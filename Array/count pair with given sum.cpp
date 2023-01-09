//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        vector<int> v(k,0);
        for(int i=0;i<n;i++)
        {
            if(arr[i]<k)
             v[arr[i]]++;
        }
        int i=1;
        int j=k-1;
        int sum=0;
        while(i<j)
        {
            sum+=v[i]*v[j];
            i++;
            j--;
        }
        if(k%2==0)
         sum+=(v[k/2]*(v[k/2]-1))/2;
         return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends
