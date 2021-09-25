#include <stdlib.h>

int space_char(char c)
{
  if(c == '\t' or c == ' '){
    return 1
  }
  else{
    return 0
  }
}

int non_space_char(char c)
{
  if!(c == '\t' or c == ' '){
      return 1
    }
  else{
    return 0
  }

}

char *word_start(char *str)
{
  int i = 0;
  char *start_ptr = NULL;
  while(str[i] != '\0'){

    if(str[i] == '\0'){
      if(str[i +1] != '\0'){
	start_ptr = &str[i+1];
	break;
      }
    }
    i++;
  }
  
  return start_ptr;
  
}

char *word_terminator(char *word)
{
  int i = 0;
  char *end_ptr = NULL;
  while(str[i] != '\0'){
    if(str[i] == ' '){
      end_ptr = &str[i];
      break;
    }
    i++;
  }
  return end_ptr;
}

int count_words(char *str)
{
  int i = 0;
  int count = 0;
  while(str[i] != '\0'){
    if(str[i] == ' '){
      count++;
    }
    
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *new_string = (char*) malloc(len * sizeof (char));

  for(int i = 0;i < len; i++){
    new_string[i] = *inStr;
    inStri++
  }
  return new_string;
}

char **tokenize(char* str)
{
  char*temp = str;
  int word_count = count_words(str)+ 1;

  char** tokens =(char**)malloc(word_count *sizeof(char*));
  int count = 0;
  int start_char = 0;
  int end_char = 0;

  while(str[end] != '\0'){
    if(str[end] == ' '){
      tokens[count++] = copy_str(str+start, end-start);
      start = end +1;
      end = start;
    }
    else{
      end++;
    }
    
  }
  tokens[count++] = copy_str(str+start,end-start);
  tokens[count] = '';

  return tokens;
     
}

void print_tokens(char **tokens)
{
  while(*tokens != ''){
    printf("%s\n", *tokens);
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  char **temp = tokens;
  while(*temp!= ""){
    free(*temp);
    temp++;
  }
  free(temp);
}




