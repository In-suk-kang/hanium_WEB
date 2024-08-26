import json
import requests
def check_vulnerabilities(filepath):
    with open(filepath, 'rb') as file:
        files = {'file': file}
        url = 'http://52.79.179.141:5000/predict' #AWS 동적 URL로 확인 필요
        response = requests.post(url, files=files)
        
    json_obj = json.loads(response.text)
    return json_obj