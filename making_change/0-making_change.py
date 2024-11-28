#!/usr/bin/python3
"""
makeChange
"""


def makeChange(coins, total):
    """
    fewest number of coins needed to meet totat
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    """

    if total <= 0:
        return 0
    if total in coins:
        return 1
    if len(coins) <= 0:
        return -1
    M = [0]*(total + 1)

    for j in range(1, total + 1):
        M[j] = total + 1

    for i in range(1, total+1):
        for coin in coins:
            if i - coin >= 0:
                M[i] = min(M[i], 1 + M[i - coin])
    return M[total] if M[total] != total + 1 else -1
