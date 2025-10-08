procedure volume kubus is
   raptor_prompt_variable_zzyz : Unbounded_String;
   lebar : ??_Variable;
   p : ??_Variable;
   v : ??_Variable;
   panjang : ??_Variable;
   t : ??_Variable;
   tinggi : ??_Variable;
   l : ??_Variable;
   volume : ??_Variable;
begin
   panjang :="p";
   raptor_prompt_variable_zzyz :="panjang dalam m";
   Put_Line(raptor_prompt_variable_zzyz);
   Get(p);
   lebar :="l";
   raptor_prompt_variable_zzyz :="lebar dalam m";
   Put_Line(raptor_prompt_variable_zzyz);
   Get(l);
   tinggi :="t";
   raptor_prompt_variable_zzyz :="tinggi dalam m";
   Put_Line(raptor_prompt_variable_zzyz);
   Get(t);
   volume :="v";
   v :=p*l*t;
   Put("volume = "+v+" meter kubik");
end volume kubus;
