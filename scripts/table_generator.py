#!/usr/bin/env python3
"""Generate the solutions table in README.md from what is actually on disk.

Each questions/<number>.<slug>.txt carries the canonical title, the difficulty and
the real LeetCode URL in its header, so those are scraped rather than guessed from
the filename (guessing gets #15 and #167 wrong). Categories live in CATEGORY below
so a new problem is classified in one place instead of by hand-editing markdown.
"""

import os
import re

# Paths
QUESTIONS_DIR = "./questions"
INCLUDE_DIR = "./solutions/cpp/include"
TESTS_DIR = "./solutions/cpp/tests"

DIFFICULTY_ICON = {"Easy": "🟢", "Medium": "🟠", "Hard": "🔴"}

# How many leading lines of a question file count as its header.
HEADER_LINES = 8

# Problem number -> category. Anything unmapped falls back to "Others".
CATEGORY = {
    # Arrays & Hashing
    1: "Arrays & Hashing", 36: "Arrays & Hashing", 49: "Arrays & Hashing",
    128: "Arrays & Hashing", 217: "Arrays & Hashing", 238: "Arrays & Hashing",
    242: "Arrays & Hashing", 271: "Arrays & Hashing", 347: "Arrays & Hashing",
    2574: "Arrays & Hashing",
    # Two Pointers
    11: "Two Pointers", 15: "Two Pointers", 42: "Two Pointers",
    125: "Two Pointers", 167: "Two Pointers",
    # Sliding Window
    3: "Sliding Window", 76: "Sliding Window", 121: "Sliding Window",
    219: "Sliding Window", 239: "Sliding Window", 424: "Sliding Window",
    567: "Sliding Window",
    # Stack
    20: "Stack", 22: "Stack", 84: "Stack", 150: "Stack", 155: "Stack",
    496: "Stack", 739: "Stack", 853: "Stack",
    # Binary Search
    4: "Binary Search", 33: "Binary Search", 74: "Binary Search",
    153: "Binary Search", 704: "Binary Search", 875: "Binary Search",
    981: "Binary Search",
    # Linked List
    2: "Linked List", 19: "Linked List", 21: "Linked List", 23: "Linked List",
    25: "Linked List", 92: "Linked List", 138: "Linked List", 141: "Linked List",
    143: "Linked List", 146: "Linked List", 206: "Linked List",
    287: "Linked List", 876: "Linked List",
    # Trees
    98: "Trees", 100: "Trees", 102: "Trees", 104: "Trees", 105: "Trees",
    110: "Trees", 124: "Trees", 199: "Trees", 226: "Trees", 230: "Trees",
    235: "Trees", 236: "Trees", 297: "Trees", 543: "Trees", 572: "Trees",
    1448: "Trees",
    # Tries
    208: "Tries", 211: "Tries", 212: "Tries", 1804: "Tries",
    # Backtracking
    17: "Backtracking", 39: "Backtracking", 40: "Backtracking",
    46: "Backtracking", 51: "Backtracking", 52: "Backtracking",
    77: "Backtracking", 78: "Backtracking", 79: "Backtracking",
    90: "Backtracking", 131: "Backtracking", 216: "Backtracking",
    # Graphs
    133: "Graphs", 200: "Graphs",
    # 1-D DP
    5: "1-D DP", 70: "1-D DP", 91: "1-D DP", 139: "1-D DP", 152: "1-D DP",
    198: "1-D DP", 213: "1-D DP", 300: "1-D DP", 322: "1-D DP", 416: "1-D DP",
    509: "1-D DP", 518: "1-D DP", 647: "1-D DP", 746: "1-D DP",
    # Greedy
    53: "Greedy",
    # Heap / Priority Queue
    846: "Heap / Priority Queue",
}

