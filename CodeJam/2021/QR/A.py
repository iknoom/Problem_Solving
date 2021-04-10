import sys
input = sys.stdin.readline

# Reversort(L):
#   for i in range(1, N)
#       j := minimum value between i and N
#       Reverse(L[i..j])

def solution():
    N = int(input())
    L = list(map(int, input().split()))
    answer = 0
    for i in range(N - 1):
        value = min(L[i:])
        for j in range(i, N):
            if L[j] == value:
                L[i : j+1] = reversed(L[i : j+1])
                answer += j - i + 1
                break
    return answer

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        answer = solution()
        print("Case #"+str(case) + ":", answer)