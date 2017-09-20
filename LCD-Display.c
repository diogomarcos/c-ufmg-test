#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINT_HOR(x) x?printf("-"):PRINT_SPACE 
#define PRINT_VER(x) x?printf("|"):PRINT_SPACE
#define PRINT_SPACE  printf(" ")
#define PRINT_LF  printf("\n")

int main(int argc, char argv[]){

 int i,j,tmp=0;
 int seq,pos;
 int horizon[100];
 char val[100][9];
 short single_num;
 int cmd_num, cnt;
 
 int num[][7]={
 {1,1,1,0,1,1,1}, // 0
 {0,0,1,0,0,1,0}, // 1
 {1,0,1,1,1,0,1}, // 2
 {1,0,1,1,0,1,1},  // 3
 {0,1,1,1,0,1,0}, // 4
 {1,1,0,1,0,1,1}, // 5
 {1,1,0,1,1,1,1}, // 6
 {1,0,1,0,0,1,0}, // 7
 {1,1,1,1,1,1,1}, // 8
 {1,1,1,1,0,1,1}}; // 9

 //------------- Obtendo as entradas ------------
 for(i=0;;i++){
 
  scanf("%d",&horizon[i]);
  scanf("%s",val[i]);
  
  val[i][9] = '\0';
  
  if(horizon[i] == 0 && val[i][0] == '0')
   break;
  
 }  
  
 //----------- Realizando a impressão -----------
 for(cnt = 0; horizon[cnt] > 0 ; cnt++){ 
 
  //-------- Loop das partes numericas ----------
  for(pos=0; pos<7 ;pos++){ 
   if(pos == 2 || pos == 5){
    ++tmp == horizon[cnt] ? tmp=0, pos++ : pos-- ;
   }

   for(seq=0 ; val[cnt][seq] != '\0' ; seq++){
    
    single_num = val[cnt][seq]-48;
    
    if(pos%3 ==0){ 
     if(single_num != 3 && single_num != 7)
      PRINT_SPACE;
     for(i=0; i<horizon[cnt] ; i++)
      PRINT_HOR( num[single_num][pos] );
     PRINT_SPACE;
    }
    
    else if(pos%3 == 1){
     if(single_num != 3 && single_num != 7)
      PRINT_VER( num[single_num][pos] );
     if( pos == 1 || pos == 4 ){
      for(j=0; j<horizon[cnt] ; j++){
       PRINT_SPACE;
      }
     }
     PRINT_VER( num[single_num][pos+1] );
    }
    PRINT_SPACE;
   }
   PRINT_LF;
  }  
  PRINT_LF;        
 }

 return 0;
}