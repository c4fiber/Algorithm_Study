id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2

def initReportIdPair(id_list, id_pair):
    for i in range(len(id_list)):
        id_pair[id_list[i]] = i

def analyzeReportedByWho(id_pair, report, reportedById):
    for words in report:
        src, dest = words.split(' ')
        index = id_pair[dest]
        reportedById[index].add(src)

def sendReportMail(id_pair, reportedById, k, answer):
    for i in reportedById:
        if len(i) >= k:
            for j in i:
                answer[ id_pair[j] ] += 1


def solution(id_list, report, k):
    n = len(id_list)
    answer = [0 for _ in range(n)]
    
    id_pair = {} # dict
    reportedById = [set() for _ in range(n)] # set array
    
    initReportIdPair(id_list, id_pair)
    analyzeReportedByWho(id_pair, report, reportedById)
    sendReportMail(id_pair, reportedById, k, answer)

    return answer

answer = solution(id_list, report, k)
print(answer)
    
# set을 이용해서 각 유저에 대해 신고집합을 생성
# 신고집합의 수가 k 이상이면 정지