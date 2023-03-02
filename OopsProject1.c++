#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class atm
{
private:
    long int Account_Number;
    int PinNum;
    string Name;
    double Balance;
    string Moblie_no;

public:
    void setData(long int AccNum, int pin, string name, double balance, string moblie_no)
    {
        Account_Number = AccNum;
        PinNum = pin;
        Name = name;
        Balance = balance;
        Moblie_no = moblie_no;
    }
    void print(atm temp)
    {
        cout << "Acctoun Number: " << temp.Account_Number << endl;
        cout << "pin: " << temp.PinNum << endl;
    }
    long int getAcc()
    {
        return Account_Number;
    }
    int getpin()
    {
        return PinNum;
    }
    string getname()
    {
        return Name;
    }
    double getbala()
    {
        return Balance;
    }
    string getmobno()
    {
        return Moblie_no;
    }
    void cashWithD(int cash)
    {
        if (cash > 0 && cash < Balance)
        {
            Balance -= cash;
            cout << "Please Collect your Card" << endl;
            cout << "Available Cash: " << Balance << endl;
            _getch();
        }
        else
        {
            cout << "Invalid Input or Insufficient Balance" << endl;
            _getch();
        }
    }
    void ChangeModlie(string p_moblie, string n_moblie)
    {
        if (p_moblie == Moblie_no)
        {
            Moblie_no = n_moblie;
            cout << "Moblie Number Sucessfully Updated" << endl;
            _getch();
        }
        else
        {
            cout << "Incorrect Moblie Number" << endl;
            _getch();
        }
    }
    void deposit(int money)
    {
        Balance = Balance + money;
        cout << "Present Balance: " << Balance << endl;
    }
};
int main()
{
    system("cls");
    int Checkpin, Choice, i = 1;
    long int CheckAcc;
    atm user1;
    user1.setData(12345678, 6060, "ManiDeepak", 10000, "8500643168");
    while (i != 4)
    {
        system("cls");
        cout << "**Welcome to ATM**" << endl;
        cout << "Enter Accout Number: ";
        cin >> CheckAcc;
        cout << "Enetr PIN: ";
        cin >> Checkpin;
        if ((CheckAcc == user1.getAcc()) && (Checkpin == user1.getpin()))
        {
            while (1)
            {
                cout << "1.Check Balance" << endl;
                cout << "2.Cash withdraw" << endl;
                cout << "3.User Details" << endl;
                cout << "4.Update Moblie Number" << endl;
                cout << "5.Deposit" << endl;
                cout << "6.To Exit" << endl;
                cout << "Enter Your Choice: ";
                cin >> Choice;
                switch (Choice)
                {
                case 1:
                {
                    cout << "Balance: " << user1.getbala() << endl;
                    _getch();
                    break;
                }
                case 2:
                {
                    int cash;
                    cout << "Enter Amount: ";
                    cin >> cash;
                    user1.cashWithD(cash);
                    break;
                }
                case 3:
                {
                    cout << "* User Detalis*** " << endl;
                    cout << "Accout Number: " << user1.getAcc() << endl;
                    cout << "Name: " << user1.getname() << endl;
                    cout << "Balance: " << user1.getbala() << endl;
                    cout << "Moblie: " << user1.getmobno() << endl;
                    _getch();
                    break;
                }
                case 4:
                {
                    string p_moblie, n_moblie;
                    cout << "Enter Your Previous Moblie Number: ";
                    cin >> p_moblie;
                    cout << "Enter Your New Moblie Number: ";
                    cin >> n_moblie;
                    user1.ChangeModlie(p_moblie, n_moblie);
                    break;
                }
                case 5:
                {
                    int money;
                    cout << "Enter The Amount to Deposit: ";
                    cin >> money;
                    user1.deposit(money);
                    break;
                }
                case 6:
                {
                    exit(0);
                }
                default:
                {
                    cout << "Please Enter Valid Number";
                }
                }
            }
        }
        else
        {
            cout << "Your Detils are Invalid" << endl;
            _getch();
        }
        ++i;
    }
    return 0;
}