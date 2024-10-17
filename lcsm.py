import pyperclip as pc

def read_fasta_terminal():
    sequences = []
    current_seq = []
    while True:
        line = input().strip()
        if line == 'q':
            break
        if line.startswith(">"):
            if current_seq:
                sequences.append("".join(current_seq))
                current_seq = []
        else:
            current_seq.append(line)
    if current_seq:
        sequences.append("".join(current_seq))
    return sequences

def longest_common_substring(dna_strings):
    shortest_string = min(dna_strings, key=len)
    length = len(shortest_string)
    for i in range(length, 0, -1):
        for j in range(length - i + 1):
            candidate = shortest_string[j:j+i]
            if all(candidate in dna for dna in dna_strings):
                return candidate
    return ""

dna_strings = read_fasta_terminal()
result = longest_common_substring(dna_strings)
print("---\n"+result)
pc.copy(result)
