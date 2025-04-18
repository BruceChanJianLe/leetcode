#!/usr/bin/env python3

import os
import re

# Paths
QUESTIONS_DIR = "./questions"
INCLUDE_DIR = "./solutions/cpp/include"
TESTS_DIR = "./solutions/cpp/tests"

# Output Table
table = []
header = "| # | Title | Status | Solution | Test | Category | Question \n"
header += "|:-:|:------|:-----|:--------|:---------|:-----|:--------\n"


# Helper function to format titles nicely
def format_title(raw_title):
    parts = re.split(r"[\.\-_]", raw_title, maxsplit=1)
    if len(parts) != 2:
        return None
    number, name = parts
    title = name.replace("-", " ").replace("_", " ").replace(".txt", "")
    title = title.strip().title()
    return int(number), title


# Process each question
for filename in sorted(os.listdir(QUESTIONS_DIR)):
    if filename.endswith(".txt"):
        info = format_title(filename)
        if info is None:
            continue
        number, title = info
        number_str = str(number)

        # Find matching solution header and test file
        slug = filename.replace(".", "").replace("-", "_").replace("txt", "")
        solution_file = f"{INCLUDE_DIR}/{slug}.hpp"
        print(solution_file)
        test_file = f"{TESTS_DIR}/{slug}_test.cpp"

        # Check if they exist
        solution_link = (
            f"[Solution]({solution_file})" if os.path.exists(solution_file) else "❌"
        )
        test_link = f"[Test]({test_file})" if os.path.exists(test_file) else "❌"

        status = (
            "✅" if os.path.exists(solution_file) and os.path.exists(test_file) else "❌"
        )

        # LeetCode link
        leetcode_link = f"[Link](https://leetcode.com/problems/{title.lower().replace(' ', '-').replace('.txt', '')}/)"

        row = f"| {number} | {title} | {status} | {solution_link} | {test_link} | Others | {leetcode_link} \n"
        table.append(row)

# Print full table
print(header + "".join(table))
