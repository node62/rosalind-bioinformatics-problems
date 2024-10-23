def read_fasta(f):
    a = f.read().split('>')[1:]
    d = {}
    for i in a:
        b = i.split('\n', 1)
        d[b[0]] = b[1].replace('\n', '')
    return d