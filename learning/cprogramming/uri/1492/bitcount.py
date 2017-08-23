import sys

def bitcount(n):
    cont = 0
    while n > 0:
        if n & 1:
            cont = cont + 1
        n = n >> 1

    return cont

dosum = False
if len(sys.argv) == 3:
    dosum = sys.argv[2] == 's'

total = 0
bits = 0

if int(sys.argv[1]) > 0:
    for i in range(1, int(sys.argv[1]) + 1):
        bits = bitcount(i)
        if not dosum:
            print "%i" % bits
        else:
            total = total + bits
    
    if dosum:
        print "%i" % total
