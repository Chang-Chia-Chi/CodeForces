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
const int N = 1e5 + 5;
int dp[N][6][2];
int func1() {  
  int n, K, Z;
  cin >> n; cin >> K; cin >> Z;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  
  dp[0][0][0] = nums[0];
  for (int k = 1; k <= K; k++)
  {
    for (int z = 0; z <= Z && 2*z <= k; z++)
    {
      int i = k - 2*z;
      dp[k][z][0] = max(dp[k-1][z][1], dp[k-1][z][0]) + nums[i];
      if (z > 0)
        dp[k][z][1] = dp[k-1][z-1][0] + nums[i];
    }
  }

  int answer = 0;
  for (int z = 0; z <= Z; z++)
  {
    answer = max(answer, dp[K][z][0]);
    answer = max(answer, dp[K][z][1]);
  }
  return answer;
}

int func2() {
  int n, K, Z;
  cin >> n; cin >> K; cin >> Z;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  
  int best = 0;
  int prefix = 0;
  int answer = 0;
  for (int i = 0; i <= K; i++)
  {
    best = max(best, nums[i] + nums[i+1]);
    prefix += nums[i];
    if ((K-i) % 2) continue;
    int jumps = min(Z, (K-i) / 2);
    answer = max(answer, prefix + jumps*best);
  }
  return answer;
}

int main() {
  int cs;
  cin >> cs;
  for (int i = 0; i < cs; i++)
    cout << func2() << endl;
  return 0;
}
