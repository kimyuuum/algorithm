def solution(record):
    answer = []

    uidData = {}

    for data in record:
        data = data.split(" ")
        if data[0] != "Leave":
            uid = data[1]
            nickName = data[2]
            uidData[uid] = nickName

    for data in record:
        data = data.split(" ")
        if data[0] == "Enter":
            uid = data[1]
            nickName = uidData[uid]
            answer.append(nickName + "님이 들어왔습니다.")
        elif data[0] == "Leave":
            uid = data[1]
            nickName = uidData[uid]
            answer.append(nickName + "님이 나갔습니다.")

    return answer
