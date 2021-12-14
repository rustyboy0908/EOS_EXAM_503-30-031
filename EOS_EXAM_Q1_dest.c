//Message Queue
//Receiver CODE
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdio.h>
#include <string.h>

mqd_t mq_s;
struct mq_attr cdac_mq_attr;
char buff[20];
int msg_prio;
int main()
{
   cdac_mq_attr.mq_flags=0;
   cdac_mq_attr.mq_maxmsg=20;
   cdac_mq_attr.mq_msgsize=1048576;
   cdac_mq_attr.mq_curmsgs=0;

   mq_s= mq_open("/cdacmq",O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdac_mq_attr);

    mq_receive(mq_s,&buff,20,&msg_prio);
    if(&buff = "m" )
    printf("Received Message: %s \n Message Priority : %d",strlen(buff),msg_prio);

   
   mq_close(mq_s);
   return 0;
}