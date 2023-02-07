#include <iostream>
#include <string>

using namespace std;

enum tokenType {
    INT,
    PLUS,
    MINUS,
    DIVIDER,
    MUL,
    EOF
};


class Token {
 public:
  TokenType type;
  int value;
  Token(TokenType type, int value) : type(type), value(value) {}
};

class Lexer {
 public:
  Lexer(string text) : text(text), pos(0), current_char(text[pos]) {}

  Token get_next_token() {
    while (current_char != '\0') {
      if (isdigit(current_char)) {
        return Token(INTEGER, get_integer());
      } else if (current_char == '+') {
        advance();
        return Token(PLUS, '+');
      } else if (current_char == '-') {
        advance();
        return Token(MINUS, '-');
      } else if (current_char == '*') {
        advance();
        return Token(MUL, '*');
      } else if (current_char == '/') {
        advance();
        return Token(DIV, '/');
      }

      advance();
    }

    return Token(EOF, '\0');
  }

 private:
  string text;
  int pos;
  char current_char;

  void advance() {
    pos++;
    if (pos > text.length() - 1) {
      current_char = '\0';
    } else {
      current_char = text[pos];
    }
  }

  int get_integer() {
    int result = 0;
    while (isdigit(current_char)) {
      result = result * 10 + current_char - '0';
      advance();
    }

    return result;
  }
};

int main() {
  Lexer lexer("12 + 3 * 4 / 3");
  Token token = lexer.get_next_token();
  while (token.type != EOF) {
    cout << "Token: " << token.type << " Value: " << token.value << std::endl;
    token = lexer.get_next_token();
  }

  return 0;
}