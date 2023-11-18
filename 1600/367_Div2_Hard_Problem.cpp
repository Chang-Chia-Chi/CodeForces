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
  int n;
  cin >> n;
  vector<ll> costs(n, 0);
  for (int i=0; i<n; i++)
    cin >> costs[i];
  
  vector<string> original(n);
  vector<string> reversed(n);
  for (int i=0; i<n; i++)
  {
    cin >> original[i];
    string rev = original[i];
    for (int j=0; j<rev.size()/2; j++)
      swap(rev[j], rev[rev.size()-1-j]);
    reversed[i] = rev;
  }

  vector<vector<ll>> dp(n, vector<ll>(2, LONG_LONG_MAX/2));
  dp[0][0] = 0; dp[0][1] = costs[0];
  for (int i=1; i<n; i++)
  {
    if (reversed[i] >= reversed[i-1] && dp[i-1][1] < LONG_LONG_MAX/2)
      dp[i][1] = min(dp[i][1], dp[i-1][1]+costs[i]);
    if (reversed[i] >= original[i-1] && dp[i-1][0] < LONG_LONG_MAX/2)
      dp[i][1] = min(dp[i][1], dp[i-1][0]+costs[i]);
    if (original[i] >= reversed[i-1] && dp[i-1][1] < LONG_LONG_MAX/2)
      dp[i][0] = min(dp[i][0], dp[i-1][1]);
    if (original[i] >= original[i-1] && dp[i-1][0] < LONG_LONG_MAX/2)
      dp[i][0] = min(dp[i][0], dp[i-1][0]);
  }

  ll answer = min(dp[n-1][0], dp[n-1][1]);
  if (answer >= LONG_LONG_MAX/2) answer = -1;
  cout << answer << endl;
  return 0;
}
