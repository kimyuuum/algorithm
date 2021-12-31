def list_chunk(lst, n):
    return [lst[i : i + n] for i in range(0, len(lst), n)]


def solution(s):
    answer = len(s)

    num = len(s) // 2

    while num != 0:
        ans = ""
        temp = list_chunk(s, num)
        cnt = 1

        for idx, val in enumerate(temp):
            if idx == 0:
                continue

            if idx == len(temp) - 1:
                if val == temp[idx - 1]:
                    cnt = cnt + 1
                    ans = ans + str(cnt) + temp[idx - 1]
                else:
                    if cnt == 1:
                        ans = ans + temp[idx - 1]
                    else:
                        ans = ans + str(cnt) + temp[idx - 1]
                        cnt = 1
                    ans = ans + val
                break

            if val == temp[idx - 1]:
                cnt = cnt + 1
            else:
                if cnt == 1:
                    ans = ans + temp[idx - 1]
                else:
                    ans = ans + str(cnt) + temp[idx - 1]
                    cnt = 1

        if len(ans) < answer:
            answer = len(ans)
        num = num - 1
    return answer
