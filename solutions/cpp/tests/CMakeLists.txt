include(GoogleTest)

function(add_leetcode_test name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} gtest_main)
  target_include_directories(${name} PRIVATE ../include)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

# 1 two sum test
add_leetcode_test(1two_sum_test)
# 2 add two numbers test
add_leetcode_test(2add_two_numbers_test)
# 3 longest substring without repeating characters test
add_leetcode_test(3longest_substring_without_repeating_characters_test)
# 4 median of two sorted arrays test
add_leetcode_test(4median_of_two_sorted_arrays_test)
# 5 longest palindromic substring test
add_leetcode_test(5longest_palindromic_substring_test)

# ==================================================================

# 11 container with most water test
add_leetcode_test(11container_with_most_water_test)
# 15 three sum test
add_leetcode_test(15three_sum_test)

# ==================================================================

# 17 letter combinations of a phone number test
add_leetcode_test(17letter_combinations_of_a_phone_number_test)
# 19 remove nth node from end of list test
add_leetcode_test(19remove_nth_node_from_end_of_list_test)
# 20 valid parentheses test
add_leetcode_test(20valid_parentheses_test)

# ==================================================================

# 21 merge two sorted lists test
add_leetcode_test(21merge_two_sorted_lists_test)
# 22 generate parentheses test
add_leetcode_test(22generate_parentheses_test)
# 23 merge k sorted list test
add_leetcode_test(23merge_k_sorted_lists_test)
# 25 reverse nodes in k group test
add_leetcode_test(25reverse_nodes_in_k_group_test)

# ==================================================================

# 33 search in rotated sorted array test
add_leetcode_test(33search_in_rotated_sorted_array_test)
# 36 valid sudoku test
add_leetcode_test(36valid_sudoku_test)
# 39 combination sum test
add_leetcode_test(39combination_sum_test)

# ==================================================================

# 40 combination sum ii test
add_leetcode_test(40combination_sum_ii_test)
# 42 trapping rain
add_leetcode_test(42trapping_rain_water_test)

# ==================================================================

# 46 permutations test
add_leetcode_test(46permutations_test)
# 49 group anagrams test
add_leetcode_test(49group_anagrams_test)

# ==================================================================

# 51 n queens test
add_leetcode_test(51n_queens_test)
# 52 n queens ii test
add_leetcode_test(52n_queens_ii_test)
# 53 maximum subarray test
add_leetcode_test(53maximum_subarray_test)

# ==================================================================

# 70 climbing stairs test
add_leetcode_test(70climbing_stairs_test)

# ==================================================================

# 74 search a 2d matrix test
add_leetcode_test(74search_a_2d_matrix_test)
# 76 minimum window substring test
add_leetcode_test(76minimum_window_substring_test)
# 77 combinations
add_leetcode_test(77combinations_test)
# 78 subsets test
add_leetcode_test(78subsets_test)
# 79 word search test
add_leetcode_test(79word_search_test)

# ==================================================================

# 84 largest rectangle in histogram test
add_leetcode_test(84largest_rectangle_in_histogram_test)

# ==================================================================

# 90 subsets ii test
add_leetcode_test(90subsets_ii_test)
# 91 decode ways test
add_leetcode_test(91decode_ways_test)
# 92 reverse linked list ii test
add_leetcode_test(92reverse_linked_list_ii_test)

# ==================================================================

# 98 validtate binary search tree test
add_leetcode_test(98validate_binary_search_tree_test)

# ==================================================================

# 100 same tree test
add_leetcode_test(100same_tree_test)
# 102 binary tree level order traversal test
add_leetcode_test(102binary_tree_level_order_traversal_test)
# 104 maximum depth of binary tree test
add_leetcode_test(104maximum_depth_of_binary_tree_test)
# 105 construct binary tree rom preorder and inorder traversal test
add_leetcode_test(105construct_binary_tree_from_preorder_and_inorder_traversal_test)

# ==================================================================

# 110 balanced binary tree test
add_leetcode_test(110balanced_binary_tree_test)

# ==================================================================

# 121 best time to buy and sell stock test
add_leetcode_test(121best_time_to_buy_and_sell_stock_test)
# 124
add_leetcode_test(124binary_tree_maximum_path_sum_test)
# 125 valid palindrome test
add_leetcode_test(125valid_palindrome_test)
# 128 longest consecutive sequence test
add_leetcode_test(128longest_consecutive_sequence_test)

# ==================================================================

# 131 palindrome partitioning test
add_leetcode_test(131palindrome_partitioning_test)

# ==================================================================

# 138 copy list with random pointer test
add_leetcode_test(138copy_list_with_random_pointer_test)

# 139 word break test
add_leetcode_test(139word_break_test)

# ==================================================================

# 141 linked list cycle test
add_leetcode_test(141linked_list_cycle_test)
# 143 reorder list test
add_leetcode_test(143reorder_list_test)
# 146 lru cache test
add_leetcode_test(146lru_cache_test)

# ==================================================================

