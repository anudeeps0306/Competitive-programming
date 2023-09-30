import requests
from bs4 import BeautifulSoup

url = 'https://www.linkedin.com/jobs/'
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

ul_element = soup.find(class_='jobs-search__results-list')

if ul_element:
    li_items = ul_element.find_all('li')

    for li in li_items:
        # Extract the ID from each li item
        job_id = li['data-job-id']
        print(job_id)
else:
    print("No results found.")
