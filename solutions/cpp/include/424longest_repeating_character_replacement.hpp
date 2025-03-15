#include <array>
#include <string>
#include <vector>

class Solution {
public:
  int characterReplacement(const std::string& s, const int k) {
    std::array<int, 26> records{};
    auto left{0uz};
    int longest_str{0}, max_count{0};

    for (auto right = 0uz; right < s.size(); ++right) {
      // update the maximum seen element
      max_count = std::max(max_count, ++records[s[right] - 'A']);

      // imagine when left and right point is the same
      // the size of the window is 1 right?
      int window_size = right - left + 1; // therefore the + 1
      if (window_size - max_count > k) {
        --records[s[left++] - 'A'];
      } else {
        longest_str = std::max(longest_str, window_size);
      }
    }
    return longest_str;
  }
};

// Another Solution...
class AnotherSolution
{
public:
  int characterReplacement(const std::string& s, const int k) {
    std::vector<int> freq(26, 0);
    int left = 0, max_count = 0, max_length = 0;

    for (int right = 0; right < s.size(); ++right) {
      max_count = std::max(max_count, ++freq[s[right] - 'A']);

      if ((right - left + 1) - max_count > k) {
        --freq[s[left] - 'A'];
        ++left;
      }

      max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
  }
};
