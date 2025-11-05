import csv
import random
from human import Human


def processCsv(currentLab):
    try:
        with open("pathfile.csv", 'r', newline='', encoding='cp1251') as csvfile:
            csv_file_path = csvfile.read().strip()
        if csv_file_path.lower() == 'd' or not csv_file_path:
            csv_file_path = 'output.csv'

        with open(csv_file_path, 'r', encoding='cp1251') as inputFile:
            reader = csv.reader(inputFile)
            rows = list(reader)

        processedHumans = []
        for row in rows:
            processedHumans.append(Human(row[0], row[1], row[2], row[3], currentLab))

        for human in processedHumans:
            human._sort_rand = random.random() ## Pseudorandom number in range(0.0, 1.0) for random sort humans with equals total score
            human.getScore()

        processedHumans.sort(key=lambda human: (human.total, human._sort_rand))

        for human in processedHumans: ## Deleting pseudorandom number
            del human._sort_rand

        with open(csv_file_path, 'w', newline='', encoding='cp1251') as outputFile:
            csvFileWriter = csv.writer(outputFile)
            csvFileWriter.writerow(["Surname", "Prev", "Submitting", "Attended", "Current", "Score"])
            for human in processedHumans:
                csvFileWriter.writerow(human.getHumanCSVRow())



    except Exception as ex:
        raise Exception(f"\033[31mError: {ex}\033[0m")

if __name__ == "__main__":
    processCsv(1)