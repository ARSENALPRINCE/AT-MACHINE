#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class ATM
{
public:
    int menu();
      void withdraw(int amount);
      void balance();
      void deposit(int amount);
	int accnum;
    int pincode;
    int balanceamt;  
};

int ATM::menu() //Function for displaying the main menu
{
    int ch;
    cout<<"\n\nATM Machine\n\n";
    cout<<"1. Withdraw Money\n";
    cout<<"2. Check Balance\n";
    cout<<"3. Deposit Money\n";
    cout<<"4. Quit\n";
    cout<<"\nPlease enter your choice: ";
    cin>>ch;
    return ch;
}

void ATM::withdraw(int amount) //Function for withdrawing money
{
    if(balanceamt >= amount)
    {
        balanceamt = balanceamt - amount;
        cout<<"\n\nWithdrawal Successful. Please Collect Your Money.\n";
        cout<<"Available Balance: "<<balanceamt<<"\n\n";
    }
    else
    {
        cout<<"\n\nInsufficient Balance.\n\n";
    }
}

void ATM::deposit(int amount) //Function for depositing money
{
    balanceamt = balanceamt + amount;
    cout<<"\n\nDeposit Successful.\n";
    cout<<"Available Balance: "<<balanceamt<<"\n\n";
}

void ATM::balance() //Function for checking balance
{
    cout<<"\n\nAvailable Balance: "<<balanceamt<<"\n\n";
}

int main()
{
    ATM myatm;  
    myatm.accnum = 1234; //Setting the account number and PIN code
    myatm.pincode = 5678;  
    myatm.balanceamt = 5000;  //Setting the initial balance

    int choice,amount,pin;
    cout << "\n\nWelcome to ATM Machine\n\n";
    cout << "Please enter your PIN: ";
    cin >> pin;

    if(pin != myatm.pincode)
    {
        cout<<"\n\nIncorrect PIN. Please try again.\n\n";
        return 0;
    }

    do
    {
        choice = myatm.menu();

        switch(choice)
        {
            case 1: cout<<"\n\nEnter the amount to withdraw: ";
                    cin>>amount;
                    myatm.withdraw(amount);
                    break;
            case 2: myatm.balance();
                    break;
            case 3: cout<<"\n\nEnter the amount to deposit: ";
                    cin>>amount;
                    myatm.deposit(amount);
                    break;
            case 4: cout<<"\n\nThank you for using ATM Machine.\n\n";
                    break;
            default: cout<<"\n\nInvalid Choice. Please try again.\n\n";
        }

    }while(choice != 4);

    return 0;
}