#code by 0xdeadbeef
r=lambda:map(int,input().split())
N,K=r()
D=[0]*(K+1)
for w,v in(r()for _ in range(N)):
 for m in range(K,1,-1):
  if w<=m:D[m]=max(D[m],D[m-w]+v)
print(D[K])
