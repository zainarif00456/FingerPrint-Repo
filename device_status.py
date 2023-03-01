import requests

if __name__ == '__main__':
    response = requests.post('http://192.168.0.75:5000/device_status', json={
        "status": "connected"
    })
    #print(response)

