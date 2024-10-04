# 1 two sum test
add_executable(1two_sum_test ./1two_sum_test.cpp)
target_link_libraries(1two_sum_test gtest_main)
target_include_directories(1two_sum_test PRIVATE ../include)

# 2 add two numbers test
add_executable(2add_two_numbers_test ./2add_two_numbers_test.cpp)
target_link_libraries(2add_two_numbers_test gtest_main)
target_include_directories(2add_two_numbers_test PRIVATE ../include)

# 49 group anagrams test
add_executable(49group_anagrams_test ./49group_anagrams_test.cpp)
target_link_libraries(49group_anagrams_test gtest_main)
target_include_directories(49group_anagrams_test PRIVATE ../include)

# 167 add two numbers ii test
add_executable(167two_sum_ii_test ./167two_sum_ii_test.cpp)
target_link_libraries(167two_sum_ii_test gtest_main)
target_include_directories(167two_sum_ii_test PRIVATE ../include)

# 217 contains duplicate test
add_executable(217contains_duplicate_test ./217contains_duplicate_test.cpp)
target_link_libraries(217contains_duplicate_test gtest_main)
target_include_directories(217contains_duplicate_test PRIVATE ../include)

# 238 product of array except self test
add_executable(238product_of_array_except_self_test ./238product_of_array_except_self_test.cpp)
target_link_libraries(238product_of_array_except_self_test gtest_main)
target_include_directories(238product_of_array_except_self_test PRIVATE ../include)

# 271 encode and decode strings
add_executable(271encode_and_decode_strings_test ./271encode_and_decode_strings_test.cpp)
target_link_libraries(271encode_and_decode_strings_test gtest_main)
target_include_directories(271encode_and_decode_strings_test PRIVATE ../include)

# 242 valid anagram test
add_executable(242valid_anagram_test ./242valid_anagram_test.cpp)
target_link_libraries(242valid_anagram_test gtest_main)
target_include_directories(242valid_anagram_test PRIVATE ../include)

# 347 top k frequent elements test
add_executable(347top_k_frequent_elements_test ./347top_k_frequent_elements_test.cpp)
target_link_libraries(347top_k_frequent_elements_test gtest_main)
target_include_directories(347top_k_frequent_elements_test PRIVATE ../include)

# Add tests
include(GoogleTest)
add_test(NAME 1two_sum_test COMMAND 1two_sum_test)
add_test(NAME 2add_two_numbers_test COMMAND 2add_two_numbers_test)
add_test(NAME 49group_anagrams_test COMMAND 49group_anagrams_test)

add_test(NAME 167two_sum_ii_test COMMAND 167two_sum_ii_test)
add_test(NAME 217contains_duplicate_test COMMAND 217contains_duplicate_test)
add_test(NAME 238product_of_array_except_self_test COMMAND 238product_of_array_except_self_test)
add_test(NAME 242valid_anagram_test COMMAND 242valid_anagram_test)
add_test(NAME 271encode_and_decode_strings_test COMMAND 271encode_and_decode_strings_test)
add_test(NAME 347top_k_frequent_elements_test COMMAND 347top_k_frequent_elements_test)
