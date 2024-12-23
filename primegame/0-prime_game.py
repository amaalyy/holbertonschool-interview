#!/usr/bin/python3
"""
Prime Game
"""


def is_prime(num):
    """
    is prime
    """
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def get_primes(remaining_nums):
    """
    get primes
    """
    return [num for num in remaining_nums if is_prime(num)]


def play_round(remaining_nums):
    """
    play round
    """
    primes = get_primes(remaining_nums)
    if not primes:
        return "Ben"

    maria_choice = min(primes)
    remaining_nums = [
        num for num in remaining_nums if num % maria_choice != 0]

    primes = get_primes(remaining_nums)
    if not primes:
        return "Maria"

    ben_choice = min(primes)
    remaining_nums = [
        num for num in remaining_nums if num % ben_choice != 0]

    return play_round(remaining_nums)


def isWinner(x, nums):
    """
    is winner
    """
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        winner = play_round(list(range(1, n + 1)))
        if winner == "Maria":
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
