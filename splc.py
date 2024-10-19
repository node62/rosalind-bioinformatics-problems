import pyperclip as pc
codons = {
    'AUG': 'M', 'UGG': 'W',
    'UUU': 'F', 'UUC': 'F',
    'UUA': 'L', 'UUG': 'L', 'CUU': 'L', 'CUC': 'L', 'CUA': 'L', 'CUG': 'L',
    'AUU': 'I', 'AUC': 'I', 'AUA': 'I',
    'GUU': 'V', 'GUC': 'V', 'GUA': 'V', 'GUG': 'V',
    'UCU': 'S', 'UCC': 'S', 'UCA': 'S', 'UCG': 'S', 'AGU': 'S', 'AGC': 'S',
    'CCU': 'P', 'CCC': 'P', 'CCA': 'P', 'CCG': 'P',
    'ACU': 'T', 'ACC': 'T', 'ACA': 'T', 'ACG': 'T',
    'GCU': 'A', 'GCC': 'A', 'GCA': 'A', 'GCG': 'A',
    'UAU': 'Y', 'UAC': 'Y',
    'CAU': 'H', 'CAC': 'H',
    'CAA': 'Q', 'CAG': 'Q',
    'AAU': 'N', 'AAC': 'N',
    'AAA': 'K', 'AAG': 'K',
    'GAU': 'D', 'GAC': 'D',
    'GAA': 'E', 'GAG': 'E',
    'UGU': 'C', 'UGC': 'C',
    'CGU': 'R', 'CGC': 'R', 'CGA': 'R', 'CGG': 'R', 'AGA': 'R', 'AGG': 'R',
    'GGU': 'G', 'GGC': 'G', 'GGA': 'G', 'GGG': 'G',
    'UAA': 'Stop', 'UAG': 'Stop', 'UGA': 'Stop'
}

def fasta(lines):
    data = {}
    label = ""
    seq = ""
    
    for line in lines:
        if line.startswith(">"):
            if label:
                data[label] = seq
            label = line[1:]
            seq = ""
        else:
            seq += line.strip()
    if label:
        data[label] = seq
    
    return data

def remove(dna, introns):
    for intron in introns:
        dna = dna.replace(intron, '')
    return dna

def transcribe(dna):
    return dna.replace('T', 'U')

def translate(mrna):
    protein = []
    
    for i in range(0, len(mrna), 3):
        codon = mrna[i:i+3]
        if len(codon) == 3:
            aa = codons.get(codon, '')
            if aa == 'Stop':
                break
            protein.append(aa)
    
    return ''.join(protein)

def process(data):
    parsed = fasta(data)
    dna = list(parsed.values())[0]
    introns = list(parsed.values())[1:]
    exons = remove(dna, introns)
    mrna = transcribe(exons)
    protein = translate(mrna)
    return protein

if __name__ == "__main__":
    lines = []
    while True:
        line = input().strip()
        if line == 'q':
            break
        lines.append(line)
    
    result = process(lines)
    print('---\n'+result)
    pc.copy(result)
    print('copied to clipboard')