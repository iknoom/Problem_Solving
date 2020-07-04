import sys
sys.stdin = open("sample_input.txt", "r")

T = int(input())

code_to_int = {'3211' : 0, '2221' : 1, '2122' : 2,
               '1411' : 3, '1132' : 4, '1231' : 5,
               '1114' : 6, '1312' : 7, '1213' : 8, '3112' : 9}

def verify(code):
    d = min(code)
    for i in range(len(code)): code[i] //= d
    ret = []
    for i in range(8):
        S = ''.join(map(str, code[i*4:(i+1)*4]))
        if S not in code_to_int: return 0
        ret.append(code_to_int[S])

    verify_code = ''.join(map(str, ret))
    if verify_code in visited: return 0
    else: visited.add(verify_code)
    Sum = 0
    for i in range(4):
        Sum += ret[i * 2] * 3
        Sum += ret[i * 2 + 1]
    if Sum % 10: return 0
    else: return sum(ret)

for test_case in range(1, T + 1):
    N, M = map(int, input().split())
    visited = set()
    answer = 0
    tmp = []
    for _ in range(N):
        for c_16 in input():
            if c_16 == '\r': continue
            c_10 = int(c_16, 16)
            for j in range(3, -1, -1):
                if c_10 & (1<<j): tmp.append(1)
                else: tmp.append(0)

    codes = []
    cnt = 1
    for i in range(len(tmp) - 1):
        if tmp[i] == tmp[i + 1]: cnt += 1
        else: codes.append(cnt); cnt = 1
    codes.append(cnt)

    for i in range(len(codes) - 32):
        while codes[i]:
            answer += verify(codes[i : i + 32])
            codes[i] -= 1

    print('#'+str(test_case), answer)