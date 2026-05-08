import os
import html
import requests
from bs4 import BeautifulSoup

HANDLE = "mishika777"

SAVE_DIR = "solutions"
os.makedirs(SAVE_DIR, exist_ok=True)

api = f"https://codeforces.com/api/user.status?handle={HANDLE}"

resp = requests.get(api).json()

if resp["status"] != "OK":
    raise Exception("API Error")

subs = resp["result"]

for sub in subs:

    if sub.get("verdict") != "OK":
        continue

    problem = sub["problem"]

    contest = problem.get("contestId")
    index = problem.get("index")

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

    url = f"https://codeforces.com/contest/{contest}/submission/{subid}"

    page = requests.get(url)

    soup = BeautifulSoup(page.text, "html.parser")

    codebox = soup.find("pre", id="program-source-text")

    if not codebox:
        continue

    code = html.unescape(codebox.text)

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(code)
