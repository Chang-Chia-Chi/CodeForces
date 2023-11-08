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
    @bootstrap
    def dfs(prev, curr, depth):
      subs = 0
      for nxt in graph[curr]:
        if nxt == prev: continue
        subs += yield dfs(curr, nxt, depth+1)
      if len(heap) <= k or heap[0] < depth:
        heapq.heappush(heap, depth - subs)
      if len(heap) > k: heapq.heappop(heap)
      return subs + 1

    n, k = inlt()
    graph = defaultdict(list)
    for _ in range(n-1):
      a, b = inlt()
      graph[a].append(b)
      graph[b].append(a)
    
    heap = []
    dfs(-1, 1, 0)
    oupNum(sum(heap))

if __name__ == '__main__':
    main()