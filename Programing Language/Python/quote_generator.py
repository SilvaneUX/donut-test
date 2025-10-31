import random

quotes = [
    "Code is like humor. When you have to explain it, it’s bad.",
    "Talk is cheap. Show me the code.",
    "Experience is the name everyone gives to their mistakes.",
    "In order to be irreplaceable, one must always be different."
]

def random_quote():
    print(random.choice(quotes))

if __name__ == "__main__":
    random_quote()
