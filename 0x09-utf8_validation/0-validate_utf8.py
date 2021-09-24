#!/usr/bin/python3
""" Functions:
        validUTF8(data).
"""


def validUTF8(data):
    """ Function that determines if a data set represents a valid UTF-8
        encoding.
        1. A character in UTF-8 can be 1 to 4 bytes long.
        2. The data set can contain multiple characters.
    Args:
        data(): List of integers.
            Each integer represents 1 byte of data, therefore you only
            need to handle the 8 least significant bits of each integer.
    Returns:
        - True if data is a valid UTF-8 encoding, False if not.
    """
    b = 0

    for i, n in enumerate(data):
        byte = n & 0xFF
        if b:
            if byte >> 6 != 2:
                return False
            b -= 1
            continue

        while (1 << abs(7 - b)) & byte:
            b += 1

        if b == 1 or b > 4:
            return False
        b = max(b - 1, 0)

    return b == 0
