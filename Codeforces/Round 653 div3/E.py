import sys
input = sys.stdin.readline


n, k = map(int, input().split())

books = [tuple(map(int, input().split())) for _ in range(n)]
books.sort(key=lambda x: (x[0], -x[1], -x[2]))

ans = 0
comm = []
cnt_a = []
cnt_b = []

for t, a, b in books:
    if a == 0 and b == 0:
        pass
    elif a == 1 and b == 1:
        if len(cnt_a) + len(comm) < k or len(cnt_b) + len(comm) < k:
            comm.append(t)
        else:
            if cnt_a and cnt_b and cnt_a[-1] + cnt_b[-1] > t:
                cnt_a.pop()
                cnt_b.pop()
                comm.append(t)
    elif a == 1 and len(cnt_a) + len(comm) < k:
        cnt_a.append(t)
    elif b == 1 and len(cnt_b) + len(comm) < k:
        cnt_b.append(t)
    else:
        pass


while cnt_a and len(cnt_a) + len(comm) > k:
    cnt_a.pop()
while cnt_b and len(cnt_b) + len(comm) > k:
    cnt_b.pop()

if len(cnt_a) + len(comm) < k or len(cnt_b) + len(comm) < k:
    print(-1)
else:
    print(sum(cnt_a) + sum(cnt_b) + sum(comm))