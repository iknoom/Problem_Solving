import sys
f_name = "perimetric_chapter_1"
sys.stdin = open(f_name + "_input.txt", 'r')
sys.stdout = open(f_name + "_output.txt", 'w')



def solution():
    N, K, W = map(int, input().split())
    L = list(map(int, input().split()))
    A_L, B_L, C_L, D_L = map(int, input().split())
    H = list(map(int, input().split()))
    A_H, B_H, C_H, D_H = map(int, input().split())

    for i in range(K, N):
        L_i = (A_L * L[-2] + B_L * L[-1] + C_L) % D_L + 1
        H_i = (A_H * H[-2] + B_H * H[-1] + C_H) % D_H + 1
        L.append(L_i)
        H.append(H_i)

    stack = []
    answer = 1
    MOD = 1000000007
    P_i = 0

    for L_i, H_i in zip(L, H):
        while stack:
            if L_i <= stack[-1][0] and stack[-1][1] <= L_i + W and stack[-1][2] <= H_i:
                _, _, _, p_s = stack.pop()
                P_i -= p_s
            else:
                break
        if not stack:
            cur_s = (W + H_i) * 2
            P_i += cur_s
            stack.append([L_i, L_i + W, H_i, cur_s])

        elif stack[-1][1] < L_i:
            cur_s = (W + H_i) * 2
            P_i += cur_s
            stack.append([L_i, L_i + W, H_i, cur_s])

        elif stack[-1][2] >= H_i:
            cur_s = (L_i + W - stack[-1][1]) * 2
            P_i += cur_s
            stack.append([stack[-1][1], L_i + W, H_i, cur_s])

        else:
            cur_s = (L_i + W - stack[-1][1]) * 2
            cur_s += (H_i - stack[-1][2]) * 2
            P_i += cur_s
            stack.append([L_i, L_i + W, H_i, cur_s])

        answer *= P_i
        answer %= MOD

    return answer

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T + 1):
        M = solution()
        print(f"Case #{case}:", M)