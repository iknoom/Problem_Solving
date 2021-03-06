from sys import stdin
input = stdin.readline

not_valid = ['3', '4', '6', '7', '9']
valid = {
    '0' : '0',
    '1' : '1',
    '2' : '5',
    '5' : '2',
    '8' : '8'
}

def solution():
    H, M = map(int, input().split())
    cur_h, cur_m = map(int, input().split(':'))
    for i in range(H * M + 2):
        str_h = str(cur_m)[::-1]
        str_m = str(cur_h)[::-1]
        if len(str_h) < 2:
            str_h = str_h + '0'
        if len(str_m) < 2:
            str_m = str_m + '0'
        flag = True
        next_h = ''
        next_m = ''
        for c in str_h:
            if c in not_valid:
                flag = False
                break
            next_h = next_h + valid[c]
        for c in str_m:
            if c in not_valid:
                flag = False
                break
            next_m = next_m + valid[c]
        if flag and (int(next_h) >= H or int(next_m) >= M):
            flag = False
        if flag:
            break
        cur_m += 1
        if cur_m >= M:
            cur_m -= M
            cur_h += 1
        if cur_h >= H:
            cur_h -= H
    ans_h = str(cur_h)
    ans_m = str(cur_m)
    if len(ans_h) < 2:
        ans_h = '0' + ans_h
    if len(ans_m) < 2:
        ans_m = '0' + ans_m
    print(ans_h+':'+ans_m)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()