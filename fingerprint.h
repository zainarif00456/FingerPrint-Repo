#ifndef _FINGERPRINT_HEADER_
#define _FINGERPRINT_HEADER_

#ifndef MY_RET_ERROR
	#define RET_SUCCESS			(0)
	#define RET_ERROR_PORT		(-1)
	#define RET_ERROR_READ		(-2)
	#define RET_ERROR_WRITE		(-3)
	#define RET_ERROR_PARAM		(-4)
	#define RET_ERROR_MEMERY	(-5)
	#define RET_ERROR_ERRDATA	(-6)
	#define RET_ERROR_UNKOWN	(-999)
#endif

	#define RET_ERROR_FAIL			(-201) //failed
	#define RET_ERROR_FULL			(-202) //storage is full
	#define RET_ERROR_NOUSER		(-203) //User does not exist
	#define RET_ERROR_USER_EXIST	(-204) //User already exists
	#define RET_ERROR_TIMEOUT		(-205) //Image acquisition timeout
	#define RET_ERROR_BREAK			(-206) //Command terminated
	#define RET_ERROR_IMAGEFAIL		(-207) //Image failute

#if defined(__cplusplus)
    extern "C" {
    #endif
	int FP_SDKVersion();
	int FP_Init();
	int FP_SendData(unsigned char *psz, int nLen);
	int FP_ReadData(unsigned char *psz, int nLen, int nTimeout);
	int FP_UnInit();
	int FP_Version(unsigned char *psz, int nLen);
	int FP_UserCount();
	int FP_DelUser();
	int FP_CheckUser();
	int FP_RegUser(unsigned short nStep);
	int FP_GetFPImg(char *filename);
	#if defined(__cplusplus)
    }
    #endif

#endif