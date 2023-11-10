import sys
import random
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
  n = inp()
  health, damage = [0]*n, [0]*n
  for i in range(n):
    health[i], damage[i] = inlt()

  answer = 0
  prevDamage = 0
  for i in range(n):
    answer += max(0, health[i]-prevDamage)
    prevDamage = damage[i]

  curr = answer
  for i in range(1, n):
    more = min(health[i], damage[i-1])
    less = min(health[i-1], damage[i-2])
    curr += more - less
    answer = min(answer, curr)
  return answer

if __name__ == '__main__':
    main()