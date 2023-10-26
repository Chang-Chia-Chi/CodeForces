import sys
from collections import deque, defaultdict, Counter

############ ---- Input Functions ---- ############
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

############ ---- Output Functions ---- ############
def oupNum(n):
    sys.stdout.write(str(n) + "\n")

def oupList(lst):
    sys.stdout.write(" ".join(map(str, lst)) + "\n")

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
    n, m = inlt()
    cats = inlt()
    cats.insert(0, 0)
    graph = defaultdict(list)
    while True:
      edge = inlt()
      if not edge: break
      graph[edge[0]].append(edge[1])
      graph[edge[1]].append(edge[0])

    oupNum(dfs(-1, 1, m, 0, graph, cats))

@bootstrap
def dfs(parent, curr, sumLimit, conSum, graph, cats):
  if cats[curr]:
    conSum += 1
  else:
    conSum = 0

  if conSum > sumLimit: return 0
  if len(graph[curr]) == 1 and graph[curr][0] == parent: return 1


  answer = 0
  for nxt in graph[curr]:
    if nxt == parent: continue
    answer += yield dfs(curr, nxt, sumLimit, conSum, graph, cats)
  return answer


if __name__ == '__main__':
    main()