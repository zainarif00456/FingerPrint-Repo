import os
import shutil
import random
import requests

if __name__ == '__main__':
    n = random.randint(0, 10000000)
    if not os.path.exists(f"img.jpg"):
        print("Status False....")
        response = requests.post('http://192.168.0.75:5000/check_status', json={
            "status": False
        })
        print(response)
    else:
        print(n)
        print("Status True...")
        shutil.move('img.jpg', f"img/{n}_img.jpg")
        filename = f"{n}_img.jpg"
        filepath = f"img/{filename}"
        files = {
        'file': (filename, open(filepath, 'rb')),
        'Content-Type': 'image/jpeg',
    }
        data = {
        	"status": True
        }
        response = requests.post('http://192.168.0.75:5000', files=files, data=data)
        print(response)
