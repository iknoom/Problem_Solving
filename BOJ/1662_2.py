def get_length(S):
    length = 0
    i = 0
    while i < len(S):
        # 1. K(Q)로 압축된 부분 -> K * get_length(Q)
        if i + 1 < len(S) and S[i + 1] == '(':
            K = int(S[i])
            # 닫히는 괄호의 위치를 찾는다.
            count = 1
            j = i + 2
            while True:
                if S[j] == '(':
                    count += 1
                if S[j] == ')':
                    count -= 1
                    if count == 0:
                        break
                j += 1
            length += K * get_length(S[i + 2 : j])
            i = j + 1
        # 2. K(Q)로 압축되지 않은 부분 -> 무조건 길이가 1
        else:
            length += 1
            i += 1
    return length

if __name__ == '__main__':
    S = input()
    print(get_length(S))