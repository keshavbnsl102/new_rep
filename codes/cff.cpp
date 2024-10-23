#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ek long long 
#define dow pair<ek,ek>
#define teen pair<ek,dow> 
#define pb push_back
#define mp make_pair
const double pi=3.14159265358979323846;
ek yes=998244353;
 
long long gcd(long long a,long long b)
{ long long temp;  
  if(a<b)
  {temp=b;
    b=a;
    a=temp;
  }
  if(a%b==0)
  {return b;}
   return gcd(b,a%b);
}
ek modu(ek a,ek b)
{
    if(a<0)
    {a=-1*a;
    return (b-a%b)%b;
    }
    else
    {return a%b;}
 
}
long long lcm(long long a,long long b,long long c,long long d)
{
  long long temp;  
  if(a<b)
  {temp=b;
    b=a;
    a=temp;
  }
 
if(a%b==0)
  {return (c*d)/b;}
   
   return lcm(b,a%b,c,d);
 
}
ek powers(ek a,ek b,ek c)
{
   ek ans=1;
   while(b>0)
   {
       if(b%2==1)
         {ans=((ans%c)*(a%c))%c;}
         b=b/2;
        a=((a%c)*(a%c))%c;
 
   }
return ans;
 
}
 

 


bool prime[1000005];
void SieveOfEratosthenes(ek n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    
    for(int i=0;i<=n;i++){
		prime[i]=true;
	}
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (ek i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    
}

int main()
{
 ek i,j,k,z,t,f,ans,ma,mi,a,b,c,d,y,mid,m,g,x,h,x1,y1,x2,y2,o,p,l,r,q,n,ab;
 cin>>t;
 
	 
	 
	 

          
return 0;
}

