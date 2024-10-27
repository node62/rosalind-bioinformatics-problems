import pyperclip
from math import factorial
from imp_stuff import read_fasta

def rna_matchings(path):
    with open(path, 'r') as file:
        data = read_fasta(file)
    s = next(iter(data.values()))

    a_count = s.count('A')
    u_count = s.count('U')
    c_count = s.count('C')
    g_count = s.count('G')

    a_u_matchings = factorial(max(a_count, u_count)) // factorial(max(a_count, u_count) - min(a_count, u_count))
    c_g_matchings = factorial(max(c_count, g_count)) // factorial(max(c_count, g_count) - min(c_count, g_count))

    result = a_u_matchings * c_g_matchings
    print(result)
    pyperclip.copy(str(result))

rna_matchings(input().strip('"'))
