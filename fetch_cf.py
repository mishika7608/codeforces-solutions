import os
import html
import requests
from bs4 import BeautifulSoup

HANDLE = "mishika777"

SAVE_DIR = "solutions"
os.makedirs(SAVE_DIR, exist_ok=True)

api = f"https://codeforces.com/api/user.status?handle={HANDLE}"

resp = requests.get(api).json()

print(resp["status"])

if resp["status"] != "OK":
    raise Exception("Codeforces API failed")

subs = resp["result"]

saved = 0

headers = {
    "User-Agent": "Mozilla/5.0"
}

for sub in subs:

    if sub.get("verdict") != "OK":
        continue

    problem = sub["problem"]

    contest = problem.get("contestId")
    index = problem.get("index")

    if not contest:
        continue

    lang = sub.get("programmingLanguage", "")

    ext = None

    if "C++" in lang:
        ext = "cpp"
    elif "Python" in lang:
        ext = "py"
    elif "Java" in lang:
        ext = "java"

    if ext is None:
        continue

    filename = f"{contest}_{index}.{ext}"
    filepath = os.path.join(SAVE_DIR, filename)

    if os.path.exists(filepath):
        continue

    subid = sub["id"]

    print("Fetching:", subid)

    url = f"https://codeforces.com/problemset/submission/{contest}/{subid}"

    page = requests.get(url, headers=headers)

    soup = BeautifulSoup(page.text, "html.parser")

    codebox = soup.find("pre")

    if not codebox:
        print("Code not found")
        continue

    code = html.unescape(codebox.text)

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(code)

    print("Saved:", filename)

    saved += 1

print("Total saved:", saved)
