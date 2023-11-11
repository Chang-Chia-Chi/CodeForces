import sys
import math
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


############ Math Trick ############ 
def lcm(a, b):
  return a // math.gcd(a, b) * b


def main():
    cases = inp()
    for _ in range(cases):
      oupList(func(), " ")
  
def func():
  n, k = inlt()
  ones = k-3
  return lcm3(n-ones) + [1] * ones

def lcm3(n):
  if n % 2 == 1:
    return [(n-1)//2, (n-1)//2, 1]
  
  if (n // 2) % 2 == 1:
    return [(n-2)//2, (n-2)//2, 2]
  return [n//2, n//4, n//4]

if __name__ == '__main__':
    main()