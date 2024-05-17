import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`) 
    
    println("Hello, whats your name?")
    var name = scanner.nextLine()

    println("Hello " + name)
}