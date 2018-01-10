import operator

ip = "81 : (1,53.38,$45) (2,88.62,$98) (3,78.48,$3) (4,72.30,$76) (5,30.18,$9) (6,46.34,$48)"

ip = ip.split(":")
max_wt = int(ip[0])

print max_wt

items = ip[1].strip()
items = items.split(" ")
print items

l = []
for each in items:
    each = each.strip("(").strip(")")
    i = int(each.split(",")[0])
    wt = float (each.split(",")[1])
    cost = int (each.split(",")[2].strip('$'))
    l.append((i,wt,cost))

#(index,wt,cost)
print l
index = []
total_wt = 0.0
total_cost = 0
for each in l:
    if (total_wt < max_wt):
        index.append(each[0])
	total_wt += each[1]

print ",".join(str(x) for x in index)
