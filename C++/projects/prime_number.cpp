#include <bits/stdc++.h>
using namespace std;

#define ll long long
// class to generate prime numbers in range [0,10^8)
class Prime
{
    bitset<10000000> bt;

public:
    Prime()
    {
        bt.set();
        bt[0] = bt[1] = 0;
        for (ll i = 2; i * i < 10000000; i++)
        {
            if (bt[i])
                for (ll j = i * i; j < 10000000; j += i)
                    bt[j] = 0;
        }
    }
    bool isPrime(ll x)
    {
        if (x < 2)
            return false;
        else if (x < bt.size())
            return bt[x];
        for (ll i = 2; i * i <= x; i++)
        {
            if (!(x % i))
                return false;
        }
        return true;
    }
} primeNumbers;

int main()
{

    // use:
    // primeNumbers.isPrime(x) -> true if x is prime, false otherwise

    primeNumbers.isPrime(2) ? cout << "Yes" : cout << "No";
    cout << endl;
    primeNumbers.isPrime(10061) ? cout << "Yes" : cout << "No";
    cout << endl;
    primeNumbers.isPrime(10065) ? cout << "Yes" : cout << "No";
    return 0;
}