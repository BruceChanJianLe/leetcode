#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

// Implement my own transform_exclusive_scan
template <typename InputIt, typename OutputIt, typename T, typename BinaryOp,
          typename UnaryOp>
OutputIt transform_exclusive_scan(InputIt first, InputIt last, OutputIt d_first,
                                  T init, BinaryOp binary_op,
                                  UnaryOp unary_op) {
  if (first == last)
    return d_first;

  T temp = init;
  for (; first != last; ++first) {
    *d_first++ = *d_first * temp;
    temp = binary_op(temp, unary_op(*first));
  }
  return d_first;
}

// Implement my own exclusive_scan (seems like need not the transform action)
template <typename InputIt, typename OutputIt, typename T, typename BinaryOp>
OutputIt exclusive_scan(InputIt first, InputIt last, OutputIt d_first,
                                  T init, BinaryOp binary_op) {
  if (first == last)
    return d_first;

  T temp = init;
  for (; first != last; ++first) {
    *d_first++ = *d_first * temp;
    temp = binary_op(temp, *first);
  }
  return d_first;
}

class FirstSolution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> result(nums.size(), 1);

    // Compute prefix multiplication
    for (int index = 1; index < nums.size(); ++index) {
      result[index] *= result[std::max(0, index - 1)] * nums[index - 1];
    }

    // std::cout << '[';
    // for (const auto &res : result) {
    //   std::cout << res << ',';
    // }
    // std::cout << ']' << '\n';

    // Compute postfix multiplication
    int postfix_value{1};
    for (int index = nums.size() - 1; index >= 0; --index) {
      result[index] *= postfix_value;
      postfix_value *= nums[index];
      std::cout << "index: " << index << ", postfix: " << postfix_value << '\n';
    }

    // std::cout << '[';
    // for (const auto &res : result) {
    //   std::cout << res << ',';
    // }
    // std::cout << ']' << '\n';

    return result;
  }
};

class SecondSolution {
public:
  std::vector<int> productExceptSelf(const std::vector<int> &num) {
    std::vector<int> result(num.size(), 1);

    ::transform_exclusive_scan(num.begin(), num.end(), result.begin(), 1,
                               std::multiplies<int>(),
                               [](const int &x) { return x; });

    ::transform_exclusive_scan(num.rbegin(), num.rend(), result.rbegin(), 1,
                               std::multiplies<int>(),
                               [](const int &x) { return x; });
    return result;
  }
};

class ThirdSolution {
public:
  std::vector<int> productExceptSelf(const std::vector<int>& num) {
    std::vector<int> prefix(num.size());
    std::vector<int> suffix(num.size());
    std::vector<int> result(num.size());

    // Calculate prefix
    std::exclusive_scan(num.begin(), num.end(), prefix.begin(), 1, std::multiplies<>{});
    // Calculate suffix
    std::exclusive_scan(num.rbegin(), num.rend(), suffix.rbegin(), 1, std::multiplies<>{});
    // Calculate result
    std::transform(prefix.begin(), prefix.end(), suffix.begin(), result.begin(), std::multiplies<>{});

    return result;
  }
};

class FourthSolution {
public:
  std::vector<int> productExceptSelf(const std::vector<int>& num) {
    std::vector<int> result(num.size(), 1);

    // Calculate prefix
    ::exclusive_scan(num.begin(), num.end(), result.begin(), 1, std::multiplies<>{});
    // Calculate suffix
    ::exclusive_scan(num.rbegin(), num.rend(), result.rbegin(), 1, std::multiplies<>{});

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
//       std::ranges::partial_sum(nums | std::views::drop(1), left.begin() + 1,
//       std::multiplies<int>());
//
//       // Calculate right products using a reverse view
//       std::vector<int> right(length, 1);
//       std::ranges::partial_sum(nums | std::views::reverse |
//       std::views::drop(1), right.rbegin() + 1, std::multiplies<int>());
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
//     std::transform(result.rbegin(), result.rend(), result.rbegin(),
//     [&rightProduct](int current) {
//         int temp = current * rightProduct; // Store the product of left and
//         right rightProduct *= current; // Update right product return temp;
//         // Return the product
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
