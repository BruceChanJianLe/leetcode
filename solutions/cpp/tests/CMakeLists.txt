# 1 two sum test
add_executable(1two_sum_test ./1two_sum_test.cpp)
target_link_libraries(1two_sum_test gtest_main)
target_include_directories(1two_sum_test PRIVATE ../include)

# 2 add two numbers test
add_executable(2add_two_numbers_test ./2add_two_numbers_test.cpp)
target_link_libraries(2add_two_numbers_test gtest_main)
target_include_directories(2add_two_numbers_test PRIVATE ../include)

# 11 container with most water test
add_executable(11container_with_most_water_test ./11container_with_most_water_test.cpp)
target_link_libraries(11container_with_most_water_test gtest_main)
target_include_directories(11container_with_most_water_test PRIVATE ../include)

# 15 three sum test
add_executable(15three_sum_test ./15three_sum_test.cpp)
target_link_libraries(15three_sum_test gtest_main)
target_include_directories(15three_sum_test PRIVATE ../include)

# 20 valid parentheses test
add_executable(20valid_parentheses_test ./20valid_parentheses_test.cpp)
target_link_libraries(20valid_parentheses_test gtest_main)
target_include_directories(20valid_parentheses_test PRIVATE ../include)

# ==================================================================

# 36 valid sudoku test
add_executable(36valid_sudoku_test ./36valid_sudoku_test.cpp)
target_link_libraries(36valid_sudoku_test gtest_main)
target_include_directories(36valid_sudoku_test PRIVATE ../include)

# 42 trapping rain
add_executable(42trapping_rain_water_test ./42trapping_rain_water_test.cpp)
target_link_libraries(42trapping_rain_water_test gtest_main)
target_include_directories(42trapping_rain_water_test PRIVATE ../include)

# 49 group anagrams test
add_executable(49group_anagrams_test ./49group_anagrams_test.cpp)
target_link_libraries(49group_anagrams_test gtest_main)
target_include_directories(49group_anagrams_test PRIVATE ../include)

# ==================================================================

# 125 valid palindrome test
add_executable(125valid_palindrome_test ./125valid_palindrome_test.cpp)
target_link_libraries(125valid_palindrome_test gtest_main)
target_include_directories(125valid_palindrome_test PRIVATE ../include)

# 128 longest consecutive sequence test
add_executable(128longest_consecutive_sequence_test ./128longest_consecutive_sequence_test.cpp)
target_link_libraries(128longest_consecutive_sequence_test gtest_main)
target_include_directories(128longest_consecutive_sequence_test PRIVATE ../include)

# 167 add two numbers ii test
add_executable(167two_sum_ii_test ./167two_sum_ii_test.cpp)
target_link_libraries(167two_sum_ii_test gtest_main)
target_include_directories(167two_sum_ii_test PRIVATE ../include)

# ==================================================================

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

# ==================================================================

# 347 top k frequent elements test
add_executable(347top_k_frequent_elements_test ./347top_k_frequent_elements_test.cpp)
target_link_libraries(347top_k_frequent_elements_test gtest_main)
target_include_directories(347top_k_frequent_elements_test PRIVATE ../include)

# Add tests
include(GoogleTest)
add_test(NAME 1two_sum_test COMMAND 1two_sum_test)
add_test(NAME 2add_two_numbers_test COMMAND 2add_two_numbers_test)
add_test(NAME 11container_with_most_water_test COMMAND 11container_with_most_water_test)
add_test(NAME 15three_sum_test COMMAND 15three_sum_test)
add_test(NAME 20valid_parentheses_test COMMAND 20valid_parentheses_test)

add_test(NAME 36valid_sudoku_test COMMAND 36valid_sudoku_test)
add_test(NAME 42trapping_rain_water_test COMMAND 42trapping_rain_water_test)
add_test(NAME 49group_anagrams_test COMMAND 49group_anagrams_test)

add_test(NAME 125valid_palindrome_test COMMAND 125valid_palindrome_test)
add_test(NAME 128longest_consecutive_sequence_test COMMAND 128longest_consecutive_sequence_test)
add_test(NAME 167two_sum_ii_test COMMAND 167two_sum_ii_test)

add_test(NAME 217contains_duplicate_test COMMAND 217contains_duplicate_test)
add_test(NAME 238product_of_array_except_self_test COMMAND 238product_of_array_except_self_test)
add_test(NAME 242valid_anagram_test COMMAND 242valid_anagram_test)
add_test(NAME 271encode_and_decode_strings_test COMMAND 271encode_and_decode_strings_test)

add_test(NAME 347top_k_frequent_elements_test COMMAND 347top_k_frequent_elements_test)
