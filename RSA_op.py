#!/usr/bin/python3
import sys
import math

if len(sys.argv) != 2:
    print("Usage: factors <file>")
    exit(1)

with open(sys.argv[1], "r") as file:
    for line in file:
        number = int(line)
        sqrt_number = int(math.sqrt(number))
        for factor in range(2, sqrt_number + 1):
            if number % factor == 0:
                print("{:d} = {:d}*{:d}".format(number, number // factor, factor))
                break
