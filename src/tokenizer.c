#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c)
{
  if(c != ' ' || c != '\t'){
    return 1;
    }
  else{
    return 0;
  }

}

char *word_start(char *str)
{
  int i = 0;
  while(space_char(str[i]) == 1){
    if(str[i] == '\0')
      return NULL;
    i++;
  }
  return &str[i];
  
}

char *word_terminator(char *word)
{
  word = word_start(word);
  if(word == NULL)
    return NULL;
  int i = 0;

  while(non_space_char(word[i]) == 1){
    if(word[i] == '\0')
      return &word[i-1];
    i++;
  }

  return &word[i];
}

int count_words(char *str)
{
  int i = 0;
  int count = 0;
  while(str[i] != '\0'){
    if(space_char(str[i]) && non_space_char(str[i+1])){
      count++;
    }
    i++;
    
  }
  count++;
  return count;
}

char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *newString = malloc((len+1) *sizeof(char));

  while(i<=len){
    newString[i] = inStr[i];

    i++;
  }
  newString[i] = 0;
  return newString;
}

char **tokenize(char* str)
{
  int i = 0;
  int len;
  int count = count_words(str);

  char **tokens = malloc((count+1) * sizeof(char*));
  char *start = str;
  char *end = str;
  


  while(i < count)
    {
      start = word_start(end);
      end = word_terminator(start);
      tokens[i] = copy_str(start, end - start);
      i++;
    }
  tokens[i] = 0;
  return tokens;
  
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]!=NULL){
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]!=0){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}




