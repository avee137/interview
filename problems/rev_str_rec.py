#!/usr/bin/env python


def rev(s):
	if len(s)==1:
		return s[0]
	else:
		return rev(s[1:])+s[0]

print rev("hello")
