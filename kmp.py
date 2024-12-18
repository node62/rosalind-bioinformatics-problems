import pyperclip

def main(path):
    with open(path, 'r') as f:
        lines = f.readlines()
    
    s = "".join(lines[1:]).replace("\n", "")
    p = [0] * len(s)
    
    for i in range(1, len(s)):
        j = p[i - 1]
        while j > 0 and s[i] != s[j]:
            j = p[j - 1]
        if s[i] == s[j]:
            j += 1
        p[i] = j

    result = " ".join(map(str, p))
    pyperclip.copy(result)
    print(result)

main(input("Enter path: ").strip('"'))g