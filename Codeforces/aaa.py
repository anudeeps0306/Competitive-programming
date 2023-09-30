def dfs(node, time, adjacency_list, time_taken):
    max_time = time
    for child in adjacency_list[node]:
        time_taken[child] = time_taken[node] + 1
        max_time = max(max_time, time_taken[child])
        max_time = max(max_time, dfs(child, time + 1, adjacency_list, time_taken))
    return max_time

# Read input
N = int(input())
adjacency_list = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, input().split())
    adjacency_list[u].append(v)

# Calculate the minimum number of hours
time_taken = [0] * (N + 1)
minimum_hours_required = dfs(1, 0, adjacency_list, time_taken)

# Output the result
print(minimum_hours_required)
