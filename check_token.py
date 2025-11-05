from auth_utils import get_credentials

def check_token():
    creds = get_credentials("token.pickle", "credentials.json")
    if creds and creds.valid:
        print("✅ Valid token")
    else:
        print("❌ Invalid token")
