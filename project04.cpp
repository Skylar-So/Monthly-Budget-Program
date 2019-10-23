/***********************************************************************
* Program:
*    Project 04, Use function in monthly budget. 
*    Brother Comeau, CS124
* Author:
*    Skylar So
* Summary: 
*    This Project is to make my monthly budget using function,
*    and display them on the screen.
*************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * GET INCOME
 * Prompt the user for his income. 
 ***********************************************************************/
double getIncome(double income)
{
   cout << "\tYour monthly income: ";
   cin >> income;

   return income;        
}

/**********************************************************************
* GET BUDGET LIVING
* Prompt the user for his budget living..
************************************************************************/
double getBudgetLiving(double budgetLiving)
{
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   
   return budgetLiving;
}

/**********************************************************************
 * GET ACTUAL LIVING
 * Prompt the user for his actual living.
 **********************************************************************/
double getActualLiving(double actualLiving)
{
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   
   return actualLiving;
}

/**********************************************************************
 * GET ACTUAL TAXES
 * Prompt the user for his actual taxes.
 ***********************************************************************/
double getActualTax(double actualTax)
{
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   
   return actualTax;
}

/**********************************************************************
 * GET ACTUAL TITHE
 * Prompt the user for his actual tithe..
 ***********************************************************************/
double getActualTithing(double actualTithing)
{
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   
   return actualTithing;
}

/**********************************************************************
 * GET ACTUAL OTHER
 * Prompt the user for his actual other expenses..
 ***********************************************************************/
double getActualOther(double actualOther)
{
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   
   return actualOther;
}

/**********************************************************************
 * This function is to compute the budget tax.
 **********************************************************************/
double computeTax(double monthlyIncome)
{
   double yearlyIncome = monthlyIncome * 12;
   double yearlyTax;

   if (yearlyIncome <= 15100)
   {
      yearlyTax = yearlyIncome * 0.10;
   }
   else if (15100 <= yearlyIncome && yearlyIncome < 61300)
   {
      yearlyTax = 1510.00 + 0.15 * (yearlyIncome - 15100);
   }
   else if (61300 <= yearlyIncome && yearlyIncome < 123700)
   {
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
   }
   else if (123700 <= yearlyIncome && yearlyIncome < 188450)
   {
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
   }
   else if (188450 <= yearlyIncome && yearlyIncome < 336550)
   {
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
   }
   else if (336550 <= yearlyIncome)
   {
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
   }
   double monthlyTax = yearlyTax / 12;
      
   return monthlyTax;
}

/**********************************************************************
 * Compute the budget tithing.
 **********************************************************************/
double computeTithing(double income)
{
   //calculate the budget tithing
   double budgetTithing =  income / 10;

   return budgetTithing;
}

/**********************************************************************
 * This function DISPLAY the users income, tithing, other,
 * budgeted living, and actual living.
 ***********************************************************************/
int display(double income, double budgetLiving, double actualLiving,
            double actualTax, double actualTithing, double actualOther)
{
   //tax
   double monthlyIncome = income;
   double budgetTax = computeTax(monthlyIncome);
   
   //compute tithing
   double budgetTithing = computeTithing(income);
   
   //compute other expenses
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;

   //compute actual Difference
   double actualDifference = income - actualTax - actualTithing
         - actualLiving - actualOther;

   // set the format to two digits
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income
        << "    $" << setw(11) << income
        << "\n";
   cout << "\tTaxes           $" << setw(11) << budgetTax
        << "    $" << setw(11) << actualTax
        << "\n";
   cout << "\tTithing         $" << setw(11) << budgetTithing
        << "    $" << setw(11) << actualTithing
        << "\n";
   cout << "\tLiving          $" << setw(11) << budgetLiving
        << "    $" << setw(11) << actualLiving
        << "\n";
   cout << "\tOther           $" << setw(11) << budgetOther
        << "    $" << setw(11) << actualOther
        << "\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.00
        << "    $" << setw(11) << actualDifference
        << "\n";

   return 0;
}

/**********************************************************************
 * Display monthly budget on the screen
 ***********************************************************************/
int main()
{
   //statement
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   //get the user input
   double income = getIncome(income);
   double budgetLiving = getBudgetLiving(budgetLiving);
   double actualLiving = getActualLiving(actualLiving);
   double actualTax = getActualTax(actualTax);
   double actualTithing = getActualTithing(actualTithing);
   double actualOther = getActualOther(actualOther);

   //display
   display(income, budgetLiving, actualLiving,
           actualTax, actualTithing, actualOther);
      
   
   return 0;
}
