def alg2(piles):
    '''Fucntion to organize stacks catching the min_indexs from a directly to b'''
    min_index = 0
    while len(piles.a) > 0:
        if find_move(piles, min_index):
            while piles.a[0].index != min_index:
                piles.rotate(piles.a)
        else:
            while piles.a[0].index != min_index:
                piles.reverse(piles.a)
        piles.push(piles.a, piles.b)
        min_index += 1
    while len(piles.b) > 0:
        piles.push(piles.b, piles.a)


def find_move(piles, min_index):
    size = len(piles.a) // 2
    for elem in piles.a:
        if not size:
            return False
        if min_index == elem.index:
            return True
        size -= 1