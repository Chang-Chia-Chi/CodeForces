#include <utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>

using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int MOD = 1000000007;

// ========== Math Trick ==========
vector<int>Eratosthenes(int n)
{
    vector<int>q(n+1,0);
    vector<int>primes;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (q[i]==1) continue;
        int j=i*2;
        while (j<=n)
        {
            q[j]=1;
            j+=i;
        }
    }        
    for (int i=2; i<=n; i++)
    {
        if (q[i]==0)
            primes.push_back(i);                
    }
    return primes;
}

ll gcd(ll a, ll b) {
  return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}

int fpow(int a, int b, int m) {
  a %= m;
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


// ========== Main Function ==========
int main() {
  int t, k;
  cin >> t;
  cin >> k;

  vector<ll> cnts(100005, 0);
  vector<ll> prefix(100005, 0);
  for (int i=1; i<=100000; i++)
  {
    if (i<k) cnts[i] = 1;
    else if (i==k) cnts[i] = 2;
    else cnts[i] = (cnts[i-1]+cnts[i-k]) % MOD;
    prefix[i] = (cnts[i]+prefix[i-1]) % MOD;
  }

  ll a, b;
  for (int i=0; i<t; i++)
  {
    cin >> a;
    cin >> b;
    cout << (prefix[b]-prefix[a-1]+MOD) % MOD << endl;
  }

  return 0;
}
