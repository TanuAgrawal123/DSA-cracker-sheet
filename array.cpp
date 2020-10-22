//Question : Given an array a[] of N positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N, sum;
	cin>>T;
	while(T--){
	    cin>>N;
	    sum=0;
	    int arr[N], flag=1;
	    for (int i=0 ;i<N; i++){
	        cin>>arr[i];
	        
	        
	        
	    }
	    unordered_set<int> res;
	    for(int i=0; i<N; i++){
	        sum+=arr[i];
	        if (sum==0 || res.find(sum) != res.end()){
	            cout<<"Yes"<<endl;
	            flag=0;
	            break;
	        } 
	        res.insert(sum);
	        
	    }
	    if (flag==1){
	        cout<<"No"<<endl;
	    }
	    
	}
	return 0;
}
    
    