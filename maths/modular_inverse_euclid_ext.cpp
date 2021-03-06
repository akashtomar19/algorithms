#include<bits/stdc++.h>
using namespace std;
int modinverse_iterative_naive(int a,int m){
    a = a%m;
    for(int x=1;x<m;x++){
        if((a*x)%m == 1)return x;
    }
}
///using gcdExtended
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

int main(){
    int a = 3;
    int m = 11;
    modInverse(a,m);
}
