r=range(9999);print(*sorted({*r}-{n+sum(map(int,str(n)))for n in r}))
