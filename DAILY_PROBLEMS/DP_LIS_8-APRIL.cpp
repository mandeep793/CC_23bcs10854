#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans, dp[i]);

    return ans;
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Length of LIS = "<<LIS(arr);

    return 0;
}
