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
    n, potions = inp(), inlt()
    dp2 = [float('-inf') for _ in range(n+1)]
    dp2[0] = 0
    for i in range(1, n+1):
      dp1 = [float('-inf') for _ in range(n+1)]
      for j in range(i+1):
        dp1[j] = dp2[j]
        if j > 0 and dp2[j-1] >= 0:
          dp1[j] = max(dp1[j], dp2[j-1]+potions[i-1])

      dp1, dp2 = dp2, dp1

    answer = 0
    for j in range(1, n+1):
      if dp2[j] >= 0:
        answer = j
    
    oupNum(answer)

if __name__ == '__main__':
    main()