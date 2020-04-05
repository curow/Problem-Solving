def solve_knapsack(profits, weights, capicity):
  dp = [[-1 for x in range(capicity + 1)] for y in range(len(profits))]
  N = len(profits)
  for y in range(N):
    dp[y][0] = 0
  for current_index in range(1, N):
    for 


def main():
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 7))
  print(solve_knapsack([1, 6, 10, 16], [1, 2, 3, 5], 6))

main()
