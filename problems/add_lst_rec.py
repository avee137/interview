#!/usr/bin/env python

def rec_sum(lst):
	if len(lst)==1:
		return lst[0]
	else:
		return lst[0]+rec_sum(lst[1:])

if __name__=="__main__":
	l = [x for x in range(11)]
	s = rec_sum(l)
	print s
