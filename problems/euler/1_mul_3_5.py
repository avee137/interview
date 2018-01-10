#! /usr/bin/env python


def sum_factors(n):
	s = 0
	for i in range(n):
		if (i%3 is 0) or (i%5 is 0):
			s += i
	return s

if __name__=="__main__":
	max_num = 1000
	s = sum_factors(max_num)
	print s
