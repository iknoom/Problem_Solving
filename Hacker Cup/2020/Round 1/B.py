import sys
f_name = "dislodging_logs"
sys.stdin = open(f_name + "_input.txt", 'r')
sys.stdout = open(f_name + "_output.txt", 'w')

def det(P, Q, L):
    if L < 0: return False
    for p in P:
        t = []
        if not Q: break
        if abs(Q[-1] - p) > L: continue
        l = r = -1
        if Q[-1] < p:
            l = Q[-1]
            diff = L - (p - Q[-1])
            r = max(p + diff // 2, Q[-1] + diff)
        else:
            l = p
            r = l + L
        while Q and (l <= Q[-1] <= r):
            t.append(Q.pop())
    if Q:
        return False
    else:
        return True

def solution():
    N, M, K, S = map(int, input().split())
    P = list(map(int, input().split()))
    A_P, B_P, C_P, D_P = map(int, input().split())
    Q = list(map(int, input().split()))
    A_Q, B_Q, C_Q, D_Q = map(int, input().split())

    for i in range(K, N):
        P_i = (A_P * P[-2] + B_P * P[-1] + C_P) % D_P + 1
        P.append(P_i)
    for i in range(K, M):
        Q_i = (A_Q * Q[-2] + B_Q * Q[-1] + C_Q) % D_Q + 1
        Q.append(Q_i)
    P.sort()
    Q.sort(reverse=True)

    L = -1
    R = 10**18
    while L + 1 < R:
        mid = (L + R) // 2
        if det(P[:], Q[:], mid):
            R = mid
        else:
            L = mid
    return R

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T + 1):
        M = solution()
        print(f"Case #{case}:", M)