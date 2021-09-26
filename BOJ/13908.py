n, m = map(int, input().split())
selected = set(map(int, input().split()))
answer = 0
for i in range(10 ** n):
    S = set()
    if len(str(i)) < n:
        S.add(0)
    S |= set(map(int, str(i)))
    if not selected - S:
        answer += 1
print(answer)