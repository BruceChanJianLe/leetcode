#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      // Sanity check
      if (s.size() != t.size()) return false;

      std::unordered_map<char, int> store;
      for (auto itr : s)
      {
        ++store[itr];
      }

      for (auto itr : t)
      {
        --store[itr];
      }

      for (auto itr : store)
      {
        if (itr.second != 0) return false;
      }

      return true;
    }
};

class FirstSolution {
public:
    bool isAnagram(std::string s, std::string t) {
      // Sanity check
      if (s.size() != t.size()) return false;

      std::unordered_map<char, int> store;
      for (std::string::iterator itr = s.begin(); itr != s.end(); ++itr)
      {
        store[*itr] += 1;
      }

      for (std::string::iterator itr = t.begin(); itr != t.end(); ++itr)
      {
        if (auto search = store.find(*itr); search != store.end())
        {
          if (search->second == 0)
          {
            return false;
          }
          else
          {
            --search->second;
          }
        }
        else
        {
          return false;
        }
      }

      return true;
    }
};
