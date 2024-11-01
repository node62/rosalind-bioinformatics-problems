import pyperclip
import imp_stuff as stuff

def transitions_transversions_ratio(file_path):
    with open(file_path, 'r') as f:
        data = stuff.read_fasta(f)
        keys = list(data.keys())
        a = data[keys[0]]
        b = data[keys[1]]
        
    trans = 0
    transv = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            if (a[i], b[i]) in [('A', 'G'), ('G', 'A'), ('C', 'T'), ('T', 'C')]:
                trans += 1
            else:
                transv += 1
                
    ratio = trans / transv if transv != 0 else 0
    pyperclip.copy(ratio)
    print(ratio)

transitions_transversions_ratio(input('Path to Input File: ').strip('"'))