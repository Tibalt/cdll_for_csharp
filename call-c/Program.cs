/***************************************************************
 * C# Class *
 ***************************************************************/
using System;
using System.Runtime.InteropServices;


namespace DDJexamples
{
    // Nag yc type
    [StructLayout(LayoutKind.Sequential)]
    unsafe public struct mem_struct
    {
        public byte mem0;
        public fixed byte mem1[12];
        public fixed byte align[3];
    }
    unsafe public struct yc
    {
        public double re;
        public double im;
        public fixed byte arr[8];
        public mem_struct mem;
        public double th;
        //public fixed byte arr[16];
    };
    unsafe public struct yc_wrapper
    {
        public fixed byte arr[36];
    };

    unsafe public struct Point
    {
        public uint addr;
        public float Yc_Value;
        public byte OV;
        public byte BL;
        public byte SB;
        public byte NT;
        public byte IV;

    }

    unsafe public struct Data_Stru
    {
        public uint Yc_Num;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public Point[] Yc_Data;
    }


    public class ExerciseTryyc
    {

        [DllImport("c-csharp.dll")]
        unsafe public static extern void TryYCwrapper(yc inputVar, yc_wrapper** outputVar);
        [DllImport("c-csharp.dll")]
        unsafe public static extern void printYCwrapper(yc_wrapper* outputVar);
        [DllImport("c-csharp.dll")]
        unsafe public static extern void PointAssign(ref Data_Stru outputVar);

  
        unsafe public static void Main()
        {
            int n = 2;
            yc inputVar = new yc();
            yc outputVar = new yc();
            yc[] array = new yc[10];

            Data_Stru y_data = new Data_Stru();

            yc_wrapper* wrapperVar = null;// = new yc_wrapper();

            inputVar.re = 1.0;
            inputVar.im = 2.0;
            inputVar.arr[0] = 100;
            inputVar.th = 3.0;

            TryYCwrapper(inputVar, &wrapperVar);
            Console.WriteLine("Print out in dll with the yc value handled by the same dll just now!");
            Console.WriteLine("See function TryYCwrapper in dll for the value supposed to be.");
            Console.WriteLine("-----------------------------------------------------------------------");
            printYCwrapper(wrapperVar);


            Console.WriteLine("");
            Console.WriteLine("print out values got from dll in C# !");
            PointAssign(ref y_data);
            Console.WriteLine("-----------------------------------------------------------------------");
            Console.WriteLine("data = ({0},{1},{2},{3})", y_data.Yc_Num, y_data.Yc_Data[127].Yc_Value, y_data.Yc_Data[127].BL, y_data.Yc_Data[127].SB);
            Console.WriteLine("data = ({0},{1},{2},{3})", y_data.Yc_Num, y_data.Yc_Data[2].Yc_Value, y_data.Yc_Data[2].BL, y_data.Yc_Data[2].SB);
            Console.ReadLine();
        }
    }














}