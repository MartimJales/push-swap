def alg1(piles):
    '''Function to organize the stacks brute force mode'''
    min_index = max_index = -1
    while len(piles.a) > 0:
        piles.minimo(piles.a)
        if piles.b == []:
            piles.push(piles.a, piles.b)
            max_index = piles.b[0].index
            min_index = piles.b[0].index
        elif len(piles.b) == 1:
            piles.push(piles.a, piles.b)
            max_index = max(max_index, piles.b[0].index)
            min_index = min(min_index, piles.b[0].index)
        else:
            '''passar isto para uma função'''
            i = 0
            size = len(piles.b)
            if piles.a[0].index < min_index:
                target = max_index
                min_index = piles.a[0].index
            elif piles.a[0].index > max_index:
                target = max_index
                max_index = piles.a[0].index
            else:
                while i < size:
                    if piles.b[i].index < piles.a[0].index and piles.a[0].index < piles.b[i - 1].index:
                        target = piles.b[i].index
                    i += 1
            while piles.b[0].index != target:
                if i < (size / 2): 
                    piles.rotate(piles.b)
                else:
                    piles.reverse(piles.b)
            piles.push(piles.a, piles.b)
    '''isto tem que ser otimizado noutra função'''
    while piles.b[0].index != max_index:
        piles.rotate(piles.b)
    while len(piles.b) > 0:
        piles.push(piles.b, piles.a)