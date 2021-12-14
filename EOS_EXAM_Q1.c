//Message Queue
//SENDER CODE
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

mqd_t mq_s;
int fd; // file discriptor to read file from distionary
struct mq_attr cdac_mq_attr;
char buff;
int main()
{
   cdac_mq_attr.mq_flags = 0;
   cdac_mq_attr.mq_maxmsg = 20;
   cdac_mq_attr.mq_msgsize = 1048576;
   cdac_mq_attr.mq_curmsgs = 0;
   
  fd= open("/home/ubuntu/Desktop/EOS_EXAM_50330031/dictionary.txt",O_RDONLY);
     //error Condition on opening file
   if(fd == -1)
   {
    printf("Error opening file!\n");
    exit(0);
   }
    mq_s = mq_open("/cdacmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdac_mq_attr);
   while(read(fd,&buff,1))
   {
    printf("%s",&buff);
    mq_send(mq_s, &buff,1, 0);
   }
 //printf("%d",mq_s);
  
    
   printf("sending data done...");
   mq_close(mq_s);
   return 0;
}