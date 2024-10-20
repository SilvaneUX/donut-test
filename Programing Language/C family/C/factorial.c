#include <stdio.h>

unsigned int factorial(int num)
{
  if (num == 0)
  {
    return 1;
  }

  int multiply = 1;
  for (int i = 1; i <= num; i++)
  {
    multiply *= i;
  }

  return multiply;
}

int main()
{
  int number;
  printf("Enter the number you want to factorial: ");
  scanf("%d", &number);

  int factorialNum = factorial(number);
  printf("Factorial of %d is %d", number, factorialNum);

  return 0;
}