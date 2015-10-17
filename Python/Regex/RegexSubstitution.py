import re
for tc in xrange(int(raw_input())):
    line = str(raw_input())
    pattern = re.compile(r'(?<= )&&(?= )')
    line = re.sub(pattern, "and", line)
    pattern = re.compile(r'(?<= )\|\|(?= )')
    line = re.sub(pattern, "or", line)
    print line
