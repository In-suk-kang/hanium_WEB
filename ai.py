import json
import requests
def check_vulnerabilities(filepath):
    with open(filepath, 'rb') as file:
        files = {'file': file}
        url = 'http://43.203.218.174:5000/predict'
        response = requests.post(url, files=files)
        
    json_obj = json.loads(response.text)
    return json_obj