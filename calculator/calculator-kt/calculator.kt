import java.util.ArrayList

enum class TokenType {
    NONE,
    DIGIT,
    PLUS,
    MULT,
    MINUS,
    DIV,
}

data class Token(val char: Char, val type: TokenType)

fun parseInput(input: String): ArrayList<Token> {
    val tokens = ArrayList<Token>()

    for (char in input) {
        when {
            char.isDigit() -> tokens.add(Token(char, TokenType.DIGIT))
            char == '+'    -> tokens.add(Token(char, TokenType.PLUS))
            char == '-'    -> tokens.add(Token(char, TokenType.MINUS))
            char == 'x'    -> tokens.add(Token(char, TokenType.MULT))
            char == '/'    -> tokens.add(Token(char, TokenType.DIV))
            char != ' '    -> throw IllegalArgumentException("Invalid character: $char")
        }
    }

    return tokens
}

fun calculate_tokens(tokens: ArrayList<Token>): Int {
    // works with basic calculations, can be done much better

    var result = 0
    var current_operation = TokenType.NONE

    for (token in tokens) {
        if (token.type == TokenType.DIGIT)
            if (current_operation == TokenType.NONE || current_operation == TokenType.PLUS) result += (token.char.code - '0'.code)
            else if (current_operation == TokenType.MINUS) result -= (token.char.code - '0'.code)
            else if (current_operation == TokenType.MULT) result *= (token.char.code - '0'.code) 

        else current_operation = token.type
    }

    return result
}




fun main(args: Array<String>) {
    if (args.isNotEmpty()) {
        println("Command line arguments:")
        
        try {
            val result = args.joinToString(separator = " ")
            val tokens = parseInput(result)
         
            println(calculate_tokens(tokens))

        } catch (e: IllegalArgumentException) {
            println("Error: ${e.message}")
        }


    } else {
        println("No command line arguments provided.")
    }
}
