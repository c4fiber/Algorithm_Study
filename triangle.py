# -*- coding: utf-8 -*-

print('triange area\n')
d = float(raw_input('length: '))

for i in range(int(d)+1):
	print('* '*i)

area = float((d ** 2) / 2)
print('area : %s' % area)

raw_input()

