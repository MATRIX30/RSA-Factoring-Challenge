#!/usr/bin/python3
import sys
import math

if len(sys.argv) != 2:
    print("Usage: factors <file>")
    exit(1)
file = open(sys.argv[1], "r")
content = file.read()
content = content.split("\n")
for number in content:
    print(type(number))
    int_num = int(number)
    for factor in range(2, (int(math.sqrt(int_num))) + 1):
        if int_num % factor == 0:
            print("{:d} = {:d}*{:d}".format(int_num, int_num // factor, factor))
            break
