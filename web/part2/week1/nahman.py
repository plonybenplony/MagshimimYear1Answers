import requests

INDEX_OF_PASS_CHAR = 99


def most_frequent(l, count):
    word_count = {}
    for word in l:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1

    frequent = sorted(word_count, key=word_count.get, reverse=True)

    return frequent[:count]


def extract_password_from_site():
    word = ""
    for i in range(11, 34 + 1):
        file = requests.get("http://webisfun.cyber.org.il/nahman/files/file%d.nfo" % (i)).text
        word += file[INDEX_OF_PASS_CHAR]

    return word


def find_most_common_words(path_to_file, words_count):
    sentence = ""
    text = ""
    if path_to_file.startswith("http://") or path_to_file.startswith("https://"):
        text = requests.get(path_to_file).text
    else:
        with open(path_to_file, "r") as f:
            text = f.read()

    words = text.split(" ")

    return " ".join(most_frequent(words, words_count))


def main():
    if input("Enter '1' to get the password, '2' to get the sentence") == '1':
        print(extract_password_from_site())
    else:
        print(find_most_common_words("http://webisfun.cyber.org.il/nahman/final_phase/words.txt", 6))


if __name__ == "__main__":
    main()
