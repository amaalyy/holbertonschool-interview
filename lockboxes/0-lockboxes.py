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
