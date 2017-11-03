#include <iostream>
using namespace std;
typedef long long ll;

int bit(ll x, int i) { return (x >> i) & 1LL; }
ll bitOn(ll x, int i) { return (1LL << i) | x; }
ll bitOff(ll x, int i) { return (~(1LL << i)) & x; }
ll bitInv(ll x, int i) { return (1LL << i) ^ x; }


ll leftMost1(ll x) {
    for(int i = 62; i >= 0; i--) 
        if (bit(x, i) == 1) return i;
    return -1;
}