from time import sleep

from ranging import processCsv
from parserIN import parserIn
from parserOUT import parserOut
from manualIn import manualIn
from check_token import check_token
from cli import *


if __name__ == "__main__":
    try:
        while True:
            show_menu(
                title="FAIRTURN",
                options=[
                    "1. Process table from Google Sheets",
                    "2. Manual input",
                    "3. Check token",
                    "0. Exit"
                ]
            )

            choice = input(center_text("Your choice: ")).strip()

            match choice:
                case "1":
                    try:
                        clear_console()
                        parserIn()
                        sleep(1)
                        clear_console()
                        try:
                            currentLab = int(input("Enter current lab number: "))
                        except Exception as ex:
                            print("Invalid number!")
                            sleep(2)
                            continue

                        processCsv(currentLab)
                        clear_console()
                        parserOut()
                        sleep(2)
                    except Exception as ex:
                        print(f"\033[31mError: {ex}\033[0m")
                        sleep(5)

                case "2":
                    try:
                        clear_console()
                        manualIn()
                        print("\nDouble press enter to continue")
                        input()
                        input()
                    except Exception as ex:
                        print(f"\033[31mError: {ex}\033[0m")
                        sleep(5)

                case "3":
                    try:
                        clear_console()
                        check_token()
                        sleep(2)
                    except Exception as ex:
                        print(f"\033[31mError: {ex}\033[0m")
                        sleep(5)

                case "0":
                    clear_console()
                    print(center_text("Developed by artaka & m0loko"))
                    exit(0)

                case _:
                    clear_console()
                    print("\033[31mInvalid choice!\033[0m")
                    sleep(2)
    except KeyboardInterrupt:
        clear_console()
        print(center_text("Developed by artaka & m0loko"))
        exit(0)