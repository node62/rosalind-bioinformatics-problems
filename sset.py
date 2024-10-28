import pyperclip

def main(file_path):
    with open(file_path, 'r') as f:
        n = int(f.read().strip())
    
    result = pow(2, n, 1000000)
    
    print(result)
    pyperclip.copy(str(result))
    
main(input().strip('"'))
