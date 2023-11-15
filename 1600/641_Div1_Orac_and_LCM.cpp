#include<utility>
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
void initializeMap(int num, map<int, vector<int>>& map, vector<int>& primes) {
  for (auto p: primes)
  {
    int cnt = 0;
    while (num % p == 0)
    {
      cnt += 1;
      num /= p;
    }
    if (map.find(p) == map.end() && cnt)
      map[p].push_back(cnt);
    else if (map.find(p) != map.end())
      map[p].push_back(cnt);
  }
}

void factorize(int num, map<int, vector<int>>& map) {
  for (auto &p: map)
  {
    int cnt = 0;
    while (num % p.first == 0)
    {
      cnt += 1;
      num /= p.first;
    }
    map[p.first].push_back(cnt);
  }
}


ll method1() {
  int n;
  cin >> n;

  int x;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    nums.push_back(x);
  }

  map<int, vector<int>> primeMap;
  int maxNum = *max_element(nums.begin(), nums.end());
  vector<int> primes = Eratosthenes(maxNum);
  
  initializeMap(nums[0], primeMap, primes);
  initializeMap(nums[1], primeMap, primes);

  for (int i = 2; i < n; i++)
    factorize(nums[i], primeMap);

  ll answer = 1;
  for (auto &p: primeMap)
  {
    sort(p.second.begin(), p.second.end());
    if (p.second.size() == n-1)
      answer *= (ll)fpow(p.first, p.second[0], MOD);
    else if (p.second.size() == n)
      answer *= (ll)fpow(p.first, p.second[1], MOD);
  }

  return answer;
}

ll method2() {
  int n;
  cin >> n;

  ll x;
  vector<ll> nums;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    nums.push_back(x);
  }

  vector<ll> suf(n+1, 0);
  ll answer = 0;
  for (int i = n-1; i >= 0; i--)
  {
    answer = gcd(answer, lcm(nums[i], suf[i+1]));
    suf[i] = gcd(nums[i], suf[i+1]);
  }

  return answer;
}

int main() {
  // cout << method1() << endl;
  cout << method2() << endl;
  return 0;
}
