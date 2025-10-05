import os
import pickle
from google.auth.transport.requests import Request
from google_auth_oauthlib.flow import InstalledAppFlow

SCOPES = ['https://www.googleapis.com/auth/spreadsheets']

def get_credentials(token_path="token.pickle", creds_path="credentials.json"):
    creds = None

    # Загружаем сохранённый токен, если есть
    if os.path.exists(token_path):
        with open(token_path, "rb") as token:
            creds = pickle.load(token)

    # Если токена нет или он невалидный
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())  # 🔄 обновляем access_token
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                creds_path, SCOPES
            )
            creds = flow.run_local_server(
                port=8080,
                access_type="offline",
                prompt="consent"
            )

        # Сохраняем новый токен
        with open(token_path, "wb") as token:
            pickle.dump(creds, token)

    return creds
