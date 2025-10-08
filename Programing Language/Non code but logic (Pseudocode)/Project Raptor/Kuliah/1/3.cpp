#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   ?? lastbal;
   ?? video;
   ?? re;
   ?? operation;
   ?? trans;
   ?? maxok;
   ?? moneyout;
   ?? ok;

   raptor_prompt_variable_zzyz ="max operation until overheat";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> maxok;
   ok =0;
   while (1)
   {
      ok =ok+1;
      if (ok>maxok)) break;
      while (1)
      {
         cout << "Welcome to SEAL BANK" << endl;         raptor_prompt_variable_zzyz ="any operation?";
         cout << raptor_prompt_variable_zzyz << endl;
         cin >> operation;
         if (operation>=1)) break;
         video =play;
      }
      raptor_prompt_variable_zzyz ="do you want withdraw?";
      cout << raptor_prompt_variable_zzyz << endl;
      cin >> trans;
      lastbal =10000;
      while (!(trans==0))
      {
         raptor_prompt_variable_zzyz ="how much you want withdraw? your balance is "+lastbal;
         cout << raptor_prompt_variable_zzyz << endl;
         cin >> moneyout;
         if (lastbal>=moneyout)
         {
            lastbal =lastbal-moneyout;
            cout << "your new balance  is "+lastbal << endl;         }
         else
         {
            cout << "LOL, you dont have money" << endl;         }
         raptor_prompt_variable_zzyz ="do you have any other transation?";
         cout << raptor_prompt_variable_zzyz << endl;
         cin >> re;
         if (re==1)
         {
         }
         else
         {
            trans =0;
         }
      }
   }
   cout << "Out of service" << endl;
   return 0;
}
