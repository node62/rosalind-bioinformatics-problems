from imp_stuff import read_fasta
import pyperclip

def get_pdist(a, b):
    return sum(x != y for x, y in zip(a, b)) / len(a)

def make_matrix(dna_list):
    return [[get_pdist(a, b) for b in dna_list] for a in dna_list]

def format_matrix(matrix):
    return '\n'.join(' '.join(f"{x:.5f}" for x in row) for row in matrix)

file_path = input("Enter input path: ").strip('"')
with open(file_path) as file:
    dna_data = read_fasta(file)
dna_list = list(dna_data.values())

matrix = make_matrix(dna_list)
result = format_matrix(matrix)

print(result)
pyperclip.copy(result)
