#include <utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

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
int solve() {
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> nums(n);
  for (int i=0; i<n; i++)
    cin >> nums[i];
  
  if (n == 1) {
    if (nums[0] > k-1) {
      cout << k-1 << endl;
      return 0;
    }
    cout << k << endl;
    return 0;
  }

  ll g = nums[0];
  for (int i=1; i<n; i++) {
    g = gcd(g, nums[i]);
  }

  ll curr = 0;
  for (int i=1; i<n; i++) {
    if (g - 1 >= k) {
      cout << curr + k << endl;
      return 0;
    }
    curr += g;
    k -= (g-1);
  }
  cout << curr + k << endl;
  return 0;
}

int main() {
  int c;
  cin >> c;
  for (int i=0; i < c; i++)
    solve();
  return 0;
}
