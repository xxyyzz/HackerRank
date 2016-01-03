from __future__ import print_function
n, l, s = input(), [], set()
for x in xrange(n):
    a, b = raw_input(), input()
    l.append([a, b])
    s.add(b)
s = sorted(s)
l = sorted(l, key = lambda l: l[0])
print (*([elem[0] for elem in l if elem[1] == s[1]]), sep='\n', end='')
