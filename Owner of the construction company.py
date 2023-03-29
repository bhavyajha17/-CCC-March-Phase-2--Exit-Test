def maxProfit(costPerCut, salePrice, len):
    # Find the shortest rod length
    shortest_len = min(len)
    
    # Iterate over all possible sale lengths that are factors of the shortest length
    max_profit = 0
    for i in range(1, shortest_len+1):
        if shortest_len % i == 0:
            # Calculate the number of rods that can be cut to the sale length
            uniform_rods = 0
            for j in len:
                uniform_rods += j // i
            
            # Calculate the total length of all the rods that will be sold
            total_length = uniform_rods * i
            
            # Calculate the number of cuts needed
            total_cuts = 0
            for j in len:
                # Count the number of cuts needed for each rod
                cuts = (j // i) - 1 if j % i == 0 else j // i
                total_cuts += cuts
            
            # Calculate the profit for this sale length
            profit = uniform_rods * i * salePrice - total_cuts * costPerCut
            
            # Update the maximum profit
            max_profit = max(max_profit, profit)
    
    return max_profit
