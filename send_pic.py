import shutil
import random
import requests

if __name__ == '__main__':
    n = random.randint(0, 10000000)
    print(n)
    shutil.move('img.jpg', f"img/{n}_img.jpg")
    filename = f"{n}_img.jpg"
    filepath = f"img/{filename}"
    files = {
    'file': (filename, open(filepath, 'rb')),
    'Content-Type': 'image/jpeg'
}
    response = requests.post('http://192.168.0.75:5000', files=files)

