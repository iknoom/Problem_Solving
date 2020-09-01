a, b, c = map(int, input().split())
S = abs(a) + abs(b)
if S > c:
    print("NO")
else:
    if (c - S) % 2 == 0:
        print("YES")
    else:
        print("NO")