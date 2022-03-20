#!/usr/bin/python3
""" Interview Preparation.
    The N queens puzzle is the challenge of placing N
    non-attacking queens on an N×N chessboard. Write a
    program that solves the N queens problem.
"""
import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
N = sys.argv[1]
if not N.isdigit():
    print("N must be a number")
    exit(1)
N = int(N)
if N < 4:
    print("N must be at least 4")
    exit(1)

queens = [[i] for i in range(N)]
for i in range(1, N):
    new_queens = []
    for x in queens:
        idx = [j for j in range(N) if j not in x]
        for k in range(len(x)):
            a, b = x[k] - i + k, x[k] + i - k
            if a in idx:
                idx.remove(a)
            if b in idx:
                idx.remove(b)
            if idx == []:
                break
        new_queens.extend([x + [j] for j in idx])
    queens = new_queens
for s in range(len(queens)):
    for i in range(N):
        queens[s][i] = [i, queens[s][i]]
print(queens)
