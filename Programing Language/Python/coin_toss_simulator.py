import random

def coin_toss(n=10):
    results = {"Heads": 0, "Tails": 0}
    for _ in range(n):
        toss = random.choice(["Heads", "Tails"])
        results[toss] += 1
    print(f"Results after {n} tosses: {results}")

if __name__ == "__main__":
    coin_toss()
