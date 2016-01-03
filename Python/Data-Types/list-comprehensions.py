X, Y, Z, n = input(), input(), input(), input()
print [[x, y, z] for x in xrange(0, X+1) for y in xrange(0, Y+1) for z in xrange(0, Z+1) if x + y + z != n]
