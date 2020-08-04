# mario less


from cs50 import get_int

def main():

    height = get_height()

    x = 1

    for i in range(height):

        print(" " * (height - x), end="")

        print("#" * x, end="")

        x += 1

        print()


def get_height():

    while True:

        h = get_int("Enter the height of the pyramid: ")

        if h > 0 and h < 9:

            break

    return h

main()


# mario more


from cs50 import get_int

def main():

    height = get_height()

    x = 1

    for i in range(height):

        print(" " * (height - x), end="")

        print("#" * x, end="")

        print("  ", end="")

        print("#" * x, end="")

        x += 1

        print()


def get_height():

    while True:

        h = get_int("Enter the height of the pyramid: ")

        if h > 0 and h < 9:

            break

    return h

main()







