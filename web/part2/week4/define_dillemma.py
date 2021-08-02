value1 = "something you think is right and important"

def is_dillemma(behavior):
    answer_hurt = input("Are there any values hurt if you choose the behavior: '{}' ?\n yes\\no\n*value = {}\n".format(behavior, value1))
    answer_promote = input("Do you stand for a value by choosing the behavior: '{}' ?\n  yes\\no\n".format(behavior))

    return answer_hurt.lower() ==  answer_promote.lower() == 'yes'


def insert_values(behavior):
    another_hurt = ""
    value_hurt = input("What value is hurt by {}?\n".format(behavior))
    hurt_list = [value_hurt]
    while not("that's it" in another_hurt.lower()):
        another_hurt = input("Is there another one? If not, type 'That's it'\n")
        hurt_list.append(another_hurt)
    del hurt_list[-1]


    another_promote = ""
    value_promote = input("What value does the behavior " + behavior + " stand for?\n")
    promote_list = [value_promote]
    while not ("that's it" in another_promote.lower()):
        another_promote = input("Is there another one? If not, type 'That's it'\n")
        promote_list.append(another_promote)
    del promote_list[-1]
    return hurt_list, promote_list

def organize_dillemma(hurt_values, promoted_values, behavior):
    print ("\nThe dillemma between " + behavior + " or not is a decision between the value(s):\n", '\n'.join(hurt_values), "\nand the value(s):\n", '\n'.join(promoted_values))
    print ("\nGood Luck!")


def main():
    behavior = input("What is the behavior that is possibly a moral dilemma?\n")
    if not (is_dillemma(behavior)):
        print ("That is not a moral dilemma")
        return
    hurt_values, promoted_values = insert_values(behavior)
    organize_dillemma(hurt_values, promoted_values, behavior)


main()