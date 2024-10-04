#pragma once

#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <ranges>

class FirstSolution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> result(nums.size(), 1);

    // Compute prefix multiplication
    for (int index = 1; index < nums.size(); ++index){
      result[index] *= result[std::max(0, index - 1)] * nums[index - 1];
    }

    std::cout << '[';
    for (const auto& res : result)
    {
      std::cout << res << ',';
    }
    std::cout << ']' << '\n';

    // Compute postfix multiplication
    int postfix_value{1};
    for (int index = nums.size() - 1; index >= 0; --index){
      result[index] *= postfix_value;
      postfix_value *= nums[index];
      std::cout << "index: " << index << ", postfix: " << postfix_value << '\n';
    }

    std::cout << '[';
    for (const auto& res : result)
    {
      std::cout << res << ',';
    }
    std::cout << ']' << '\n';

    return result;
  }
};

class SecondSolution {
public:
  std::vector<int> productExceptSelf(const std::vector<int> &num) {
    std::vector<int> padded_result(num.size() + 2, 1);
    std::vector<int> result(num.size(), 1);
    // std::transform(num.begin(), num.end(), padded_result.begin(), std::begin(padded_result), 
    //     [](const int& val1, const int& val) { return val; });

    std::transform_exclusive_scan(num.begin(), num.end(), result.begin(),
        1, 
        std::multiplies<int>(), [](const int& x) { return x; });

    std::cout << '[';
    for (const auto& res : result)
    {
      std::cout << res << ',';
    }
    std::cout << ']' << '\n';

    int rightProduct = 1;
    std::transform(result.rbegin(), result.rend(), result.rbegin(), [&rightProduct](int current) {
        int temp = current * rightProduct; // Store the product of left and right
        rightProduct *= current; // Update right product
        return temp; // Return the product
    });
    std::cout << '[';
    for (const auto& res : result)
    {
      std::cout << res << ',';
    }
    std::cout << ']' << '\n';

    return result;
  }
};


// GPT solution
// class GPTSolution {
// public:
//   std::vector<int> productExceptSelf(std::vector<int> &nums) {
//       int length = nums.size();
//
//       // Create a vector for the final answer
//       std::vector<int> answer(length);
//
//       // Calculate left products
//       std::vector<int> left(length, 1);
//       std::ranges::partial_sum(nums | std::views::drop(1), left.begin() + 1, std::multiplies<int>());
//
//       // Calculate right products using a reverse view
//       std::vector<int> right(length, 1);
//       std::ranges::partial_sum(nums | std::views::reverse | std::views::drop(1), right.rbegin() + 1, std::multiplies<int>());
//
//       // Combine left and right products
//       for (int i = 0; i < length; ++i) {
//         answer[i] = left[i] * right[i];
//       }
//       return answer;
//   }
// };

// #include <vector>
// #include <iostream>
// #include <numeric>
// #include <execution>
//
// std::vector<int> productExceptSelf(const std::vector<int>& nums) {
//     int n = nums.size();
//     std::vector<int> result(n, 1);
//
//     // Step 1: Calculate left products using exclusive scan
//     std::transform_exclusive_scan(
//         std::execution::par,
//         nums.begin(), nums.end(),
//         result.begin(),
//         1, // Initial value for multiplication
//         std::multiplies<int>(), // Binary operation for multiplication
//         [](int x) { return x; } // Identity function
//     );
//
//     // Step 2: Calculate right products in place using std::transform
//     int rightProduct = 1;
//     std::transform(result.rbegin(), result.rend(), result.rbegin(), [&rightProduct](int current) {
//         int temp = current * rightProduct; // Store the product of left and right
//         rightProduct *= current; // Update right product
//         return temp; // Return the product
//     });
//
//     return result;
// }
//
// int main() {
//     std::vector<int> nums = {1, 2, 3, 4};
//     std::vector<int> result = productExceptSelf(nums);
//
//     for (const auto& val : result) {
//         std::cout << val << " "; // Output: 24 12 8 6
//     }
// }

