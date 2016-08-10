import sys

for N in sys.stdin:
	i = 1
	for line in sys.stdin:
		print "Case %i:" % i
		i = i + 1
		num, base = line.split()
		if base == 'hex':
			toDec = int(num, 16)
			toBin = bin(toDec)

			print str(toDec) + ' dec'
			print toBin[2:] + ' bin'

		elif base == 'dec':
			toHex = hex(int(num))
			toBin = bin(int(num))

			print toHex[2:] + ' hex'
			print toBin[2:] + ' bin' 

		else: # bin
			toDec = int(num, 2)
			toHex = hex(toDec)

			print str(toDec) + ' dec'
			print toHex[2:] + ' hex'

		print

		# print "num = " + num
		# print "base = " + base