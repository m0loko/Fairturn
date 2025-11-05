from human import Human
from cli import clear_console
import random

def manualIn():
    inputedHumans = []
    try:
        humanCount = int(input("Enter the number of humans: "))
    except Exception as ex:
        raise Exception(f"Error in manualIn(). Human count is not a number!({ex})")

    try:
        currentLab = int(input("Enter current lab number: "))
    except Exception as ex:
        raise Exception(f"Error in manualIn(). Current lab number is not a number!({ex})")

    print("Enter data according to the template <surname> <prevLabs> <submittingLabs> <attended (Да/Нет)>")
    i = 1
    while(i < humanCount + 1):
        humanStr = input(f"{i}. ")
        strDict = humanStr.split()

        if (len(strDict) != 4 or strDict[0] == '' or strDict[1] == '' or strDict[2] == '' or strDict[3] == ''
                or (strDict[3].lower() != 'да' and strDict[3].lower() != 'нет')):
            print("Not valid data. Try again.")
            continue

        try:
            surname = strDict[0]
            prevLabs = int(strDict[1])
            submittingLabs = int(strDict[2])
            attended = strDict[3]
        except:
            print("Not valid data. Try again.")
            continue

        newHuman = Human(surname, prevLabs, submittingLabs, attended, currentLab)
        inputedHumans.append(newHuman)
        i += 1

    try:
        for human in inputedHumans:
            human._sort_rand = random.random()  ## Pseudorandom number in range(0.0, 1.0) for random sort humans with equals total score
            human.getScore()

        inputedHumans.sort(key=lambda human: (human.total, human._sort_rand))

        for human in inputedHumans:  ## Deleting pseudorandom number
            del human._sort_rand
    except Exception as ex:
        raise Exception(f"Error in manualIn() Sorting part. ({ex})")

    clear_console()
    print("Surname Prev Submitting Attended Current Score")
    for index, human in enumerate(inputedHumans, start=1):
        print(f"{index}. {human.getHumanStr()}")

if __name__ == "__main__":
    manualIn()