def func(p):

    if len(p) == 0:
        return p
    else:
        left = 0
        right = 0
        idx = 0
        u = ""
        v = ""

        for i in p:
            if i == "(":
                left += 1
            elif i == ")":
                right += 1
            if left == right:
                u = p[: idx + 1]
                v = p[idx + 1 :]
                break
            idx += 1

        s = []

        for i in u:
            if i == "(":
                s.append("(")
            if i == ")" and len(s) != 0:
                s.pop()

        if len(s) == 0:
            v2 = func(v)
            u = u + v2
            return u
        else:
            temp = "("
            temp = temp + func(v)
            temp = temp + ")"
            u = u[1:-1]
            for i in u:
                if i == "(":
                    temp = temp + ")"
                elif i == ")":
                    temp = temp + "("
            return temp


def solution(p):
    answer = func(p)

    return answer
