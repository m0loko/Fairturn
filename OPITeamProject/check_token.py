from auth_utils import get_credentials

if __name__ == "__main__":
    creds = get_credentials("token.pickle", "credentials.json")
    if creds and creds.valid:
        print("✅ Токен рабочий")
    else:
        print("❌ Токен невалидный")
