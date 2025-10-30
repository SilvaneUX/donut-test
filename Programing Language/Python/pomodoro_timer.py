import time

def pomodoro(minutes=25):
    print(f"🍅 Pomodoro started for {minutes} minutes.")
    time.sleep(minutes * 60)
    print("⏰ Time's up! Take a break.")

if __name__ == "__main__":
    pomodoro(0.1)  # test with 6 seconds
