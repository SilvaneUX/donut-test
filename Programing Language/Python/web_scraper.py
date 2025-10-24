import requests
from bs4 import BeautifulSoup

# Ask user for the URL
url = input("Enter the URL to scrape: ")

try:
    # Send GET request
    response = requests.get(url)
    response.raise_for_status()  # Raise error for bad status

    # Parse the HTML content
    soup = BeautifulSoup(response.text, 'html.parser')

    # Example 1: Extract all headings (h1, h2, h3)
    print("\n=== Headings on the page ===")
    for heading in soup.find_all(['h1', 'h2', 'h3']):
        print(heading.text.strip())

    # Example 2: Extract all links
    print("\n=== Links on the page ===")
    for link in soup.find_all('a', href=True):
        print(link['href'])

except requests.exceptions.RequestException as e:
    print("Error fetching the page:", e)
