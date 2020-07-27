import sys
f_name = "alchemy"
sys.stdin = open(f_name + "_input.txt", 'r')
sys.stdout = open(f_name + "_output.txt", 'w')

def solution():
    N = int(input())
    C = input().rstrip()
    cnt_B = cnt_A = 0
    for i in range(N):
        if C[i] == 'A': cnt_A += 1
        if C[i] == 'B': cnt_B += 1
    if abs(cnt_A - cnt_B) == 1:
        return 'Y'
    else:
        return 'N'

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T + 1):
        y_n = solution()
        print(f"Case #{case}: {y_n}")