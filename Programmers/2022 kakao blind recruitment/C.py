from collections import defaultdict

def get_timestamp(time_str):
    h, m = map(int, time_str.split(':'))
    return h * 60 + m

def solution(fees, records):
    base_minute, base_fee, unit_time, unit_fee = fees
    sum_all_parktime = defaultdict(int)
    check_in_out = {}
    for record in records:
        _time, car_number, IN_OUT = record.split()
        time = get_timestamp(_time)
        if IN_OUT == "IN":
            check_in_out[car_number] = time
        elif IN_OUT == "OUT":
            sum_all_parktime[car_number] += time - check_in_out[car_number]
            check_in_out.pop(car_number)

    limit_time = get_timestamp("23:59")
    for car_number in check_in_out.keys():
        sum_all_parktime[car_number] += limit_time - check_in_out[car_number]

    tmp = []
    for car_number in sum_all_parktime.keys():
        parktime = sum_all_parktime[car_number]
        if parktime <= base_minute:
            tmp.append((int(car_number), base_fee))
            continue
        cur_fee = base_fee
        parktime -= base_minute
        cur_fee += (parktime // unit_time) * unit_fee
        if parktime % unit_time != 0:
            cur_fee += unit_fee
        tmp.append((int(car_number), cur_fee))
    answer = []
    for _, fee in sorted(tmp):
        answer.append(fee)
    return answer

if __name__ == '__main__':
    print(solution([180, 5000, 10, 600],
                   ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))