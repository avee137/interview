#!/usr/bin/env python

def fib_sum(n):
	first = 1
	second = 2
	s = 2
	nxt = 0
	while nxt < n:
		nxt = first+second
		first = second
		second = nxt
		if (nxt % 2 is 0):
			s += nxt
	return s



if __name__=="__main__":
	top = 4000000
	s = fib_sum(top)
	print s
