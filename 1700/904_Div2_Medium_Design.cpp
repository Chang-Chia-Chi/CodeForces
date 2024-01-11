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
int fetchMaxOverlaps(vector<PII>& arr) {
  sort(arr.begin(), arr.end());
  
  map<int, int> starts;
  map<int, vector<int>> ends;
  int n = arr.size();
  int answer = 0;
  int curr = 0;
  for (int i=0; i<n; i++)
  {
    while (!ends.empty() && ends.begin()->first < arr[i].first)
    {
      for (auto j: ends.begin()->second)
      {
        curr -= 1;
        starts[arr[j].first] -= 1;
        if (starts[arr[j].first] == 0) starts.erase(arr[j].first);
      }
      ends.erase(ends.begin());
    }
    curr += 1;
    starts[arr[i].first] += 1;
    ends[arr[i].second].push_back(i);
    answer = max(answer, curr);
  }
  return answer;
}

int helper() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<PII> arr1;
  vector<PII> arr2;
  for (int i=0; i<n; i++)
  {
    int l, r;
    cin >> l;
    cin >> r;
    if (l > 1)
      arr1.push_back({l, r});
    if (r < m)
      arr2.push_back({l, r});
  }

  int answer1 = fetchMaxOverlaps(arr1);
  int answer2 = fetchMaxOverlaps(arr2);
  cout << max(answer1, answer2) << endl;
  return 0;
}

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
    helper();
  return 0;
}
