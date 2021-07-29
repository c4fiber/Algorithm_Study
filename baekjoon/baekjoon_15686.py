def getDistance(depth):
    if depth == m:
        res = 0
        for i in range(len(hous)):
            minimum =999999
            for j in visited:
                tmp = abs(hous[i][0] - chick[j][0]) + abs(hous[i][1] - chick[j][1])
                minimum = min(minimum, tmp)
            res += minimum
        return res
    return topValue

def selectChicken(depth):
    minimum = topValue
    for i in range(depth, len(chick)+1):
        if i not in visited:
            visited.append(i)
            selectChicken(i+1)
            visited.pop()
        minimum = min(minimum, getDistance(len(visited)))
    return minimum

#dfs 이용, depth = 치킨집 개수, node(res) 값 = 치킨거리의 합 
n, m = [*map(int, input().split(' '))]
matrix=[input().split(' ') for _ in range(n)]
hous, chick = [], []
topValue = 999999

#chick = 치킨집 좌표, hous = 가정집 좌표
for i in range(n):
    for j in range(n):
        if matrix[i][j] == '1':
            hous.append([i,j])
        elif matrix[i][j] == '2':
            chick.append([i,j])
visited = []


print(selectChicken(0))
#치킨집 갯수만큼 재귀함수 돌리기

