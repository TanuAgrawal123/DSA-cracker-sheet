// Sieve of Eratosthenes and segmented sieve

//Question  generate all prime numbers between two given numbers!
#include "bits/stdc++.h"
using namespace std;

#define FASTIO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef vector<int> vi;
typedef vector <vector <int> > vii;
typedef pair<int, int> pii;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define loop(a, c) for (long long(a) = 0; (a) < (c); (a)++)
#define loopl(a, b, c) for (long long(a) = (b); (a) <= (c); (a)++)
#define loopr(a, b, c) for (long long(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define rev(a) reverse(a.begin(),a.end())
#define int long long

typedef vector<long long> vll;
typedef vector <vector <long long> > vvll;
typedef pair<long long,long long> pllll;

const int mod=1e9+7;

int32_t main()
{
FASTIO
int T, N,M;
vector<bool> v(100000,1);
v[0]=v[1]=0;
    // logic for Sieve of Eratosthenes
for(int p=2;p*p<=100000;p++){
    if (v[p]==1){
        for(int i=p*p ; i<=100000;i+=p ){
            v[i]=0;
            
        }
    }
}
vector<int>prime;

for(int i=0;i<100000;i++){
   if (v[i]==1)
   {
      
       prime.push_back(i);
       
   }
   
   
   
}
cin>>T;
int j;
for(int i=0;i<T;i++){
    cin>>M>>N;
    // logic for segmented seive
   vector<bool> sv(N-M+1, true);
   if (M==1)
   M++;
   for(int i=0;(prime[i]*prime[i])<=N;i++){
       j=(M/prime[i])*prime[i];
       if (j<M){
           j+=prime[i];
           
       }
       for(;j<=N;j+=prime[i]){
           if(j!=prime[i]){
               sv[j-M]=false;
               
           }
       }
   }
   for(int i=M;i<=N;i++){
       if(M<=1){
           continue;
         
       }
       if(sv[i-M]==true){
           cout<<i<<endl;
           
           
           
           
       }
   
   }



}
    return 0;
}


//ques- Given a number, find the total number of divisors of the factorial of the number.

//Since the answer can be very large, print answer modulo 109+7.

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define FASTIO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

const int mod=1e9+7;
int main()
{FASTIO
    int T,N;
    cin>>T;
    vector<bool>v(50001, true);
    v[0]=v[1]=false;
    for(int p=2;p*p<=50001;p+=1){
        if(v[p]==true)
        { for(int i=p*p;i<=50001;i+=p){
            v[i]=false;
            
        }
            
        }
        
    }
    vector<int> prime;
    for(int i=0;i<=50000;i++){
        if(v[i]==true){
            prime.push_back(i);
            
        }
    }
    while(T--){
        cin>>N;
        long long result=1;
        for(int i=0; prime[i]<=N;i++){
            int k=prime[i];
            long long count=0;
            while(N/k!=0){
                count=(count+(N/k))%mod;
                k=k*prime[i];
            }
            result=(result*(count+1))%mod;
            
        }
        cout<<result<<endl;
    }     
         return 0;
    
}










