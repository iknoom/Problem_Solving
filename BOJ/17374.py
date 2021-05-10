from sys import stdin
input = stdin.readline

T = int(input())
for _ in range(T):
    P, Q, A, B, C, D = map(int, input().split())
    # P개의 비트 / Q개의 베리
    # 빈센트에게 비트 A개를 주고 코인을 B개 받는다.
    # 빈센트에게 코인 B개를 주고 비트를 A개 받는다.
    # 빈센트에게 베리 C개를 주고 코인을 D개 받는다.
    # 빈센트에게 코인 D개를 주고 베리를 C개 받는다.
    # 빈센트에게 비트 1개와 코인 1개를 주고 비트코인을 1개 받는다.

    # 1. 베리 -> 코인
    coin = (Q // C) * D

    # 2. 비트 + 코인
    bitcoin = min(P, coin)
    P -= bitcoin
    coin -= bitcoin

    # 3. 코인 -> 비트
    if coin >= B:
        bitcoin += (coin // (A + B)) * A
        coin %= A + B
        if coin >= B:
            bitcoin += coin - B

    # 4. 비트 -> 코인
    if P >= A:
        bitcoin += (P // (A + B)) * B
        P %= A + B
        if P >= A:
            bitcoin += P - A

    print(bitcoin)