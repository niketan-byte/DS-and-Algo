//  Fermat theorem application

// 1) Modulo Inverse
// a^p = a(mod p)

// If a is not divisible by p,
// a^p-1 = 1(mod p)  
// On multiplying by a^-1
// a^p-2 = a^-1(mod p)

// 2) Binary Exponentiation
// 3) (a/b)%m = (a%m)*(b^-1 % m) % m

// 4) (nCr)%p
// if p>n
// 1) pre calculate factorial taking modulo p
// 2) nCr % p = (fac[n])*modInverse(fac[r])%p * modInverse(fac[n-r])%p) % p

// if n>=p than n! % p  = 0 because n! me p bhi to hoga


// Wilson Theorem
// A positive  integer n>1 is a prime if and only if
//  (n-1)! = -1(mod n)  or  (n-1)! = n-1(mod n)
// also vice versa is true    

// In other word, (n-1)! is 1 less than a multiple of n
// For eg, 101 is prime so 100! = 101k - 1 for some integer k 


// For eg Calculate (25! % 29)
// From Wilson theorem we know that 28! is -1
// So we need to find
// [(-1)*inverse(28,29)*inverse(27,29)*inverse(26,29)]%29



// Spoj Boring Factorial (calculate factorial of very very big number)
// if n>=p than 0
// if p > n than  (p-1)! = p-1(mod p)
// But we have to remove (n+1)*(n+2)*....(p-1) by taking inverse modulo
// for(int i=n+1;i<p;i++)
// {
//     res = (res * modInverse(i,p)) % p; 
// }


// O((p-n)*logn)
#include<bits/stdc++.h>
using namespace std;
#define int long long

int power(int x,int y,int p)
{
    int res=1;
    x = x%p;
    while(y>0)
    {
        if(y&1)
        {
            res = (res*x)%p;
        }
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}

int modInverse(int a,int p)
{
   return power(a,p-2,p);  // Fermat little theorem a^p-1 = a^-1(mod p)
}

int modfact(int n,int p)
{
    if(p <= n)
    {
        return 0;
    }
    int res = (p-1);
    for(int i=n+1;i<p;i++)
    {
        res = (res*modInverse(i,p))%p;
    }
    return res;
}

int32_t main()
{
    int n,p;
    cin>>n>>p;
    cout<<modfact(n,p);
    return 0;
}