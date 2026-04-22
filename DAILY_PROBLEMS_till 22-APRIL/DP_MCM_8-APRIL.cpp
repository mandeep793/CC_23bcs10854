#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MCM(vector<int>& arr){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int len=2; len<n; len++){

        for(int i=1; i<n-len+1; i++){

            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++){

                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}

int main(){
    int n;

    cout<<"Enter number of matrices: ";
    cin>>n;

    vector<int> arr(n+1);

    cout<<"Enter dimensions array: ";
    for(int i=0;i<=n;i++)
        cin>>arr[i];

    cout<<"Minimum multiplication cost = "<<MCM(arr);

    return 0;
}