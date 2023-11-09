import sys
import heapq
from collections import deque, defaultdict, Counter

############ constants ############
MOD = 1000000007

############ Input Functions ############
input = sys.stdin.readline

def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

############ Output Functions ############
def oupNum(n):
    sys.stdout.write(str(n) + "\n")

def oupList(lst, sep):
    sys.stdout.write(sep.join(map(str, lst)) + "\n")


############ Recursion Trick ############ 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = stack.append(f(*args, **kwargs))
            while True:
                try:
                    to = stack.append(stack[-1].send(to))
                except StopIteration as e:
                    stack.pop()
                    to = e.value
                    if not stack:
                        break
            return to
    return wrappedfunc


def main():
    cases = inp()
    for _ in range(cases):
      oupNum(func())

def func():
  @bootstrap
  def dfs(prev, curr):
    answer = 0
    for nxt in graph[curr]:
      if nxt == prev: continue
      answer += yield dfs(curr, nxt)
    subNodesCnt[curr] = answer
    return answer + 1

  p1, p2 = 'Ayush', 'Ashish'
  n, x = inlt()
  graph = defaultdict(set)
  for _ in range(n-1):
    a, b = inlt()
    graph[a].add(b)
    graph[b].add(a)

  subNodesCnt = Counter()
  dfs(-1, x)
  if subNodesCnt[x] % 2 or len(graph[x]) <= 1: return p1
  return p2


if __name__ == '__main__':
    main()