#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

  FILE *input, *output;
  output = fopen(argv[2],"w");
  unsigned int currentLine;
  char *value;
  int read_char;
  unsigned int vcpm;
  int QuotationOnOff; 

  value = (char*)malloc(sizeof(char)*50);  
  char *column = (char*)malloc(sizeof(char)*100);

  if(input = fopen(argv[1],"r") ) {
    output = fopen("output.xml","a");
    fprintf(output,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root>\n<row>\n");

    rewind(input);
    currentLine = 1;
    vcpm = 0;
    QuotationOnOff = 0;
    int valNum = 0;
    while( (read_char = fgetc(input)) != EOF)
    {
       switch(read_char)
       {
          case ',':

              value[vcpm] = '\0';  

              if(currentLine == 1){
                strcat(column,value);
                strcat(column,",");
              }

              else{
                fprintf(output,"<");
                int i = 0,j=0;
                 while(column[i] != '\0'){
                  if(column[i] ==',')
                    j++;
                  if(j == valNum){
                    if(column[i] != ',')
                      fprintf(output,"%c",column[i] );
                  }
                  i++;
                }

                fprintf(output,">");
                fprintf(output,"%s</",value);
                i=0;j=0;
                while(column[i] != '\0'){
                  if(column[i] ==',')
                    j++;
                  if(j == valNum){
                   if(column[i] != ',')
                      fprintf(output,"%c",column[i] );
                  }
                  i++;
                }
                fprintf(output,">\n");
                valNum++;
              }
              vcpm = 0;
            break;
          case '\n':

              value[vcpm-1] = '\0';
              vcpm = 0;
              if(currentLine == 1){
                 strcat(column,value);  
              }
              else{
               fprintf(output,"<");
                int i = 0,j=0;
                 while(column[i] != '\0'){
                  if(column[i] ==',')
                    j++;
                  if(j == valNum){
                    if(column[i] != ',' ){
                      fprintf(output,"%c",column[i] );
                    }
                  }
                  i++;
                }
                   fprintf(output,">");
        
                fprintf(output,"%s</",value);

                i=0;j=0;
                while(column[i] != '\0'){
                  if(column[i] ==',')
                    j++;
                  if(j == valNum){
                   if(column[i] != ',' && column[i] != '\n'){
                      fprintf(output,"%c",column[i] );
                   }
                  }
                  i++;
                }
                fprintf(output, ">\n</row>\n");
                if( value[strlen(value)] != '\0')
                  fprintf(output, "<row>\n");
                valNum = 0;
              }           
            currentLine++;

            break;
          case '\"':
              if(!QuotationOnOff) {
                QuotationOnOff = 1;         
                value[vcpm] = read_char;
                vcpm++;

              } else {
                QuotationOnOff = 0;
                value[vcpm] = read_char;
                vcpm++;
              }

            break;
          default: 

              value[vcpm] = read_char;
              vcpm++;

            break;
       }
    }

    fclose(input); 
    free(value);

  }
  fprintf(output, "</root>\n");

  return 0;
}