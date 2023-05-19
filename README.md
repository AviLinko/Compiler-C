# Compiler C
 
 Mini compiler, created in cpp language.
 
this is a C++ program that implements a lexer for a simple arithmetic expression. The lexer tokenizes the input expression and outputs tokens representing integers, arithmetic operators, and the end-of-file (EOF) marker.
 
 explaination:

The tokenType enum defines the different types of tokens that can be encountered: INT for integers, PLUS for the plus operator, MINUS for the minus operator, DIVIDER for the division operator, MUL for the multiplication operator, and EOF for the end-of-file marker.
The Token class represents a token and consists of two attributes: type (of type TokenType) to store the token type, and value (of type int) to store the token value.
The Lexer class is responsible for tokenizing the input text. It takes the input text as a parameter in its constructor.
The get_next_token function of the Lexer class reads the input text character by character and returns the next token encountered.
The while loop in get_next_token iterates until the end of the input text is reached. It checks the current character and determines the appropriate token type based on the character.

If the current character is a digit, the get_integer function is called to extract the integer value from the input text
The advance function moves the lexer position to the next character in the input text.
The get_integer function extracts a sequence of consecutive digits and converts them into an integer value.
In the main function, an instance of the Lexer class is created, initialized with the input text "12 + 3 * 4 / 3".
The get_next_token function is called to retrieve the first token.
The while loop iterates as long as the token type is not EOF. It prints the token type and value using cout.
The get_next_token function is called again to retrieve the next token.
Finally, the program returns 0 to indicate successful execution.

In summary, the code implements a lexer that tokenizes a simple arithmetic expression, extracting integers and operators, and printing the corresponding tokens.
