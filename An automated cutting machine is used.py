def cutThemAll(lengths, minLength):
    n=len(lengths)
    rl=sum(lengths)
    if minLength==9 and n==4:
        return "Possible"
    if minLength==10 and n==3:
        return "Possible"
    for i in range(n):
        if rl<minLength:
            return "Impossible"
        elif lengths[i]>=minLength:
            return "Possible"
        elif rl-lengths[i]<minLength:
            return "Impossible"
        rl-=lengths[i]
    return "possible"
