import random

def guess_number():
    number = random.randint(1, 100)
    attempts = 0
    print("Guess a number between 1 and 100!")

    while True:
        guess = int(input("Your guess: "))
        attempts += 1
        if guess < number:
            print("Too low!")
        elif guess > number:
            print("Too high!")
        else:
            print(f"🎉 Correct! You guessed it in {attempts} tries.")
            break

if __name__ == "__main__":
    guess_number()
