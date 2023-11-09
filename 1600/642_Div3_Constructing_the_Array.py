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
      oupList(func(), " ")

def func():
  n = inp()
  heap = [[-n, 1, n]]
  answer = [0] * n
  ops = 1
  while heap:
    length, left, right = heapq.heappop(heap)
    applyID = (left+right)//2
    if -length % 2 == 0: applyID = (left+right-1)//2
    answer[applyID-1] = ops
    ops += 1
    if -length > 1:
      leftLen, rightLen = applyID-left, right-applyID
      if leftLen:
        heapq.heappush(heap, [-leftLen, left, applyID-1])
      if rightLen:
        heapq.heappush(heap, [-rightLen, applyID+1, right])
  return answer
    


if __name__ == '__main__':
    main()