import sys
from itertools import cycle
ip = "10,3"

ip = ip.split(",")
count = int(ip[0])
gap = int (ip[1])

#print ip, count, gap

lst = []
for i in range(count):
    lst.append(i)

pool = cycle(lst)

ct = 0
l = []
for item in pool:
    #print ct, gap, count
    if ((ct+1) % (gap)) == 0:
    	l.append(item)
    if ct >= count:
	break 
    ct += 1

print ' '.join(str(x) for x in l)
