n, k = input().split(' ')
n, k = int(n), int(k)
nk = 1
for i in range(n-k+1, n+1):
    #nk *= i
    nk = nk * i // (i-n+k)
print(nk % 1000000007)    

