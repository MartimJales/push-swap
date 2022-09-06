from Controls import Piles
from Alg1 import alg1
from Alg2 import alg2
from Check import check
import random

def main():
    result = []
    print('TEST == 1')
    for i in range(100):
        piles = Piles(size = 100)
        piles.index()
        alg1(piles)
        if check(piles):
            result.append(piles.moves)
        else:
            print(piles)
            print('UNSORTED')
            return 1
    avg = int(sum(result) / len(result))
    print('Average 1: ' + str(avg))
    print('TEST == 2')
    for i in range(100):
        piles = Piles(size = 100)
        piles.index()
        alg2(piles)
        if check(piles):
            result.append(piles.moves)
        else:
            print(piles)
            print('UNSORTED')
            return 1
    avg = int(sum(result) / len(result))
    print('Average 2: ' + str(avg))
    

if __name__ == '__main__':
    main()