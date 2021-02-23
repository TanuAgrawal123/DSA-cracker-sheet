//Calculate square of a number without using *, / and pow()


//approach 1 : is to repeatedly add n to result. 
// approach2 :log(n)
/* If n is even, it can be written as
   n = 2*x 
  n2 = (2*x)2 = 4*x2
If n is odd, it can be written as 
  n = 2*x + 1
  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1 */

#include <bits/stdc++.h>

using namespace std;
int square(int n){
    if (n==0)
    return 0;
       
   
   int x=n>>1;
   
   if(n & 1){
       return ((square(x)<<2) +(x<<2) + 1);}
     else{
         return square(x)<<2;
         
     }
       
   }
int main()
{ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
   int n;
   cin>>n;
   cout<<square(n);
   
   
    return 0;
}
