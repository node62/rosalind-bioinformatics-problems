import pyperclip as pc
fasta = {}
current_label = ""
current_seq = ""
print("Enter, end with q:")
while True:
    line = input()
    if line == "q":
        break
    if line.startswith(">"):
        if current_label != "":
            fasta[current_label] = current_seq
        current_label = line[1:]
        current_seq = ""
    else:
        current_seq += line
if current_label != "":
    fasta[current_label] = current_seq
k = 3
edges = []
for s_label in fasta:
    s_seq = fasta[s_label]
    if len(s_seq) >= k:
        s_suffix = s_seq[-k:]
        for t_label in fasta:
            if s_label != t_label and fasta[t_label].startswith(s_suffix):
                edges.append((s_label, t_label))
for edge in edges:
    print(edge[0], edge[1])

pc.copy("\n".join([" ".join(edge) for edge in edges]))
