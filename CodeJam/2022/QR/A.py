import sys
input = sys.stdin.readline

def solution():
    R, C = map(int, input().split())
    arr = []
    for _ in range(R):
        arr.append(['+-' for _ in range(C)] + ['+'])
        arr.append(['|.' for _ in range(C)] + ['|'])
    arr.append(['+-' for _ in range(C)] + ['+'])
    arr[0][0] = '..'
    arr[1][0] = '..'
    for row in arr:
        print(''.join(row))

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":")
        solution()