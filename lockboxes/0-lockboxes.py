#!/usr/bin/python3
"""
Lockboxes
"""


def canUnlockAll(boxes):
    """
    method that determines if all the boxes can be opened.
    """
    n = len(boxes)
    opened = [False] * n
    Result = [0]

    opened[0] = True

    while Result:
        current_box = Result.pop()

        for key in boxes[current_box]:
            if 0 <= key < n and not opened[key]:
                opened[key] = True
                Result.append(key)

    return all(opened)
