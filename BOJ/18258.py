import sys
from collections import deque
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    queue = deque([])
    for _ in range(N):
        query = input().rstrip()
        if query == "pop":
            if not queue: print(-1)
            else: print(queue.popleft())
        elif query == "size":
            print(len(queue))
        elif query == "empty":
            if not queue: print(1)
            else: print(0)
        elif query == "front":
            if not queue: print(-1)
            else: print(queue[0])
        elif query == "back":
            if not queue: print(-1)
            else: print(queue[-1])
        else:
            queue.append(int(query[5:]))