# Metadata for problems whose question file is missing or empty, so the table never
# emits a broken row. Remove an entry once its question file is re-dumped.
OVERRIDES = {
    92: ("Reverse Linked List II", "Medium", "reverse-linked-list-ii"),
    509: ("Fibonacci Number", "Easy", "fibonacci-number"),
}

HEADER = (
    "| # | Title | Status | Solution | Test | Category | Question | Difficulty\n"
    "|:-:|:------|:-----|:--------|:---------|:-----|:--------|---\n"
)


def base_from_question(filename):
    """1.two-sum.txt -> 1two_sum (matches the include/ and tests/ naming)."""
    stem = filename[:-4] if filename.endswith(".txt") else filename
    number, _, name = stem.partition(".")
    return f"{number}{name.replace('-', '_')}"


def parse_question(path, number):
    """Scrape (title, difficulty, slug) from a question file header."""
    with open(path, encoding="utf-8", errors="replace") as handle:
        text = handle.read()

    slug = None
    url_match = re.search(r"https://leetcode\.com/problems/([A-Za-z0-9-]+)", text)
    if url_match:
        slug = url_match.group(1)

    # Only the first few lines are the header; searching further risks matching
    # body prose that happens to start with the problem number.
    header = "\n".join(text.splitlines()[:HEADER_LINES])

    title = None
    # Padded for centering, hence the strip. The dot is optional because Premium
    # problems are dumped as "271 String Encode and Decode" with no separator.
    title_match = re.search(rf"^\s*{number}\.?\s+(.+?)\s*$", header, re.MULTILINE)
    if title_match:
        title = title_match.group(1)

    difficulty = None
    difficulty_match = re.search(r"\b(Easy|Medium|Hard)\b", header)
    if difficulty_match:
        difficulty = difficulty_match.group(1)

    return title, difficulty, slug


def collect():
    """Union every problem number known from questions/ and from include/."""
    problems = {}

    for filename in os.listdir(QUESTIONS_DIR):
        if not filename.endswith(".txt"):
            continue
        number_text = filename.partition(".")[0]
        if not number_text.isdigit():
            continue
        number = int(number_text)
        problems[number] = {
            "base": base_from_question(filename),
            "question": os.path.join(QUESTIONS_DIR, filename),
        }

    for filename in sorted(os.listdir(INCLUDE_DIR)):
        if not filename.endswith(".hpp"):
            continue
        match = re.match(r"^(\d+)", filename)
        if not match:
            continue
        number = int(match.group(1))
        problems.setdefault(number, {"base": filename[:-4], "question": None})

    return problems


def main():
    rows = []

    for number, info in sorted(collect().items()):
        base = info["base"]

        title = difficulty = slug = None
        if info["question"]:
            title, difficulty, slug = parse_question(info["question"], number)

        override = OVERRIDES.get(number)
        if override:
            title = title or override[0]
            difficulty = difficulty or override[1]
            slug = slug or override[2]

        if not (title and difficulty and slug):
            raise SystemExit(
                f"cannot resolve metadata for problem {number} ({base}); "
                f"re-dump its question file or add an OVERRIDES entry"
            )

        solution_file = f"{INCLUDE_DIR}/{base}.hpp"
        test_file = f"{TESTS_DIR}/{base}_test.cpp"
        has_solution = os.path.exists(solution_file)
        has_test = os.path.exists(test_file)

        solution_link = f"[Solution]({solution_file})" if has_solution else "❌"
        test_link = f"[Test]({test_file})" if has_test else "❌"
        status = "✅" if has_solution and has_test else "❌"

        category = CATEGORY.get(number, "Others")
        question_link = f"[Link](https://leetcode.com/problems/{slug}/)"
        icon = DIFFICULTY_ICON[difficulty]

        rows.append(
            f"| {number} | {title} | {status} | {solution_link} | {test_link} "
            f"| {category} | {question_link} | {icon}\n"
        )

    print(HEADER + "".join(rows), end="")


if __name__ == "__main__":
    main()
