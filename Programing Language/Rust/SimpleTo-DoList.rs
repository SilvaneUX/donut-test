use std::io;

fn main() {
    let mut todos: Vec<String> = Vec::new();

    loop {
        println!("\n✅ To-Do App");
        println!("1️⃣ Add task");
        println!("2️⃣ Show tasks");
        println!("3️⃣ Exit");

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).unwrap();

        match choice.trim() {
            "1" => {
                println!("Enter task:");
                let mut task = String::new();
                io::stdin().read_line(&mut task).unwrap();
                todos.push(task.trim().to_string());
            }
            "2" => {
                println!("📋 Your Tasks:");
                for (i, task) in todos.iter().enumerate() {
                    println!("{}. {}", i + 1, task);
                }
            }
            "3" => break,
            _ => println!("⚠️ Invalid option."),
        }
    }
}
