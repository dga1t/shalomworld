from cs50 import get_float

def main():

    while True:

        change = get_float("How much change is owed?: ")

        if change > 0:

            break

    change = round(change * 100)

    coins = 0

    while change > 0:

        if change >= 25:
            change -= 25
            coins += 1

        elif change >= 10:
            change -= 10
            coins += 1

        elif change >= 5:
            change -= 5
            coins += 1

        elif change >= 1:
            change -= 1
            coins += 1

    print(coins)

main()