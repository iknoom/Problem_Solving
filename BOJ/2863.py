A, B = map(int, input().split())
C, D = map(int, input().split())
value = [
    (A/C + B/D, -0),
    (C/D + A/B, -1),
    (D/B + C/A, -2),
    (B/A + D/C, -3)
]
_, answer = max(value)
print(-answer)