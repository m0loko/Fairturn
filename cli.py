import shutil
import os

def center_text(text, width=None):
    if width is None:
        width = shutil.get_terminal_size().columns
    return text.center(width)

def clear_console():
    os.system('cls' if os.name == 'nt' else 'clear')

def show_menu(title="FAIRTURN", options=None):

    clear_console()
    width = shutil.get_terminal_size().columns

    # Верхняя рамка
    print("═" * width)

    # Заголовок
    print(center_text(title, width))
    print("─" * width)

    # Опции меню
    for option in options:
        print(center_text(option, width))

    # Нижняя рамка
    print("═" * width)
    print()