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
      x1, y1, x2, y2 = inlt()
      width, height = x2-x1, y2-y1
      minDim = min(width, height)
      maxDim = max(width, height)
      sameAmount = max(0, maxDim - minDim - 1)
      answer = (1+minDim)*minDim + sameAmount*minDim + 1
      if maxDim == minDim:
        answer -= maxDim
      oupNum(answer)

if __name__ == '__main__':
    main()