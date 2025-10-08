using System;
using System.IO;
using System.Text;

namespace volume kubus
{
   public class main_class
   {
      static System.Random random_generator = new System.Random();
      public static void Main(string[] args)
      {
         string raptor_prompt_variable_zzyz;
         ?? lebar;
         ?? p;
         ?? v;
         ?? panjang;
         ?? t;
         ?? tinggi;
         ?? l;
         ?? volume;
      
         panjang ="p";
         raptor_prompt_variable_zzyz ="panjang dalam m";
         Console.WriteLine(raptor_prompt_variable_zzyz);
         p= Double.Parse(Console.ReadLine());
         lebar ="l";
         raptor_prompt_variable_zzyz ="lebar dalam m";
         Console.WriteLine(raptor_prompt_variable_zzyz);
         l= Double.Parse(Console.ReadLine());
         tinggi ="t";
         raptor_prompt_variable_zzyz ="tinggi dalam m";
         Console.WriteLine(raptor_prompt_variable_zzyz);
         t= Double.Parse(Console.ReadLine());
         volume ="v";
         v =p*l*t;
         Console.Write("volume = "+v+" meter kubik");
      }
   }
}
