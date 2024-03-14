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
bool isOK() {
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> seq(n, 0);
  map<int, vector<int>> graph;
  map<int, int> indegree;
  for (int i=1; i<=n; i++)
    indegree[i] = 0;
  for (int i=0; i<k; i++)
  {
    for (int i=0; i<n; i++)
      cin >> seq[i];
    
    for (int j=1; j<n-1; j++)
    {
      int a = seq[j];
      int b = seq[j+1];
      graph[a].push_back(b);
      indegree[b]++;
    }
  }

  int nodeCnt = 0;
  deque<int> Queue;
  for (auto &node: indegree)
  {
    if (node.second == 0)
    {
      Queue.push_back(node.first);
      nodeCnt++;
    }
  }

  while (!Queue.empty())
  {
    int lvsize = Queue.size();
    for (int i=0; i<lvsize; i++)
    {
      int node = Queue.front();
      Queue.pop_front();
      for (int j=0; j<graph[node].size(); j++)
      {
        int nxt = graph[node][j];
        if (indegree[nxt] == 0) continue;
        indegree[nxt]--;
        if (indegree[nxt] == 0)
        {
          Queue.push_back(nxt);
          nodeCnt++;
        }
      }
    }
  }
  return nodeCnt == n;
}

int main() {
  int cases;
  cin >> cases;
  for (int i=0; i<cases; i++)
  {
    if (isOK()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
