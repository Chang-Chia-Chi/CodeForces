import sys
from collections import deque, defaultdict, Counter

input = sys.stdin.readline

############ Input Functions ############
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


############ Main Function ############
def main():
    m = inp()
    nums = inlt()
    counter = Counter(nums)
    uniqNums = list(counter.keys())
    uniqNums.sort()

    n = len(uniqNums)
    dp = [[0, 0] for _ in range(n)]
    dp[0][1] = counter[uniqNums[0]] * uniqNums[0]
    for i in range(1, n):
      dp[i][0] = max(dp[i-1][0], dp[i-1][1])
      dp[i][1] = max(dp[i][1], dp[i-1][0]+counter[uniqNums[i]]*uniqNums[i])
      if i > 0 and uniqNums[i] - uniqNums[i-1] > 1:
        dp[i][1] = max(dp[i][1], dp[i-1][1]+counter[uniqNums[i]]*uniqNums[i])

    oupNum(max(dp[n-1]))



if __name__ == '__main__':
    main()