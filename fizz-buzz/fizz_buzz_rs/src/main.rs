fn is_multiple_of_3(number: u32) -> bool {
    return number % 3 == 0
}

fn is_multiple_of_5(number: u32) -> bool {
    return number % 5 == 0
}

fn main() {
    println!("This is Fizz Buzz in Rust!");

    let mut counter: u32 = 1;

    loop {
        if counter == 101 {
            break;
        }

        if is_multiple_of_3(counter) && is_multiple_of_5(counter) {
            println!("\t\tFizzBuzz!");
        } else if is_multiple_of_3(counter) {
            println!("\t\tFizz!");
        } else if is_multiple_of_5(counter) {
            println!("\t\tBuzz!");
        } else {
            println!("\t\t{}", counter);
        }

        counter += 1;
    }
}
