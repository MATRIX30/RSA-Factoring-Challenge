#!/usr/bin/python3
import sys

handle = open(sys.argv[1], 'r')

for lines in handle:
    print(int(lines) * 2)

handle.close()
