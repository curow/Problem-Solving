def solve_knapsack(profits, weights, capicity):
    def recursive_solve_knapsack(choice_made, current_profit, remain_capicity):
        if len(choice_made) >= len(profits) or remain_capicity <= 0:
            return choice_made, current_profit
        next_choice = len(choice_made)
        choice_without_next_item, profit_without_next_item = \
                recursive_solve_knapsack(choice_made + [0], current_profit, remain_capicity)

        profit_with_next_item = 0
        if remain_capicity - weights[next_choice] >= 0:
            choice_with_next_item, profit_with_next_item = \
                    recursive_solve_knapsack(choice_made + [1],
                            current_profit + profits[next_choice],
                            remain_capicity - weights[next_choice])
        if profit_without_next_item > profit_with_next_item:
            choice = choice_without_next_item
            profit = profit_without_next_item
        else:
            choice = choice_with_next_item
            profit = profit_with_next_item
        return choice, profit

    choice, profit = recursive_solve_knapsack([], 0, capicity)
    while len(choice) < len(profits):
        choice.append(0)
    return choice, profit

def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))

main()
