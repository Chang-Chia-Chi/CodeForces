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
    def dfs(curr, num, path):
      if len(path) == num: return

      for d in [-4, -3, -2, 2, 3 ,4]:
        nxt = curr + d
        if nxt < 1 or nxt > num: continue
        if nxt in visited: continue
        visited.add(nxt)
        path.append(nxt)
        yield dfs(nxt, num, path)
        if len(path) == num: return
        path.pop()
        visited.remove(nxt)

    cases = inp()
    for _ in range(cases):
      num = inp()
      isOK = False
      for i in range(1, num+1):
        answer = [i]
        visited = set(answer)
        dfs(i, num, answer)
        if len(answer) == num:
          oupList(answer, " ")
          isOK = True
          break
      if not isOK: oupNum(-1)

if __name__ == '__main__':
    main()