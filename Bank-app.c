// Author : velan
// Date : Dec-31-25 at 9.45pm Indian Standard Time
// Description : To make a Bank-Account-System though C-Programming

// Algorithm
/*
 * 1.Start Program
 * 2.Open Option_menu
 * 3.Select_Option
 * 4.Process Option
 * 5.Exit
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Account {
  char bankName[50];
  char bankBranch[100];
  char name[60];
  int accountNumber;
  char Address[250];
  double balance;
};

int DisplayOptions();
struct Account CreateAccount();
void CheckBalance(struct Account acc);
void DepositMoney(double *balance);
bool Exit();

int main() {
  struct Account account;
  bool exit = false;

  // Start of Program
  puts("\n#### WELCOME TO BANK APPLICATION ####\n");
  do {
    switch (DisplayOptions()) {
    case 1:
      account = CreateAccount();
      break;
    case 2:
      CheckBalance(account);
      break;
    case 3:
      DepositMoney(&account.balance);
      break;
    case 4:
      exit = Exit();
      break;
    default:
      printf("\nYou Enter something Wrong!");
      break;
    }
  } while (!exit);

  printf("Program Has been Succefully Executed! ");
  return 0; // End of Program
}

// DisplayOptions
int DisplayOptions() {
  int choise;

  printf("\n\n##Bank Option menu::##");
  printf("\n1.CreateAccount");
  printf("\n2.CheckBalance");
  printf("\n3.DepositMoney");
  printf("\n4.Exit");

  printf("\nPlease enter any one Option(1,2,3,4,5,) : ");
  scanf("%d", &choise);
  return choise;
}

struct Account CreateAccount() {
  struct Account account;
  srand(time(NULL));

  printf("\nAccount Creating Menu::");
  printf("\n\nEnter the bank name : ");
  scanf("%s", account.bankName);
  printf("\nEnter the bank Branch : ");
  scanf("%s", account.bankBranch);
  printf("\nEnter your name       : ");
  scanf("%s", account.name);
  printf("\nEnter your Address    : ");
  scanf("%s", account.Address);

  account.accountNumber = rand();
  account.balance = 0;
  printf("\nYour Account number   : %d", account.accountNumber);
  printf("\nYour Account balance  : %.2f", account.balance);

  return account;
}

void CheckBalance(struct Account acc) {
  printf("\n###Check Balance Menu :: ");
  printf("\n\n\tCurrent Balance : %.2f", acc.balance);
  printf("\n\n Press any key to exit : ");
  scanf("");
}

void DepositMoney(double *balance) {
  double balances;
  printf("\n Deposit Menu:: ");
  printf("\n\n Enter amount to deposit : ");
  scanf("%lf", &balances);
  *balance += balances;
}

bool Exit() {
  printf("\n\n####End-Bank-Apllication####\n\n");
  return true;
}
