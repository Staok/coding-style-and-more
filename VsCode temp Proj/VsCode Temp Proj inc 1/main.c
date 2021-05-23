#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 用户头文件 */
#include"libA\IncA.h"
#include"libB\IncB.h"
#include"inc\common.h"



int main()
{
    char message[2][10] = {"start!","end!"},overstate;
    srand((int)time(0));
    printf("\n%s\n",message[0]);
    /* ___________________________开始用户程序___________________________ */


    printf("\n%d\n",add(-1,100));
    printf("%d\n",  sub(-1,100));
    printf("%d\n",  common(-1,100));


	/* ___________________________结束用户程序___________________________ */
	printf("\n%s\n",message[1]);
    printf("Press Enter to exit");
    scanf("%c",&overstate);
    return 0;
}

