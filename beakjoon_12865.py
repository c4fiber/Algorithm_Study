#N: Number, K: Kilogram
N, K = list(map(int, str(input()).split()))

#sack: result of calc
#list선언 후 초기화 할 때 *를 사용하면 모두 같은 객체로 인식된다.
sack = [[0] * (K + 1) for _ in range(N + 1)]

for r in range(1, N+1):
    #w: weight, v: value
    w, v = list(map(int, str(input()).split()))

    for c in range(1, K+1):
        if c >= w:
            #현재 물건을 넣을 수 있으면 넣는 경우를 계산, 최대값 구함
            sack[r][c] = max(v + sack[r-1][c-w], sack[r-1][c])
        else:
            #이전의 최대값 복사
            sack[r][c] = sack[r-1][c]

    print(sack[r])
print(max(sack[-1]))
