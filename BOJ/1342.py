from itertools import permutations

def is_lucky(string):
    for i in range(len(string) - 1):
        if string[i] == string[i + 1]:
            return False
    return True

if __name__ == '__main__':
    S = input()
    permu_set = set(''.join(e) for e in permutations(S))
    answer = 0
    for e in permu_set:
        if is_lucky(e):
            answer += 1
    print(answer)