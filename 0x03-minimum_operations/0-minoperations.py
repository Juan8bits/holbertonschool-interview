#!/usr/bin/python3
""" Functions:
        minOperations(n).
"""

def minOperations(n):
    """ Fucntion that Given a number n, write a method
        that calculates the fewest number of operations
        needed to result in exactly n H characters in the file.

    Args:
        n (int): Given number to calculate the fewest.
    """
    if not isinstance(n, int) or n <= 1:
        return 0
    minimum = 0
    operations = 2
    while operations <= n:
        if n % operations == 0:
            minimum += operations
            n /= operations
            operations -= 1
        operations += 1
    return minimum
