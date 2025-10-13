import turtle


def apply_rules(axiom, rules):
    """
    Applies the production rules to the axiom string to generate the next iteration.
    """
    result = ""
    for char in axiom:
        # If the character is a key in our rules, replace it with the rule's value.
        # Otherwise, keep the character as is.
        result += rules.get(char, char)
    return result


def draw_lsystem(t, instructions, angle, distance):
    """
    Interprets the instruction string and uses a turtle to draw the L-system.
    """
    # A stack to save the turtle's state (position and heading)
    state_stack = []

    # We'll update the screen periodically to see the drawing animation
    draw_count = 0

    for command in instructions:
        if command == 'F':
            t.forward(distance)
        elif command == 'B':
            t.backward(distance)
        elif command == '+':
            t.right(angle)
        elif command == '-':
            t.left(angle)
        elif command == '[':
            # Push current state (position, heading) onto the stack
            state_stack.append((t.position(), t.heading()))
        elif command == ']':
            # Pop state from the stack and restore it
            position, heading = state_stack.pop()
            t.penup()
            t.goto(position)
            t.setheading(heading)
            t.pendown()

        # To make the drawing animated, we update the screen every few steps
        draw_count += 1
        if draw_count % 100 == 0:
            turtle.getscreen().update()


def main():
    """Main function to set up and run the L-system generator."""
    # --- 1. SETUP THE TURTLE ENVIRONMENT ---
    screen = turtle.Screen()
    screen.setup(width=800, height=800)
    screen.title("L-System Fractal Plant Generator")
    screen.bgcolor("#1C1C1C")  # A dark background
    screen.tracer(0)  # Turn off automatic screen updates

    # --- 2. DEFINE THE L-SYSTEM ---
    # You can swap between different rule sets to generate different plants!

    # Rule Set 1: A classic fractal plant
    axiom = "X"
    rules = {
        "X": "F-[[X]+X]+F[+FX]-X",
        "F": "FF"
    }
    iterations = 5  # How many times to apply the rules
    angle = 25  # The angle for turns
    distance = 4  # The length of each forward step
    start_pos = (0, -350)
    start_heading = 90
    plant_color = "#2ECC71"  # A nice green

    # --- 3. GENERATE THE INSTRUCTION STRING ---
    current_string = axiom
    print(f"Starting Generation (this might take a moment for high iterations)...")
    print(f"Iteration 0: {current_string}")
    for i in range(iterations):
        current_string = apply_rules(current_string, rules)
        print(f"Iteration {i + 1} length: {len(current_string)}")
    print("Generation complete.")

    # --- 4. DRAW THE L-SYSTEM ---
    t = turtle.Turtle()
    t.hideturtle()
    t.speed(0)
    t.pencolor(plant_color)
    t.pensize(2)

    # Position the turtle at the start
    t.penup()
    t.goto(start_pos)
    t.setheading(start_heading)
    t.pendown()

    # Draw the final result
    draw_lsystem(t, current_string, angle, distance)

    # --- 5. FINISH ---
    screen.update()  # Final update to show the completed drawing
    print("Drawing complete. Click the window to exit.")
    screen.exitonclick()


# --- MAIN EXECUTION BLOCK ---
if __name__ == "__main__":
    main()
