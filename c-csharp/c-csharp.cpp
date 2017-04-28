// c-csharp.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
//
#include <stdio.h>
#include <stdlib.h>

#define NAG_CALL __stdcall
#define NAG_DLL_EXPIMP __declspec(dllexport)

extern "C"{


// pointer of pointer 
typedef struct{
     char mem0;
     char mem1[12];
     char align[3];
} mem_struct;

typedef struct { 
     double re,im;
     char arr[8];
     mem_struct memstru1;
     double th;
} yc;

typedef struct { 
     char arbr[40];
} yc_wrapper;

typedef enum { red=101, green, blue,black } colour;
NAG_DLL_EXPIMP void NAG_CALL EnumString(colour rainbow, char *rainbowcolour);
NAG_DLL_EXPIMP void NAG_CALL EnumString(colour rainbow, char *rainbowcolour)
{
	 if (rainbow == black )
	 {
		strcpy(rainbowcolour, "Black is not a rainbow colour");
	 }
	 else
	 {
		strcpy(rainbowcolour, "This is a rainbow colour");
	 }
} 


NAG_DLL_EXPIMP void transfer(char* buf,int *len,char *returnmsg);
NAG_DLL_EXPIMP void transfer(char* buf,int *len, char *returnmsg)
{
	if(buf[0]==1)
	{
		strcpy(returnmsg, "buf[0]==a");
	}
	else if(buf[0]==2)
	{
		strcpy(returnmsg, "buf[0]==b");
	}



}
//NAG_DLL_EXPIMP void NAG_CALL Tryyc(yc inputVar, yc *outputVar, int n, yc array[]);

 void Tryyc(yc inputVar, yc **outputVar, int n, yc array[])
{
     *outputVar = (yc*)malloc(sizeof (yc));
     (*outputVar)->re = ++inputVar.re;
     (*outputVar)->im = ++inputVar.im;
     (*outputVar)->arr[0] = inputVar.arr[0] + 10;
     (*outputVar)->th = ++inputVar.th;

     array[0].re = 99.0;
     array[0].im = 98.0;
     array[1].re = 97.0;
     array[1].im = 96.0;
} 
NAG_DLL_EXPIMP void NAG_CALL TryYCwrapper(yc inputVar, yc_wrapper **outputVar)//, yc_wrapper array[]){
{
     //yc iyc;
     //iyc.re = 1.0;
     //iyc.im =1.1;
     yc arr[10];
     Tryyc(inputVar,(yc**) outputVar, 10,  arr);
}
NAG_DLL_EXPIMP void NAG_CALL printYCwrapper( yc_wrapper *outputVar){
     yc* ptr = (yc*)(outputVar);
     printf("re=%f,im=%f\n",ptr->re,ptr->im);
     printf("arr[0]=%d\n",ptr->arr[0]);
     printf("th=%f\n",ptr->th);
}
//Point
typedef struct
{

     unsigned int addr;

     float Yc_Value;
     unsigned char OV ;
     unsigned char BL ;
     unsigned char SB ;
     unsigned char NT ;
     unsigned char IV ;

}Point;

typedef struct
{
     unsigned int Yc_Num;
     Point Yc_Data[128];
}PointsStru;

NAG_DLL_EXPIMP void NAG_CALL PointAssign(PointsStru *outputVar )
{
     outputVar->Yc_Num = 128;
     outputVar->Yc_Data[2].Yc_Value = 123.45;
     outputVar->Yc_Data[2].BL = 1;
     outputVar->Yc_Data[2].SB = 2;


     outputVar->Yc_Data[127].Yc_Value = 567.89;
     outputVar->Yc_Data[127].BL = 2;
     outputVar->Yc_Data[127].SB = 3;

}
}
