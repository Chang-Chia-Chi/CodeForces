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
    ncases = inp()
    for _ in range(ncases):
      n = inp()
      arr = [int(s) for s in insr()]

      answer, prefix = 0, 0
      preCnt = Counter()
      preCnt[0] = 1
      for i in range(n):
        prefix += arr[i]
        diff = prefix - (i+1)
        answer += preCnt[diff]
        preCnt[diff] += 1
      oupNum(answer)


if __name__ == '__main__':
    main()