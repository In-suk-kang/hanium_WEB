def getType(ai):
    vul_dict = {
        0: 'secure',
        1:'Stack Overflow',
        2:'Heap Overflow',
    }
    data = vul_dict[ai]
    return data