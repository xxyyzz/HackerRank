l = []
for q in xrange(input()):
    args = raw_input().split()
    if args[0] == 'print':
        print l
    else:
        getattr(l, args[0])(*(list(int(args[x]) for x in xrange(1, len(args)))))
        # getattr(l, args[0])(*(int(args[x]) for x in xrange(1, len(args))))
