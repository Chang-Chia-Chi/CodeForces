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

def oupMazeRow(lst):
    sys.stdout.write("".join(map(str, lst)) + "\n")


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
    m, n, k = inlt()
    maze = [['.' for _ in range(n)] for _ in range(m)]
    walls = 0
    sr, sc = -1, -1
    visited = set()
    for r in range(m):
      row = insr()
      for c in range(n):
        if row[c] == '#':
          visited.add((r, c))
          maze[r][c] = '#'
          walls += 1
        else:
          if sr == -1:
            sr, sc = r, c

    tarSteps = m*n - walls - k - 1
    visited.add((sr, sc))
    queue = deque([(sr, sc)])
    while queue and tarSteps:
      lvsize = len(queue)
      while lvsize and tarSteps:
        r, c = queue.popleft()
        lvsize -= 1
        for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
          nr, nc = r+dr, c+dc
          if nr < 0 or nr >= m or nc < 0 or nc >= n: continue
          if (nr, nc) in visited: continue
          tarSteps -= 1
          visited.add((nr, nc))
          queue.append((nr, nc))
          if tarSteps == 0: break

    for r in range(m):
      for c in range(n):
        if (r, c) not in visited:
          maze[r][c] = 'X'
    
    for r in range(m):
      oupMazeRow(maze[r])



if __name__ == '__main__':
    main()