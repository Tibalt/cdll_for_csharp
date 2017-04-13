// c-csharp.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
//
#include <stdio.h>
//
//extern "C"
//{
//	typedef struct {
//		float value;
//		char name[128];
//		int id;
//	}yc_stru;
//	yc_stru yc[10]={{1.1,"yc",1},{2.2,"yc",2}};
//  
//	
//	__declspec(dllexport) void DisplayHelloFromDLL()
//  {
//    printf ("Hello from DLL !\n");
//	getchar();
//  }
//
//    __declspec(dllexport) void getYC(int* num, yc_stru *ptr)
//  {
//	*num = 2;
//	memcpy(ptr,yc, sizeof(yc_stru));
//    printf ("data is copied out from DLL !\n");
//	getchar();
//  }
//
//}
#define NAG_CALL __stdcall
#define NAG_DLL_EXPIMP __declspec(dllexport)

extern "C"{
 typedef struct { /* NAG yc Data Type */
 double re,im;
 } yc;

NAG_DLL_EXPIMP void NAG_CALL Tryyc(yc inputVar, yc *outputVar, int n, yc array[]);
NAG_DLL_EXPIMP void NAG_CALL Tryyc(yc inputVar, yc *outputVar, int n, yc array[])
{
 outputVar->re = ++inputVar.re;
 outputVar->im = ++inputVar.im;
 array[0].re = 99.0;
 array[0].im = 98.0;
 array[1].re = 97.0;
 array[1].im = 96.0;

} 
}