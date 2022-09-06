import random 

class Piles:
    def __init__(self, b=[], a=[], moves=0, size=4):
        if a == []:
            self.a = self.create_array(size)
        else:
            self.a = a
        self.b = b
        self.moves = moves

    def create_array(self, size):
        test = []
        array = random.sample(range(0, size * 2), size)
        for elem in array:
            test.append(Element(elem))
        return test
    
    def __str__(self):
        s = 'A: '
        for elem in self.a:
            s += str(elem)
            s += ' ' 
        s += '\nB: '
        for elem in self.b:
            s += str(elem)
            s += ' ' 
        s += '\nmov: ' + str(self.moves)
        return s
    
    def anti(self, stack):
        if stack == self.a:
            return self.b
        return self.a

    def swap(self, stack):
        aux = stack[0]
        stack[0] = stack[1]
        stack[1] = aux
        self.moves += 1

    def push(self, orig, dest):
        if orig != []:
            aux = orig[0]
            dest.insert(0, aux)
            orig.pop(0)
        self.moves += 1


    def rotate(self, stack):
        if stack != []:
            aux = stack[0]
            stack.append(aux)
            stack.pop(0)
        self.moves += 1
    
    def reverse(self, stack):
        if stack != []:
            aux = stack[-1]
            stack.insert(0, aux)
            stack.pop(-1)
        self.moves += 1

    def index(self):
        '''Function to index the elements of the stack in ascendent order'''
        arr = sorted(self.a)
        i = 0
        for elem in arr:
            elem.index = i
            i += 1
        for elem in self.a:
            for key in arr:
                if elem.number == key.number:
                    elem.index = key.index
    def alg1(self):
        '''Function to organize the stacks'''
        min_index = max_index = -1
        while len(self.a) > 0:
            self.minimo(self.a)
            if self.b == []:
                self.push(self.a, self.b)
                max_index = self.b[0].index
                min_index = self.b[0].index
            elif len(self.b) == 1:
                self.push(self.a, self.b)
                max_index = max(max_index, self.b[0].index)
                min_index = min(min_index, self.b[0].index)
            else:
                '''passar isto para uma função'''
                i = 0
                size = len(self.b)
                if self.a[0].index < min_index:
                    target = max_index
                    min_index = self.a[0].index
                elif self.a[0].index > max_index:
                    target = max_index
                    max_index = self.a[0].index
                else:
                    while i < size:
                        if self.b[i].index < self.a[0].index and self.a[0].index < self.b[i - 1].index:
                            target = self.b[i].index
                        i += 1
                while self.b[0].index != target:
                    if i < (size / 2): 
                        self.rotate(self.b)
                    else:
                        self.reverse(self.b)
                self.push(self.a, self.b)
        '''isto tem que ser otimizado noutra função'''
        while self.b[0].index != max_index:
            self.rotate(self.b)
        while len(self.b) > 0:
            self.push(self.b, self.a)
        
    def insert_order(self, orig, dest):
        '''Function to insert the head of origin to dest stack in order'''


    def minimo(self, stack):
        '''Function to grab the minimum value between heads and tail'''
        if len(self.a) > 2:
            minimo = min(stack[0], stack[1], stack[-1])
            if minimo == stack[1]:
                self.swap(self.a)
            elif minimo == stack[-1]:
                self.reverse(self.a)
        elif len(self.a) == 2:
            if stack[0] > stack[1]:
                self.swap(self.a)


class Element:
    def __init__(self, number, index=-1):
        self.number = number
        self.index = index
        self.target = None

    def __str__(self):
        return (f'({self.number}|{self.index})')

    def __lt__(self, other):
         return self.number < other.number