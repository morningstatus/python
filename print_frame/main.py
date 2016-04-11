# -*- coding: utf-8 -*-

import sys
import os

def detail_trace(info):
	retStr = ""
	curindex=0
	f = sys._getframe()
	f = f.f_back # first frame is detailtrace, ignore it
	while hasattr(f, "f_code"):
		co = f.f_code
		retStr = "%s(%s:%s)\n" % (co.co_name, os.path.abspath(co.co_filename),
			f.f_lineno) + retStr
		f = f.f_back
	print retStr+info

def test_print_trace(i):
	if i == 10:
		detail_trace('')
		return
	test_print_trace(i + 1)

if __name__ == '__main__':
	test_print_trace(0)