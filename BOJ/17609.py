def is_pal(s):
    return s == s[::-1]

def is_ps_pal(s):
    for i in range(len(s)):
        if s[i] != s[len(s) - i - 1]:
            if is_pal(s[i: len(s) - i - 1]):
                return True
            if is_pal(s[i + 1: len(s) - i]):
                return True
            break
    return False

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        S = input()
        if is_pal(S):
            print(0)
        elif is_ps_pal(S):
            print(1)
        else:
            print(2)