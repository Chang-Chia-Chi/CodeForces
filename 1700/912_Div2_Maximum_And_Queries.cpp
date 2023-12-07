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

ll solve(vector<int> nums, ll k)
{
  int n = nums.size();
  ll ans = 0;
  for (ll b=60; b>=0; b--)
  {
    ll ops = 0;
    for (int i=0; i<n; i++)
    {
      if (((ll)nums[i]>>b) & (ll)1) continue;
      ops += ((ll)1 << b) - (ll)nums[i] % ((ll)1 << b);
      if (ops > k) break;
    }

    if (ops <= k)
    {
      k -= ops;
      ans += (ll)1<<b;
      for (int i=0; i<n; i++)
      {
        if (((ll)nums[i]>>b) & (ll)1) continue;
        nums[i] -= (int)((ll)nums[i] % ((ll)1 << b));
      }
    }
  }
  return ans;
}

int main() {
  int n, q;
  cin >> n;
  cin >> q;
  vector<int> nums(n, 0);
  for (int i=0; i<n; i++)
    cin >> nums[i];
  
  ll k;
  for (int i=0; i<q; i++)
  {
    cin >> k;
    cout << solve(nums, k) << endl;
  }

  return 0;
}