#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#include "fingerprint.h"

void PrintMenu(void);
int number = 0;
void PrintMenu(void)
{
	printf("\r\n");
	printf("--------             MENU    SDK:V%d-------\r\n", FP_SDKVersion());	
	printf("	1 - FP_Version\r\n");
	printf("	2 - FP_RegUser\r\n");
	printf("	3 - FP_CheckUser\r\n");
	printf("	4 - FP_UserCount\r\n");
	printf("	5 - FP_DelUser\r\n");
	printf("	6 - FP_GetFPImg\r\n");
	
	printf("	0 - exit\r\n");
	printf("------- Please Press Key to Continue ------\r\n");
}

int main(int argc, char** argv)
{
	int nRet = 0;

	nRet = FP_Init();
	if (nRet < 0)
	{
		printf("FP_Init fail:%d\r\n", nRet);
		return 1;
	}
	else
	{
		system("python3 device_status.py");
		printf("Connect...OK\r\n");
	}
	int c;
	//clrscr();
	//PrintMenu();
	// Old Code
	/*
	while((scanf("%d",&c)) & (c!= 0))
	{
		if (c == 10)
			continue;
		switch(c)
		{
			case 1:
			{
				unsigned char szVersion[128] = {0};
				int nRet = FP_Version(szVersion, 128);
				printf("FP_Version[%d]:%s\r\n", nRet, &szVersion[0]);
			}
			break;
			case 2:
			{
				printf("Please press the 1st finger\r\n");
				int nRet = FP_RegUser(1);
				if (nRet == RET_SUCCESS)
				{
					sleep(3);
					printf("Please press the 2nd finger\r\n");
					nRet = FP_RegUser(2);
					if (nRet == RET_SUCCESS)
					{
						sleep(3);
						printf("Please press the 3rd finger\r\n");
						nRet = FP_RegUser(3);
						if (nRet > 0)
						{
							printf("register user ok, the user id is:%d\r\n", nRet);
						}
						else
						{
							printf("FP_RegUser fail, try again:%d\r\n", nRet);
						}
					}
					else
					{
						printf("FP_RegUser fail, try again:%d\r\n", nRet);
					}
				}
				else
				{
					printf("FP_RegUser fail, try again:%d\r\n", nRet);
				}
			}
			break;
			case 3:
			{
				printf("Please press finger\r\n");
				int nRet = FP_CheckUser();
				printf("FP_CheckUser:%d\r\n", nRet);
			}
			break;
			case 4:
			{
				int nRet = FP_UserCount();
				printf("FP_UserCount:%d\r\n", nRet);
			}
			break;
			case 5:
			{
				int nRet = FP_DelUser();
				printf("FP_DelUser:%d", nRet);
			}
			break;
			case 6:
			{
				printf("press the finger\r\n");
				//number = rand();
				char filename[] = "img.jpg";
				int nRet = FP_GetFPImg(filename);
				if(nRet==0){
					// Code for Separating image
					system("python3 send_pic.py");
				}
				printf("FP_GetFPImg:%d\r\n", nRet);
			}
			break;
			default:
				printf("the key is :%c, Please press the right key\r\n", c);
			break;
		}
		*/
		while(true){
				// Reinitializing Fingerprint.
				sleep(2);
				FP_Init();
				printf("press the finger when scanner light is turned on\r\n");
				//number = rand();
				
				char filename[] = "img.jpg";
				int nRet = FP_GetFPImg(filename);
				if(nRet==0){
					// Code for Separating image
					system("python3 send_pic2.py");
				}
				else if(nRet==-205){
					FP_UnInit();
					continue;
				}
				else{
					system("python3 send_pic2.py");
					printf("Could not Read Fingerprint. Try again...");
				}
				printf("FP_GetFPImg:%d\r\n", nRet);
				// After completing one scan either success or fail, it will uninit and re-init with the start of the loop.
				FP_UnInit();
		}
		
		//PrintMenu();
	//}
	FP_UnInit();
}
