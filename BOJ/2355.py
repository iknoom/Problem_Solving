A, B = map(int, input().split())
if A > B: A, B = B, A
print(B * (B + 1) // 2 - A * (A - 1) // 2)