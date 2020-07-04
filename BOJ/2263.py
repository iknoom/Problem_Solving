import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
in_order = list(map(int, input().split()))
post_order = list(map(int, input().split()))
node_idx = [in_order[i] - 1 for i in range(N)]

# in-order에서의 범위 : [L1 : R1]
# post-order에서의 범위 : [L2 : R2]

def pre_order(L1, R1, L2, R2):

    # in-order에서 root의 인덱스
    root = node_idx[post_order[R2] - 1]

    # 왼쪽 서브트리의 크기
    K = root - L1

    print(in_order[root], end=' ')
    if L1 != root:
        pre_order(L1, root - 1, L2, L2 + K - 1)
    if R1 != root:
        pre_order(root + 1, R1, L2 + K, R2 - 1)

pre_order(0, N - 1, 0, N - 1)