# 150 evaluate reverse polish notation test
add_leetcode_test(150evaluate_reverse_polish_notation_test)
# 152 maximum product subarray test
add_leetcode_test(152maximum_product_subarray_test)
# 153 find minimum in rotated sorted array
add_leetcode_test(153find_minimum_in_rotated_sorted_array_test)
# 155 min stack test
add_leetcode_test(155min_stack_test)

# ==================================================================

# 167 add two numbers ii test
add_leetcode_test(167two_sum_ii_test)

# ==================================================================

# 198 house robber test
add_leetcode_test(198house_robber_test)
# 199 binary tree right side view test
add_leetcode_test(199binary_tree_right_side_view_test)
# 200 number of island test
add_leetcode_test(200number_of_islands_test)

# ==================================================================

# 206 reverse linked list test
add_leetcode_test(206reverse_linked_list_test)
# 208 implement trie prefix tree test
add_leetcode_test(208implement_trie_prefix_tree_test)

# ==================================================================

# 211 design add and search words data structure test
add_leetcode_test(211design_add_and_search_words_data_structure_test)
# 212 word search ii test
add_leetcode_test(212word_search_ii_test)
# 213 house robber ii test
add_leetcode_test(213house_robber_ii_test)

# ==================================================================

# 215 kth largest element in an array test
add_leetcode_test(215kth_largest_element_in_an_array_test)
# 216 combination sum iii test
add_leetcode_test(216combination_sum_iii_test)
# 217 contains duplicate test
add_leetcode_test(217contains_duplicate_test)
# 219 contains duplicate ii test
add_leetcode_test(219contains_duplicate_ii_test)

# ==================================================================

# 226 invert binary tree
add_leetcode_test(226invert_binary_tree_test)

# ==================================================================

# 230 kth smallest element in a binary search tree test
add_leetcode_test(230kth_smallest_element_in_a_bst_test)

# ==================================================================

# 235 lowest common ancestor of a binary search tree test
add_leetcode_test(235lowest_common_ancestor_of_a_binary_search_tree_test)
# 236 lowest common ancestor of a binary tree test
add_leetcode_test(236lowest_common_ancestor_of_a_binary_tree_test)
# 238 product of array except self test
add_leetcode_test(238product_of_array_except_self_test)
# 239 sliding window maximum test
add_leetcode_test(239sliding_window_maximum_test)

# ==================================================================

# 242 valid anagram test
add_leetcode_test(242valid_anagram_test)
# 271 encode and decode strings
add_leetcode_test(271encode_and_decode_strings_test)
# 287 find the duplicate number test
add_leetcode_test(287find_the_duplicate_number_test)
# 297 serialize and deserialize binary tree test
add_leetcode_test(297serialize_and_deserialize_binary_tree_test)

# ==================================================================

# 300 longest increasing subsequence test
add_leetcode_test(300longest_increasing_subsequence_test)

# ==================================================================

# 322 coin change test
add_leetcode_test(322coin_change_test)

# 347 top k frequent elements test
add_leetcode_test(347top_k_frequent_elements_test)

# ==================================================================

# 424 longest repeating character replacement test
add_leetcode_test(424longest_repeating_character_replacement_test)
# 496 next greater element i test
add_leetcode_test(496next_greater_element_i_test)

# ==================================================================

# 509 fibonacci number test
add_leetcode_test(509fibonacci_number_test)

# ==================================================================

# 518 coin change ii test
add_leetcode_test(518coin_change_ii_test)
# 543 diameter of binary tree test
add_leetcode_test(543diameter_of_binary_tree_test)
# 567 permutation in string test 
add_leetcode_test(567permutation_in_string_test)
# 572 subtree of another tree test
add_leetcode_test(572subtree_of_another_tree_test)

# ==================================================================

# 647 palindromic substrings test
add_leetcode_test(647palindromic_substrings_test)

# ==================================================================

# 704 binary search test
add_leetcode_test(704binary_search_test)
# 739 daily temperature test
add_leetcode_test(739daily_temperatures_test)
# 746 min cost climbing stairs test
add_leetcode_test(746min_cost_climbing_stairs_test)

# ==================================================================

# 835 car fleet test
add_leetcode_test(853car_fleet_test)

# 846 hand of straight
add_leetcode_test(846hand_of_straights_test)

# ==================================================================

# 875 koko eating bananas test
add_leetcode_test(875koko_eating_bananas_test)
# 876 middle of the linked list test
add_leetcode_test(876middle_of_the_linked_list_test)

# ==================================================================

# 912 sort an array test
add_leetcode_test(912sort_an_array_test)
# 981 time based key value store test
add_leetcode_test(981time_based_key_value_store_test)

# ==================================================================

# 1448 count good nodes in binary tree test
add_leetcode_test(1448count_good_nodes_in_binary_tree_test)

# ==================================================================

# 1804 implement trie ii prefix tree test
add_leetcode_test(1804implement_trie_ii_prefix_tree_test)

# ==================================================================

# 2574 left and right sum difference test
add_leetcode_test(2574left_and_right_sum_differences_test)
