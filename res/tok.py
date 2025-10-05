import os
import pickle
from google.auth.transport.requests import Request
from google_auth_oauthlib.flow import InstalledAppFlow

SCOPES = ['https://www.googleapis.com/auth/spreadsheets']

def get_google_token():
    creds = None

    # Загружаем токен если есть
    if os.path.exists('token.pickle'):
        with open('token.pickle', 'rb') as token:
            creds = pickle.load(token)

    # Если токена нет или он невалидный
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            print("🔄 Токен устарел, обновляю...")
            creds.refresh(Request())
        else:
            print("⚠️ Нужна новая авторизация в браузере...")
            flow = InstalledAppFlow.from_client_secrets_file(
                'credentials.json', SCOPES
            )
            creds = flow.run_local_server(
                port=8080,
                access_type='offline',
                prompt='consent'
            )

        # Сохраняем обновлённый токен
        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)

    return creds

if __name__ == '__main__':
    creds = get_google_token()
    print("✅ Токен готов, можно пользоваться API.")
