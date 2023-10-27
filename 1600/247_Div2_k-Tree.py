import sys
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
    @bootstrap
    def dfs(rest, k, depth, must, hasMust):
      if rest < 0: return 0
      if rest == 0 and hasMust: return 1
      if rest == 0: return 0
      
      if (rest, depth, hasMust) in memo:
        return memo[(rest, depth, hasMust)]
  
      answer = 0
      for n in range(1, k+1):
        answer += yield dfs(rest-n, k, depth+1, must, hasMust or n >= must)
      memo[(rest, depth, hasMust)] = answer
      return answer

    total, k, must = inlt()
    memo = {}
    oupNum(dfs(total, k, 0, must, False) % MOD)


if __name__ == '__main__':
    main()