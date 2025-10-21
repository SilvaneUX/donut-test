def add_expense():
    desc = input("Enter expense description: ")
    amount = float(input("Enter amount: "))
    with open("expenses.txt", "a") as f:
        f.write(f"{desc} - {amount}\n")
    print("✅ Expense added!")

def show_expenses():
    total = 0
    print("\n💰 Your Expenses:")
    with open("expenses.txt", "r") as f:
        for line in f:
            print(line.strip())
            total += float(line.split("-")[1])
    print(f"Total Spent: ₹{total}")

def main():
    while True:
        print("\n1️⃣ Add Expense\n2️⃣ View Expenses\n3️⃣ Exit")
        choice = input("Choose: ")
        if choice == "1":
            add_expense()
        elif choice == "2":
            show_expenses()
        elif choice == "3":
            break
        else:
            print("⚠️ Invalid choice!")

main()
