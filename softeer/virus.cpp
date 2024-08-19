#include<iostream>
using namespace std;

long long solve(long long k, long long p, long long n)
{
    if(n==0) return 1;
    if(n==1) return p;
    if(n%2 == 0){
        long long tmp = solve(k, p, n / 2) % 1000000007;
        return (tmp * tmp) % 1000000007;
    } 
    else{
        return ((solve(k, p, n/2) % 1000000007) * (solve(k, p, n/2+1) % 1000000007)) % 1000000007;
    }
}

int main(int argc, char** argv)
{
    long long n, k, p;
    cin >> k >> p >> n;
    n *= 10;
    cout << (k * solve(k,p,n)) % 1000000007;
    
}