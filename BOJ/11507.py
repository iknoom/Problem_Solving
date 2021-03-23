
def solution(STR):
    vst = {
        'P': set(),
        'K': set(),
        'H': set(),
        'T': set()
    }
    for i in range(len(STR) // 3):
        shp = STR[i * 3]
        num = int(STR[i * 3 + 1 : i * 3 + 3])
        if num in vst[shp]:
            print('GRESKA')
            return
        vst[shp].add(num)
    answer = []
    for shp in 'PKHT':
        answer.append(13 - len(vst[shp]))
    print(*answer)




if __name__ == '__main__':
    STR = input()
    solution(STR)