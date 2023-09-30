#!/usr/bin/python3
import sys
import math
if (len(sys.argv) != 2):
    print("Usage: factors <file>")
    exit(1)
file = open(sys.argv[1], 'r')
content = file.read()
content = content.split('\n')
for number in content:
    for factor in range(2,(int(math.sqrt(int(number))))+1):
        if int(number)%factor == 0:
            print("{:d} = {:d}*{:d}".format(int(number),int(number)//factor, factor))
            break;