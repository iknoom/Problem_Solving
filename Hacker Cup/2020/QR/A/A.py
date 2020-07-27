import sys
f_name = "travel_restrictions"
sys.stdin = open(f_name + "_input.txt", 'r')
sys.stdout = open(f_name + "_output.txt", 'w')

def solution():
    N = int(input())
    incoming = input().rstrip()
    outcoming = input().rstrip()
    answer = [['N'] * N for _ in range(N)]
    for i in range(N):
        answer[i][i] = 'Y'
        for j in range(i - 1, -1, -1):
            if outcoming[j + 1] == 'N': break
            if incoming[j] == 'N': break
            answer[i][j] = 'Y'
        for j in range(i + 1, N):
            if outcoming[j - 1] == 'N': break
            if incoming[j] == 'N': break
            answer[i][j] = 'Y'
    return answer

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T + 1):
        M = solution()
        print(f"Case #{case}:")
        for row in M:
            print(''.join(row))