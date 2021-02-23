
// Question Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of //elements in both parts is the same.


#include <bits/stdc++.h>
using namespace std;


 class Solution{
public:

    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++){
            if (sum+=arr[i]);
            
        }
        if (sum%2!=0){
            return 0;
            
        }
        else
        {
       bool result[sum/2 + 1][N+1];
   for (int i=0;i<=sum/2;i++)
   result[i][0]=false;
   for(int i=0; i<=N; i++){
       result[0][i]=true;
   }
        for (int i=1 ;i<=sum/2; i++){
            for (int j=1; j<=N; j++){
                
                
                    result[i][j]=result[i][j-1];
                    if(i>=arr[j-1])
                    result[i][j]=result[i][j] || result[i-arr[j-1]][j-1];
                 
                }    
                }
            
            if (result[sum/2][N])
            return 1;
            else
            return 0;
            
        }  
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}


//Given an integer array nums, return the length of the longest strictly increasing subsequence.

int lengthOfLIS(vector<int>& nums) {
      vector<int> vec(nums.size(), 1);
        int maxval=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if (nums[j]<nums[i]){
                    vec[i]=max(vec[j]+1, vec[i]);
                    
                    
                }
                
                
            }
        if (maxval<vec[i]){
            maxval=vec[i];
            
        }
            
            
        }
        
       return maxval; 
    }












