#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   int s;
   int b;
   int m;
   int a;

   a =1;
   s =0;
   raptor_prompt_variable_zzyz ="Maksimal";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> m;
   raptor_prompt_variable_zzyz ="1 Untuk Mencari ganjil, 0 Untuk memcari Genap";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> b;
   while (!(s>=3))
   {
      if (b==1)
      {
         cout << "List angka yang Ganjil antara 0 sampai "+a << endl;         cout << "Ganjil : " << endl;         while (!(a>=m+1))
         {
            if (a % 2==0)
            {
            }
            else
            {
               cout << a << endl;            }
            a =a+1;
         }
         s =3;
      }
      else
      {
         if (b==0)
         {
            cout << "List angka yang Genap antara 0 sampai "+a << endl;            cout << "Genap : " << endl;            while (!(a>=m+1))
            {
               if (a % 2==0)
               {
                  cout << a << endl;               }
               else
               {
               }
               a =a+1;
            }
            s =3;
         }
         else
         {
            cout << "Salah input gan, cuma 1 sama 0 aja yang bisa" << endl;            if (s>=2)
            {
               cout << "Gan, udah 3 kali lho salah mulu, dah lah males" << endl;               s =s+1;
            }
            else
            {
               raptor_prompt_variable_zzyz ="1 Untuk Mencari ganjil, 0 Untuk memcari Genap";
               cout << raptor_prompt_variable_zzyz << endl;
               cin >> b;
            }
            s =s+1;
         }
      }
   }

   return 0;
}
