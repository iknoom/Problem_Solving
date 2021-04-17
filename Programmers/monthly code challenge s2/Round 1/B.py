def is_ok(s):
    stack = []
    for c in s:
        if c in '({[':
            stack.append(c)
        elif c == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                return False
        elif c == '}':
            if stack and stack[-1] == '{':
                stack.pop()
            else:
                return False
        elif c == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

def solution(s):
    answer = 0
    for i in range(len(s)):
        nxt = s[i:] + s[:i]
        if is_ok(nxt):
            answer += 1
    return answer

if __name__ == '__main__':
    print(solution("[](){}"))