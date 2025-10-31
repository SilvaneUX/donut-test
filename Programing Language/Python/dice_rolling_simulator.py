import random

def roll_dice():
    while True:
        input("Press Enter to roll the dice...")
        print(f"🎲 You rolled: {random.randint(1, 6)}")
        again = input("Roll again? (y/n): ")
        if again.lower() != 'y':
            break

if __name__ == "__main__":
    roll_dice()
