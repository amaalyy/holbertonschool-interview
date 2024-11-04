#!/usr/bin/python3
"""
Given a list of non-negative integers representing
the heights of walls with unit width 1
"""


def rain(walls):
    """
    Integer indicating total amount of rainwater retained.
    return 0 if the list is empty.
    """
    n = len(walls)
    total_water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        total_water = total_water + (min(left, right) - walls[i])
    return total_water
