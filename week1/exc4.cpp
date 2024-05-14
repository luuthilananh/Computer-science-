#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;  // Input the number of elements

    int max_abs_val = 0;
    int max_abs_num = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;  // Input the current number

        // Calculate the absolute value of the current number
        int abs_val = std::abs(num);

        // Update the maximum absolute value if the absolute value of the current number is greater
        if (abs_val > max_abs_val) {
            max_abs_val = abs_val;
            max_abs_num = num;
        }
    }

    // Output the maximum absolute value
    std::cout << max_abs_num << std::endl;

    return 0;
}
