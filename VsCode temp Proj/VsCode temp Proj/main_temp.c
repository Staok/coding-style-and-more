#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random(x) (rand()%x)

int main()
{
    char message[2][10] = {"start!","end!"},overstate;
    srand((int)time(0));
    printf("\n%s\n",message[0]);

    //printf("\n%d\n",sizeof(unsigned short));
	
	// a.next = &b;
    // a.data = 0;
    // a.next->data = 999;
	
	// printf("%d\r\n",a.next->data);
	
    // buf4tok = strtok(srt_buf," ,-");
    // if(buf4tok != NULL)
    // {
    //     for(i = 0;buf4tok != NULL;i++)
    //     {
    //         printf("%3d : %s\r\n",i,buf4tok);
    //         buf4tok = strtok(NULL," ,-");
    //     }
    // }

	
	printf("\n%s\n",message[1]);
    printf("Press Enter to exit");
    scanf("%c",&overstate);
    return overstate;
}