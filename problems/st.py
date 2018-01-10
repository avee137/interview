import sys

class stack():
    st = []

    def __init__(self):
        self.st = [] 
        
    def push(self, num):
        self.st.append(num)
    
    def pop(self):
        return self.st.pop()
    
    def print_alternate(self):
        p = 1
        while len(self.st) != 0:
            n = self.st.pop()
            if p%2 == 1:
                print n
            p += 1
            
        

def main ():
    s = stack ()
    for line in [1,2,3,4]:
        num = int(line)
        s.push(num)
    s.print_alternate()

main()
