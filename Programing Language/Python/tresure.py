"""
Treasure Hunt - a simple terminal-based Python game
How to play:
- Run: python treasure_hunt.py
- Move using commands: n (north), s (south), e (east), w (west), q (quit)
- Objective: Collect 3 treasures and return to the starting point (home) to win.
- Encounters: Monsters, traps, healing fountains, and random events.
This script is self-contained and uses only the Python standard library.
"""

import random
import time
import os
import sys

WIDTH = 5
HEIGHT = 5
TREASURES_TO_WIN = 3

def clear():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

class Player:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.hp = 10
        self.max_hp = 10
        self.treasures = 0
        self.gold = 0

    def is_alive(self):
        return self.hp > 0

class Cell:
    def __init__(self):
        self.type = 'empty'
        self.visited = False

class World:
    def __init__(self, width, height, seed=None):
        if seed is not None:
            random.seed(seed)
        self.width = width
        self.height = height
        self.grid = [[Cell() for _ in range(width)] for _ in range(height)]
        self.populate()

    def populate(self):
        spots = [(x, y) for x in range(self.width) for y in range(self.height) if not (x == 0 and y == 0)]
        random.shuffle(spots)

        for _ in range(5):
            if not spots: break
            x, y = spots.pop()
            self.grid[y][x].type = 'treasure'

        for _ in range(6):
            if not spots: break
            x, y = spots.pop()
            self.grid[y][x].type = 'monster'

        for _ in range(5):
            if not spots: break
            x, y = spots.pop()
            self.grid[y][x].type = 'trap'

        for _ in range(3):
            if not spots: break
            x, y = spots.pop()
            self.grid[y][x].type = 'fountain'

    def in_bounds(self, x, y):
        return 0 <= x < self.width and 0 <= y < self.height

    def cell(self, x, y):
        return self.grid[y][x]

def print_status(player):
    print(f"HP: {player.hp}/{player.max_hp}   Treasures: {player.treasures}   Gold: {player.gold}")

def print_map(world, player):
    print("Map (P = you, H = home) - visited cells shown:")
    for y in range(world.height):
        row = []
        for x in range(world.width):
            if x == player.x and y == player.y:
                row.append('P')
            elif x == 0 and y == 0:
                row.append('H')
            else:
                cell = world.cell(x, y)
                row.append('.' if cell.visited else '?')
        print(' '.join(row))
    print("")

def encounter_monster(player):
    monster_hp = random.randint(3, 7)
    monster_atk = random.randint(1, 3)
    print(f"A monster appears! (HP {monster_hp})")
    while monster_hp > 0 and player.is_alive():
        dmg = random.randint(1, 4)
        monster_hp -= dmg
        print(f"You strike the monster for {dmg} damage. (Monster HP={max(0, monster_hp)})")
        time.sleep(0.2)
        if monster_hp <= 0:
            loot = random.randint(1, 5)
            player.gold += loot
            print(f"Monster defeated! You loot {loot} gold.")
            break
        md = random.randint(0, monster_atk)
        player.hp -= md
        print(f"The monster hits you for {md} damage. (Your HP={max(0, player.hp)})")
        time.sleep(0.2)
        if not player.is_alive():
            print("You were slain by the monster...")
            break
        if random.random() < 0.08:
            print("The monster flees unexpectedly. You catch your breath.")
            break

def encounter_trap(player):
    dmg = random.randint(1, 4)
    player.hp -= dmg
    print(f"You triggered a trap and took {dmg} damage! (HP now {player.hp})")
    if not player.is_alive():
        print("The trap was lethal...")

def encounter_fountain(player):
    heal = random.randint(1, 4)
    old = player.hp
    player.hp = min(player.max_hp, player.hp + heal)
    print(f"You find a healing fountain. Restored {player.hp - old} HP. (HP now {player.hp})")

def encounter_treasure(player):
    found = 1
    player.treasures += found
    gold = random.randint(2, 8)
    player.gold += gold
    print(f"You found a treasure chest! Treasures +{found}, Gold +{gold}.")

def random_event(player):
    r = random.random()
    if r < 0.05:
        price = random.randint(3, 7)
        print(f"A wandering merchant offers a healing potion for {price} gold. Buy? (y/n)")
        choice = input("> ").strip().lower()
        if choice == 'y' and player.gold >= price:
            heal = random.randint(3, 6)
            player.gold -= price
            player.hp = min(player.max_hp, player.hp + heal)
            print(f"You use the potion and recover {heal} HP. (HP now {player.hp})")
        else:
            print("You decline the offer.")
    elif r < 0.12:
        print("You hear distant howls. The air feels tense... nothing happens.")

def game_loop(seed=None):
    world = World(WIDTH, HEIGHT, seed=seed)
    player = Player()
    clear()
    print("WELCOME TO TREASURE HUNT!")
    print("Objective: Collect 3 treasures and return to Home (H at 0,0).")
    print("Commands: n (north), s (south), e (east), w (west), m (map), q (quit), status (show status)")
    print("Press Enter to begin...")
    input()
    while True:
        clear()
        print_status(player)
        print_map(world, player)
        if not player.is_alive():
            print("\nGAME OVER. You died. Better luck next time!")
            break
        if player.treasures >= TREASURES_TO_WIN and player.x == 0 and player.y == 0:
            print("\nCONGRATULATIONS! You collected enough treasures and returned home safely. You win!")
            print(f"Final Gold: {player.gold}")
            break
        print("Where do you want to go? (n/s/e/w/m/status/q)")
        cmd = input("> ").strip().lower()
        if cmd == 'q':
            print("Quitting... thanks for playing!")
            break
        if cmd == 'm' or cmd == 'map':
            clear()
            print_map(world, player)
            input("Press Enter to continue...")
            continue
        if cmd == 'status':
            clear()
            print_status(player)
            input("Press Enter to continue...")
