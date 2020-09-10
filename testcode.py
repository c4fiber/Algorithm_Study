#weight, value

N, K = [*map(int, str(input()).split())]
sack = [[0]*(K+1)]*(N+1)

for r in range(1, N+1):
    w, v = [*map(int, str(input()).split())]

    for c in range(1, K+1):
        print('c: ',c)
        if c >= w:
            sack[r][c] = max(v + sack[r-1][c-w], sack[r-1][c])
        else:
            sack[r][c] = sack[r-1][c]
            
print(sack.pop().pop())
