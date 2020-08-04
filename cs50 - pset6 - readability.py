from cs50 import get_string
import re

def main():

    text = get_string("Text: ")

    L = (count_letters(text) / count_words(text)) * 100

    S = (count_sentences(text) / count_words(text)) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    grade = round(index)


    if grade < 16 and grade >= 0:

        print(f"Grade {grade}")

    elif grade >= 16:

        print("Grade 16+")

    else:

        print("Before Grade 1")


    print(count_letters(text))
    print(count_words(text))
    print(count_sentences(text))
    print(grade)



def count_letters(text):

    letters = len(re.findall('[A-Za-z]', text))

    return letters


def count_words(text):

    words = len(re.findall(' ', text))

    return words + 1


def count_sentences(text):

    sentences = len(re.findall('[.!?]', text))

    return sentences

main()

