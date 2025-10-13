import turtle
import math


# --- SIMULATION CLASS FOR A CELESTIAL BODY ---
class Body(turtle.Turtle):
    """
    Represents a celestial body (like a planet or a star) for the simulation.
    Inherits from turtle.Turtle to draw itself on the screen.
    """

    def __init__(self, name, mass, position, velocity, color, size):
        super().__init__(shape="circle")
        self.name = name
        self.mass = mass
        self.position = list(position)  # [x, y]
        self.velocity = list(velocity)  # [vx, vy]

        # Turtle graphics setup
        self.penup()
        self.color(color)
        self.shapesize(stretch_wid=size, stretch_len=size)
        self.goto(position[0], position[1])

    def calculate_gravity(self, other_body, G, TIMESTEP):
        """
        Calculates the gravitational force exerted by another body
        and updates this body's velocity accordingly.
        """
        # Calculate distance vector and magnitude
        dx = other_body.position[0] - self.position[0]
        dy = other_body.position[1] - self.position[1]
        distance_sq = dx ** 2 + dy ** 2

        # Avoid division by zero if bodies are at the same spot
        if distance_sq == 0:
            return

        distance = math.sqrt(distance_sq)

        # Calculate force magnitude (Newton's Law of Universal Gravitation)
        force_magnitude = G * self.mass * other_body.mass / distance_sq

        # Calculate force components (vector)
        force_x = force_magnitude * dx / distance
        force_y = force_magnitude * dy / distance

        # Calculate acceleration (a = F/m)
        acceleration_x = force_x / self.mass
        acceleration_y = force_y / self.mass

        # Update velocity (v = u + at)
        self.velocity[0] += acceleration_x * TIMESTEP
        self.velocity[1] += acceleration_y * TIMESTEP

    def update_position(self, TIMESTEP):
        """
        Updates the body's position based on its current velocity.
        """
        # Update position (s = ut)
        self.position[0] += self.velocity[0] * TIMESTEP
        self.position[1] += self.velocity[1] * TIMESTEP

        # Move the turtle to the new position
        self.goto(self.position[0], self.position[1])


def simulate_orbit():
    """Main function to set up and run the simulation."""
    # --- 1. SETUP & CONSTANTS ---
    screen = turtle.Screen()
    screen.setup(width=800, height=800)
    screen.title("Planetary Orbit Simulation")
    screen.bgcolor("black")
    # Turn off tracer for manual screen updates, which creates a smooth animation
    screen.tracer(0)

    # Simulation constants (scaled for visualization)
    GRAVITATIONAL_CONSTANT = 30  # Increased for a stronger effect at this scale
    TIMESTEP = 0.01  # Simulation time per frame

    # --- 2. CREATE CELESTIAL BODIES ---
    # Sun (stationary at the center)
    sun = Body(
        name="Sun",
        mass=10000,
        position=(0, 0),
        velocity=(0, 0),
        color="yellow",
        size=2.0
    )

    # Earth
    earth = Body(
        name="Earth",
        mass=50,
        position=(200, 0),  # Start 200 pixels to the right
        # CORRECTED: Velocity reduced for a stable elliptical orbit.
        # The previous value of 150 was too high, causing it to escape.
        velocity=(0, 40),
        color="#3498db",  # A nice blue
        size=0.8
    )
    # Enable drawing a trail
    earth.pendown()

    # Mars (a second planet for a more dynamic simulation)
    mars = Body(
        name="Mars",
        mass=25,  # Lighter than Earth
        position=(-280, 0),  # Starts further away on the left
        velocity=(0, -35),  # Slower orbital velocity, moving clockwise
        color="#e74c3c",  # Red color
        size=0.6
    )
    mars.pendown()

    # --- 3. ADD EXPLANATORY TEXT ---
    pen = turtle.Turtle()
    pen.hideturtle()
    pen.penup()
    pen.color("white")
    pen.goto(0, 350)
    pen.write("Planetary Orbit Simulation (Newton's Law of Gravitation)", align="center", font=("Arial", 16, "bold"))

    # --- 4. SIMULATION LOOP ---
    # Create a list of all planets to be simulated
    planets = [earth, mars]

    while True:
        # Loop through each planet in our list
        for planet in planets:
            # Calculate gravity's effect on the planet from the Sun
            planet.calculate_gravity(sun, GRAVITATIONAL_CONSTANT, TIMESTEP)

            # Update the planet's position based on its new velocity
            planet.update_position(TIMESTEP)

        # Refresh the screen to show all the new positions
        screen.update()


# --- MAIN EXECUTION BLOCK ---
if __name__ == "__main__":
    try:
        simulate_orbit()
    except turtle.Terminator:
        print("Simulation window closed.")

