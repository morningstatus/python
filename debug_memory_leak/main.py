# -*- coding: utf-8 -*-

import gc

def dump_garbage():
	print '\nGARBAGE OBJECTS:'
	for x in gc.garbage:
		s = str(x)
		if len(x) > 80: s = s[:77] + '...'
		print type(x), '\n  ', s

if __name__ == '__main__':
	gc.enable()
	gc.set_debug(gc.DEBUG_LEAK)
	l = []
	l.append(l)
	del l
	dump_garbage()
	gc.collect()
	dump_garbage()