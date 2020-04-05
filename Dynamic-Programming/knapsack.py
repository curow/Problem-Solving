def solve_knapsack(profits, weights, capicity):
    dp = [[-1 for x in range(capicity + 1)] for y in range(len(profits))]
    def recursive_solve_knapsack(current_index, current_profit, remain_capicity):
        if current_index >= len(profits) or remain_capicity <= 0:
            return current_profit
        if dp[current_index][remain_capicity] >= 0:
            return dp[current_index][remain_capicity]

        profit_without_next_item = \
                recursive_solve_knapsack(current_index + 1, current_profit, remain_capicity)

        profit_with_next_item = 0
        if remain_capicity - weights[current_index] >= 0:
            profit_with_next_item = \
                    recursive_solve_knapsack(current_index + 1,
                            current_profit + profits[current_index],
                            remain_capicity - weights[current_index])
        profit = max(profit_with_next_item, profit_without_next_item)
        dp[current_index][remain_capicity] = profit
        return profit

    return recursive_solve_knapsack(0, 0, capicity)


def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))

main()
