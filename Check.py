from Controls import Piles, Element

def check(piles: Piles):
    indexs = []
    for elem in piles.a:
        indexs.append(elem.index)
    if indexs == sorted(indexs):
        return 1
    return 0