import math

def compute_log_probabilities(s, A):
    B = []
    for gc_content in A:
        log_prob = 0
        gc_prob = gc_content / 2
        at_prob = (1 - gc_content) / 2
        for base in s:
            if base == 'G' or base == 'C':
                log_prob += math.log10(gc_prob)
            else:
                log_prob += math.log10(at_prob)
        B.append(log_prob)
    return B

s = input().strip()
A = []

while True:
    inp = input().strip()
    if inp == 'q':
        break
    A = list(map(float, inp.split()))

result = compute_log_probabilities(s, A)
print(" ".join(f"{x:.3f}" for x in result))
