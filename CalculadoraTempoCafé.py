# ☕ Coffee Break Timer
# Author: Debora Martins (@Debora0Martins)
# Description: Simple countdown timer for coffee breaks during Hacktoberfest.
# Run this code and enjoy your donut while waiting!

import time

def coffee_timer(minutes):
    print(f"Starting {minutes}-minute coffee break 🍩☕")
    for m in range(minutes, 0, -1):
        print(f"{m} minute(s) left...")
        time.sleep(1)
    print("Break over! Back to coding 🚀")

coffee_timer(3)
