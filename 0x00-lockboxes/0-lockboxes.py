#!/usr/bin/python3
""" Interview Preparation.
    Given n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes.

    Write a method that determines if all the boxes can be opened.

    * boxes is a list of lists.
    * A key with the same number as a box opens that box.
    * You can assume all keys will be positive integers.
    * There can be keys that do not have boxes.
    * The first box boxes[0] is unlocked.
    * Return True if all boxes can be opened, else return False.
"""


def canUnlockAll(boxes):
    """ Main function that received a list of lists
        and determine if all boxes can be unlocked.

        Parameters:
            boxes: List of lists.
        Return: True/False
    """
    unlocks = [False] * len(boxes)
    unlocks[0] = True
    unlocks = unlocker(boxes, unlocks)
    return all(unlocks)


def unlocker(boxes, unlocks):
    """ Aux function that computes/solved the relation
        between the boxes and the keys inside itself.

        Parameters:
            boxes: list of lists.
            unlocks: list of boolean values.(Index 0 True else False)
        Return: List of boolean values according to the unlocked boxes index.
    """
    boxes_size = len(boxes)
    index = 0
    for box in boxes:
        if unlocks[index] is True:
            for key in box:
                if key < index and unlocks[key] is False:
                    unlocks[key] = True
                    return unlocker(boxes, unlocks)
                if key < boxes_size:
                    unlocks[key] = True
        index += 1
    return unlocks
