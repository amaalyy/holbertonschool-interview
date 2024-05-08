#!/usr/bin/python3

def canUnlockAll(boxes):
    if not boxes:
        return False
    
    keys = [0]
    visited = [False] * len(boxes)
    visited[0] = True
    
    while keys:
        current_key = keys.pop()
        current_box = boxes[current_key]
        
        for key in current_box:
            if 0 <= key < len(boxes) and not visited[key]:
                visited[key] = True
                keys.append(key)
    
    return all(visited)


test_cases = [
    [[1], [2], [3], [4], []],
    [[1, 4, 5], [2], [5, 2], [3], [4, 1], [3, 5]],
    [[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]],
    [[0]],
]

for i, boxes in enumerate(test_cases):
    result = canUnlockAll(boxes)
    print(f"Correct output - case {i + 1}: {result}")
