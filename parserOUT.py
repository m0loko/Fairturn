import os
import csv
from googleapiclient.discovery import build
from auth_utils import get_credentials  # ✅ подключаем функцию

# Загрузка данных из CSV в Google Sheets
def upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path):
    try:
        # Получаем всегда валидный токен
        credentials = get_credentials(token_path=credentials_path, creds_path="credentials.json")

        # Создаем API клиент
        service = build('sheets', 'v4', credentials=credentials)

        if not os.path.exists(csv_file_path):
            raise FileNotFoundError(f"CSV файл {csv_file_path} не найден.")

        # Читаем CSV
        with open(csv_file_path, 'r', encoding='cp1251') as csvfile:
            reader = csv.reader(csvfile)
            values = list(reader)

        # Пишем в Google Sheets
        body = {'values': values}
        service.spreadsheets().values().update(
            spreadsheetId=spreadsheet_id,
            range=worksheet_name,
            valueInputOption="RAW",
            body=body
        ).execute()

        print(f"✅ Data from {csv_file_path} uploaded into {spreadsheet_id}:{worksheet_name}")
    except Exception as e:
        raise Exception(f"\033[31mUpload error: {e}\033[0m")


def parserOut():
    print("Enter data for upload to Google Sheets:")

    with open("id.csv", 'r', newline='', encoding='cp1251') as csvfile:
        spreadsheet_id = csvfile.read().strip()

    worksheet_name = input("Worksheet name (example 'Sheet1'): ").strip()

    with open("pathfile.csv", 'r', newline='', encoding='cp1251') as csvfile:
        csv_file_path = csvfile.read().strip()
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    with open("pathtoken.csv", 'r', newline='', encoding='cp1251') as csvfile:
        credentials_path = csvfile.read().strip()
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path)
