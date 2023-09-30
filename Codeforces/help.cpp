#include <iostream>
#include <vector>

std::vector<int> schedule_work(int a, std::vector<std::vector<int>>& b) {
    int m = b.size();
    std::vector<int> output(a + 1, -1);  // Initialize output vector with -1
    
    for (int i = 0; i < m; ++i) {
        int start_day = b[i][0];
        int end_day = b[i][1];
        int time_required = b[i][2];
        
        for (int day = start_day; day <= end_day; ++day) {
            if (output[day] == -1) {
                output[day] = i + 1;  // Work i+1 can be done on day
            } else {
                output[day] = m + 1;  // Deadline reached, no other work can be done
            }
        }
    }
    
    output.erase(output.begin());  // Remove the first element (-1) from the output vector
    return output;
}

int main() {
    int a = 6;
    std::vector<std::vector<int>> b = {{1, 5, 1}, {1, 6, 1}, {1, 2, 1}};
    std::vector<int> result = schedule_work(a, b);

    // Print the result
    for (int task : result) {
        std::cout << task << " ";
    }

    return 0;
}
