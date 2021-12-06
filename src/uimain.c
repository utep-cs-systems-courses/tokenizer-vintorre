#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"



int main()
{
  List *history = init_history();
  while(1){
    char userIn[100];
    printf("%s\n" , "Hello what task would you like to perform?");
    printf("%s\n" , "[1] Tokenize");
    printf("%s\n", "[2] Add String to history.");
    printf("%s\n", "[3] Clear History");
    printf("%s\n", "[4] Print History");
    printf("%s\n", "[5] Get History");
    putchar('$');
    fgets(userIn, 100, stdin);
    if(userIn[0] == '1'){
      printf("%s\n", "Enter string you would like to tokenize...");
      fgets(userIn, 100, stdin);
      char *str = userIn;
      char **tokens = tokenize(str);
      add_history(history, str);
      print_tokens(tokens);

    }
    if(userIn[0] == '2'){
      printf("%s\n", "Enter string you would like to add to history...");
      fgets(userIn, 100, stdin);
      add_history(history, userIn);
      print_history(history);

    }
    if(userIn[0] == '3'){
      free_history(history);
      printf("%s\n", "History has been cleared");

    }
    if(userIn[0] == '4'){
      print_history(history);

    }
    if(userIn[0] == '5'){
      printf("%s\n", "At what point would you like to get history?");
      fgets(userIn, 100, stdin);
      int index = userIn;
      char * content = get_history(history, index);
      printf("String at that index is: %s\n", content);
    }
    else{
      printf("%s\n", "Invalid input");
    }
    
  }
}
