from math import factorial
from imp_stuff import read_fasta
import pyperclip

def solve(f):
    with open(f) as r:
        rna = next(iter(read_fasta(r).values()))

    a = rna.count('A')
    c = rna.count('C')
    res = factorial(a) * factorial(c)
    print(res)
    pyperclip.copy(str(res))

f = input("Input file: ").strip('"')
solve(f)