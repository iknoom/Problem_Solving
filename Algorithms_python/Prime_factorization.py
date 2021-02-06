def prime_fact(num):
    ret = []
    while True:
        if num == 1: break
        tmp = num
        div = 2
        while div * div <= num:
            if num % div == 0:
                ret.append(div)
                num //= div
                break
            div += 1
        if num == tmp:
             ret.append(num)
             break
    return ret

def prime_fact2(num):
    ret = set()
    while True:
        if num == 1: break
        tmp = num
        div = 2
        while div * div <= num:
            if num % div == 0:
                ret.add(div)
                ret.add(num//div)
                num //= div
                break
            div += 1
        if num == tmp:
             ret.add(num)
             break
    return ret

if __name__ == "__main__":
    print(prime_fact2(214748364))
