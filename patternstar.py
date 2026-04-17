for i in range(1, 10):
    for j in range(1, 10):
        if abs(5 - i) + abs(5 - j) == 4:
            print("*", end="")
        else:
            print(" ", end="")
    print()