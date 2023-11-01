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
    def isOK(times):
      used = 0
      for i in range(3):
        need = times * counter[i] - already[i]
        if need > 0:
          used += prices[i] * need
      return used <= money

    comb = insr()
    counter = [0] * 3
    matToID = {'B':0, 'S':1, 'C':2}
    for mat in comb:
      counter[matToID[mat]] += 1
    already = inlt()
    prices = inlt()
    money = inp()

    left = 0
    right = 10000000000000
    while left < right:
      mid = right - (right-left)//2
      if isOK(mid):
        left = mid
      else:
        right = mid-1
    oupNum(left)
    

if __name__ == '__main__':
    main()