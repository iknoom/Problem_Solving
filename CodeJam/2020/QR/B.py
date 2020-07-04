T = int(input())

for case in range(1, T + 1):
    ans = ""
    depth = 0
    S = list(map(int, input()))
    for cur in S:
        if cur > depth:
            ans += '(' * (cur - depth)
        elif cur < depth:
            ans += ')' * (depth - cur)
        ans += str(cur)
        depth = cur
    ans += ')' * depth
    print("Case #"+str(case) + ":", ans)