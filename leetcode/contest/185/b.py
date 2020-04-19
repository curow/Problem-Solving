class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        def parse_order(order):
            table = []
            table.append(order[1])
            for food in foods:
                if order[2] == food:
                    table.append(1)
                else:
                    table.append(0)
            return table
        orders = sorted(orders, key=lambda x: int(x[1]))
        foods = set()
        for order in orders:
            foods.add(order[2])
        foods = sorted(list(foods))
        head = ["Table"]
        head += foods
        all_table = [head]
        table = []
        for order in orders:
            if not table:
                table = parse_order(order)
            elif table[0] == order[1]:
                index = foods.index(order[2])
                table[index + 1] += 1
            else:
                all_table.append(table[:])
                table = parse_order(order)
        all_table.append(table)
        for i, table in enumerate(all_table):
            for j, x in enumerate(table):
                all_table[i][j] = str(x)
        return all_table
