#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
#include <string.h>
#include <stdio.h>
using namespace std;
class Display
{
public:
    void printMessageCenter(const char* message);
    void headMessage(const char *message);
    void welcomeMessage();
    void drawLine(int n, char symbol);
    void rules();
};
void Display::drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
void Display::rules()
{
    headMessage("RULES OF THE GAME");
    cout << "\n\n\n\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getchar();
}
void Display::printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    len = (78 - strlen(message))/2;
    cout << "\t\t\t";
    for(pos =0 ; pos < len ; pos++)
    {
        cout <<" ";
    }
    cout << message;
}
void Display::headMessage(const char *message)
{
    system("cls");
    cout << "\t\t\t###########################################################################";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t############             Casino Game Project in C++            ############";
    cout << "\n\t\t\t############                                                   ############";
    cout << "\n\t\t\t###########################################################################";
    cout << "\n\t\t\t---------------------------------------------------------------------------\n";
    printMessageCenter(message);
    cout << "\n\t\t\t----------------------------------------------------------------------------";
}
void Display::welcomeMessage()
{
    headMessage("www.aticleworld.com");
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =                    WELCOME                =";
    cout << "\n\t\t\t        =                      TO                   =";
    cout << "\n\t\t\t        =                 CASINO GAME               =";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getchar();
}
class PlayerInfo:public Display
{
public:
    int getGuessNumber();
    void setGuessNumber();
    void setAmount();
    float getAmount();
    int getdice();
    void updateAmount(const bool isWin);
    void setBettingAmount();
    bool isPlayerWin();
    void init();
    void displayMessageAfterPlay(const bool isWin);
    PlayerInfo():m_amount(0.00),m_bettingAmount(0.00),m_guessNumber(-1)
    {
    }
private:
    float m_amount; 
    float m_bettingAmount; 
    int m_guessNumber; 
};
void PlayerInfo::setAmount()
{
    headMessage("Set Amount");
    do
    {
        cout << "\n\nEnter Deposit amount to play game : $";
        cin >> m_amount;
        if(m_amount < 0.01f)
        {
            cout << "\n\nPlease Enter valid amount to play the Game!!";
        }
    }
    while(m_amount < 0.01f);
}
float PlayerInfo::getAmount()
{
    return m_amount;
}
int PlayerInfo::getGuessNumber()
{
    return m_guessNumber;
}
void PlayerInfo::setGuessNumber()
{
    headMessage("Set Guess Number");
    do
    {
        cout << "\n\nGuess your number to bet between 1 to 10 :";
        cin >> m_guessNumber;
        if(m_guessNumber <= 0 || m_guessNumber > 10)
            cout << "\n\nPlease check the number!! should be between 1 to 10\n"
                 <<"\nRe-enter the number\n ";
    }
    while(m_guessNumber <= 0 || m_guessNumber > 10);
}
void PlayerInfo::updateAmount(const bool isWin)
{
    m_amount = isWin ? (m_amount + (m_bettingAmount *10)): (m_amount - m_bettingAmount);
}
void PlayerInfo::setBettingAmount()
{
    headMessage("Set Bet Amount");
    do
    {
        cout <<"\n\nEnter money to bet : $";
        cin >> m_bettingAmount;
        if(m_bettingAmount > m_amount)
        {
            cout << "\n\nYour wallet amount is $" << m_amount;
            cout << "\n\nYour betting amount is more than your current balance";
        }
    }
    while(m_bettingAmount > m_amount);
}
bool PlayerInfo::isPlayerWin()
{
    const int dice = rand()%10 + 1;
    return ((dice == getGuessNumber())? true:false);
}
void PlayerInfo::init()
{
    welcomeMessage();
    srand(time(0));
    rules();
}
void PlayerInfo::displayMessageAfterPlay(const bool isWin)
{
    if(isWin)
    {
        cout << "\n\nGood Luck!! You won $" << m_bettingAmount * 10;
        cout << "\n\nNow update Amount is $" << m_amount;
    }
    else
    {
        cout << "\n\nBad Luck this time !! You lost $"<< m_bettingAmount <<"\n";
        cout << "\n\nNow update Amount is $" << m_amount;
    }
}
int main()
{
    class PlayerInfo obj_player ;
    char choice;
    obj_player.init();
    obj_player.setAmount();
    do
    {
        cout << "\n\nYour current balance is $" << obj_player.getAmount() << "\n";
        obj_player.setBettingAmount();
        obj_player.setGuessNumber();
        const bool isPlayerWin = obj_player.isPlayerWin();
        obj_player.updateAmount(isPlayerWin);
        obj_player.displayMessageAfterPlay(isPlayerWin);
        if(obj_player.getAmount() == 0.00f)
        {
            cout << "You have no money to play, Good Bye..";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }
    while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    obj_player.drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $" << obj_player.getAmount() << "\n\n";
    obj_player.drawLine(70,'=');
    return 0;
}