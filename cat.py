import pyperclip
from imp_stuff import read_fasta

def f(x):
    if x in h:
        return h[x]
    if len(x) == 0:
        return 1
    r = 0
    for i in range(1, len(x), 2):
        if (x[0] == 'A' and x[i] == 'U') or (x[0] == 'U' and x[i] == 'A') or (x[0] == 'C' and x[i] == 'G') or (x[0] == 'G' and x[i] == 'C'):
            r += f(x[1:i]) * f(x[i+1:])
            r %= 1000000
    h[x] = r
    return r

def g(y):
    with open(y, 'r') as z:
        d = read_fasta(z)
        k = next(iter(d.values()))
    d = f(k)
    pyperclip.copy(str(d))
    print(d)

h = {}

p = input("Enter the file path: ").strip('"')
g(p)
