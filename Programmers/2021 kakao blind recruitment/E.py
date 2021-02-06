
def sec(time):
    h, m, s = time.split(":")
    return int(h) * 3600 + int(m) * 60 + int(s)

def inv_sec(sec):
    h = sec // 3600
    sec %= 3600
    m = sec // 60
    sec %= 60
    return f'{h:02d}:{m:02d}:{sec:02d}'

def sweeping(play_time, L, logs):
    periods = []
    for s, e in logs:
        if e - s < L:
            periods.append((s - L, 1))  # up
            periods.append((e - L, -1))  # maintain
            periods.append((s, -1))  # down
            periods.append((e, 1))  # maintain
        else:
            periods.append((s - L, 1))  # up
            periods.append((s, -1))  # maintain
            periods.append((e - L, -1))  # down
            periods.append((e, 1))  # maintain

    periods.append((0, 0))
    periods.append((play_time - L, 0))

    # do sweeping
    max_time = -1
    ret = -1
    y = t = 0
    before_time = -10**18
    for start_time, dt in sorted(periods):
        y += t * (start_time - before_time)
        if 0 <= start_time and start_time + L <= play_time and max_time < y:
            max_time = y
            ret = start_time
        t += dt
        before_time = start_time
    return ret

def solution(play_time, adv_time, logs):
    sec_logs = []
    for log in logs:
        s, e = log.split('-')
        sec_logs.append((sec(s), sec(e)))
    answer_time = sweeping(sec(play_time), sec(adv_time), sec_logs)
    return inv_sec(answer_time)

if __name__ == "__main__":
    print(solution("02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))
    print(solution("50:00:00", "50:00:00", ["15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"]))