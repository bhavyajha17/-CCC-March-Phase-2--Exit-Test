def minimumGroups(predator):
    ans=0
    for i in predator:
        count=1
        temp=i
        while( temp > -1 ):
            count+=1
            temp = predator[temp]
        if(count>ans):
            ans=count
    return ans
