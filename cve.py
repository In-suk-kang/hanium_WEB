import requests
from bs4 import BeautifulSoup

def get_cve(ai):
    vul_dict = {
        1:"stack+overflow",
        2:"heap+overflow"
    }
    url = f"https://cve.mitre.org/cgi-bin/cvekey.cgi?keyword={vul_dict[ai]}"
    response = requests.get(url)

    if response.status_code != 200:
        print("Failed to retrieve data")
        return []

    soup = BeautifulSoup(response.text, 'html.parser')

    table = soup.find('table', {'cellpadding': '0', 'cellspacing': '0', 'border': '0'})
    cve_details = []
    
    for row in table.find_all('tr'):
        cve_td = row.find('td', {'nowrap': 'nowrap'})
        if cve_td:
            a_tag = cve_td.find('a')
            if a_tag:
                cve_id = a_tag.text
                cve_url = "https://cve.mitre.org" + a_tag['href']
                
                # Get the next <td> for the description
                description_td = cve_td.find_next_sibling('td')
                description = description_td.text.strip() if description_td else "No description available"
                
                cve_details.append({
                    "cve_id": cve_id,
                    "cve_url": cve_url,
                    "description": description
                })
            if len(cve_details) == 3: 
                break

    return cve_details