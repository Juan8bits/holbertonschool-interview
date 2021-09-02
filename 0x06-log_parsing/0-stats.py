#!/usr/bin/python3
""" Script that reads stdin line by line and computes metrics.
Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
"""
import sys


def print_log(allows, file_size):
    """ Function that print the file size in this order
            File size: <total size>
        and then, each  status code in this order
            <status code>: <number>

    Args:
        allows (dic): Dictionary with allows status codes
            to be printed with their values.
        file_size (dic): Dictionary with that containes tha
            value of the size of a file.
    """
    print("File size: {}".format(file_size["file_size"]))
    sort_allows = sorted(allows.keys())
    for k in sort_allows:
        if allows[k] is not 0:
            print("{}: {}".format(k, allows[k]))


i = 0
allows = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}
file_size = {"file_size": 0}
try:
    for line in sys.stdin:
        # ["<IP Address> - [<date>]",
        # "GET /projects/260 HTTP/1.1",
        # "<status code> <file size>"]
        first_form = line.split('"')
        if len(first_form) == 3:
            # ["<IP Address> - ", "[<date>]"]
            second_form = first_form[0].split("[")
            if len(second_form) == 2:
                # ["<status code>", "<file size>"]
                sizes = first_form[2].split()
                if len(sizes) == 2:
                    file_size["file_size"] += int(sizes[1])
                    if sizes[0] in allows.keys():
                        allows[sizes[0]] += 1
                        if i is 9:
                            i = -1
                            print_log(allows, file_size)
        i += 1
except ValueError:
    pass
finally:
    print_log(allows, file_size)
