#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>



int squr(int x){
  int ans;
  ans=x*x;
  return ans;
}



int main(){
  int fd = open("Imagine_The_Pixels.ppm", O_WRONLY | O_CREAT, 0644);
  char output[100]="P3 \n500 500 \n255\n";
  write(fd, &output, strlen(output));

  int r=255;
  int g=0;
  int b=255;
  
  int i=0;
  int j=0;

  int count=0;

  for(i=0; i<500; i++){
    for(j=0; j<500; j++){

      //r=255;
      //g=0;
      //b=255;	
      
      if(squr(i-250)+squr(j-250) <= squr(400)){
	r=255;
	g=0;
      }
      if(squr(i-250)+squr(j-250) <= squr(350)){
	r=223;	
	g=31;
      }
      if(squr(i-250)+squr(j-250) <= squr(300)){
	r=191;
	g=63;
      }
      if(squr(i-250)+squr(j-250) <= squr(250)){
	r=159;	
	g=95;
      }
      if(squr(i-250)+squr(j-250) <= squr(200)){
	r=127;	
	g=127;
      }
      if(squr(i-250)+squr(j-250) <= squr(150)){
	r=95;	
	g=159;
      }
      if(squr(i-250)+squr(j-250) <= squr(100)){
	r=63;
	g=191;
      }
      if(squr(i-250)+squr(j-250) <= squr(50)){
	r=31;
	g=232;
      }

      if(i < 250 && j < 250){
	b=0;
      }
      else{
	if(i > 250 && j < 250){
	  b=86;
	}
	else{
	  if(i < 250 && j > 250){
	    b=172;
	  }
	  else{
	    if(i > 250 && j > 250){
	      b=255;
	    }
	  }
	}
      }

      
      /*
      if(count >= 5){
	g++;
	count=0;
      }
      if(count < 5){
	count++;
      }
      */

      
      r=r%256;
      g=g%256;
      b=b%256;
      
      char value[25];
      sprintf(value, "%d %d %d \n", r, g, b);
      write(fd, &value, strlen(value));
      value[0]=0;
    }
  }


  
  close(fd); 
  return 1;
}
