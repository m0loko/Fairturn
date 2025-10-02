import os
import csv
from googleapiclient.discovery import build
from auth_utils import get_credentials  # ✅ подключаем функцию

# Скачивание данных из Google Sheets в CSV
def download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path):
    try:
        # Получаем всегда валидный токен
        credentials = get_credentials(token_path=credentials_path, creds_path="credentials.json")

        # Создаем API клиент
        service = build('sheets', 'v4', credentials=credentials)

        # Чтение данных
        range_name = f"{worksheet_name}!A2:Z"
        result = service.spreadsheets().values().get(
            spreadsheetId=spreadsheet_id,
            range=range_name
        ).execute()
        values = result.get('values', [])

        if not values:
            print("Таблица пуста или данных нет.")
            return

        # Сохраняем в CSV
        with open(csv_file_path, 'w', newline='', encoding='cp1251') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(values)

        print(f"✅ Данные сохранены в {csv_file_path}")
    except Exception as e:
        print(f"Ошибка при скачивании: {e}")


if __name__ == "__main__":
    print("Введите данные для скачивания из Google Sheets:")
    spreadsheet_id = input("Spreadsheet ID: ").strip()
    with open("id.csv", 'w', newline='', encoding='cp1251') as csvfile:
        csvfile.write(spreadsheet_id)

    worksheet_name = input("Worksheet name: ").strip()

    csv_file_path = input("Путь для сохранения CSV (по умолчанию 'output.csv', введите 'd' для default): ").strip()
    with open("pathfile.csv", 'w', newline='', encoding='cp1251') as csvfile:
        csvfile.write('d')
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    credentials_path = input("Путь к токену (по умолчанию 'token.pickle', введите 'd' для default): ").strip()
    with open("pathtoken.csv", 'w', newline='', encoding='cp1251') as csvfile:
        csvfile.write('d')
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path)
