import bisect

N, C = map(int, input().split())
arr = list(map(int, input().split()))
A, B = arr[:N // 2], arr[N // 2:]
left_values = [0]
for x in A:
    inc = [k + x for k in left_values]
    left_values += inc
right_values = [0]
for x in B:
    inc = [k + x for k in right_values]
    right_values += inc

answer = 0
left_values.sort()
for right_value in right_values:
    answer += bisect.bisect(left_values, C - right_value)
print(answer)