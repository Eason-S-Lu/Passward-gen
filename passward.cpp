#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <locale>
#include <algorithm>
#include <stdexcept>

using namespace std;
int
main ()
{
  //init var(s).
  string name;
  string webside;
  int passwardlength;
  string capitalized;
  int capitalized_int;
  string special;
  int special_int;
  string reversable;
  int reversable_int;
  //question
    cout << "Passward:>Welcome to the passward generater." << endl;
    cout << "Passward:>Please type your name:";
        cin >> name;
    cout <<"Passward:>Please type the webside you are going to craete a passward for:";
        cin >> webside;
    cout << "Passward:>Please type how long you want your passward:";
         cin >> passwardlength;
/*
while statement to detect t/f
*/
     while (true)
        {
            cout << "Passward:>Do you want to use CAPITALIZED letter? [yes/no]:";
                cin >> capitalized;
            if (capitalized == "yes")
	            {
	                capitalized_int = 1;
	                cout << "Passward:>Imput accepted as yes. " << "Your imput is:" << capitalized;
	                break;
	            }
                else if (capitalized == "no")
	                {
	                    capitalized_int = 0;
	                    cout << "Passward:>Imput accepted as no. " << "Your imput is:" << capitalized;
                        break;
                    }
                else
	                {
	                    cout << "Error:invalid input please try again.";
	                }
        }
/*
end while statement
*/
/*
while statement to detect t/f
*/
        while (true)
            {
                cout << endl << "Passward:>Do you want special letters? [yes/no]:";
                cin >> special;
                    if (special == "yes")
	                    {
	                        special_int = 1;
	                         cout << "Passward:>Imput accepted as yes. " << "Your imput is:" << special;
	                        break;
	                    }
                    else if (special == "no")
	                    {
	                        special_int = 0;
	                        cout << "Passward:>Imput accepted as no. " << "Your imput is:" << special;
	                        break;
	                    }
                    else
	                    {
	                        cout << "Passward:>Error:invalid input please try again.";
	                    }
            }
/*
end while statement
*/
/*
while statement to detect t/f
*/
        while (true)
            {
                cout << endl << "Passward:>Do you want reversable algeoism?" << endl << "Passward:>Warning:Choosing yes will ignore all settings." << endl << "Passward:>Yor input[yes/no]:";
                    cin >> reversable;
                if (reversable == "yes")
	                {
	                    reversable_int = 1;
	                    cout << "Passward:>Imput accepted as yes. " << "Your imput is:" << reversable;
	                    break;
	                }
                else if (reversable == "no")
	                {
	                    reversable_int = 0;
	                    cout << "Passward:>Imput accepted as no. " << "Your imput is:" << reversable;
	                     break;
	                }
                else
	                {
	                    cout << "Passward:>Error:invalid input please try again.";
	                }
            }
/*
-----------------------------------------------------------------------------------------------------
question complete
*/
    cout << endl << "Passward:>Start genrating......" << endl;
    if (reversable_int == 1)
    {

    }
    else
    {
         if (special_int == 1)
         {
            if (capitalized_int == 1)
            {
                //TT
                cout << "debug: specialcar=true, capitialized=ture" << endl ;
                if ( passwardlength % 3 == 0)
                {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength/3 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch+cch;
	                cch = '-' + rand()%4;
	                ch=ch+cch;
	                cch = 'A' + rand()%26;
                    ch=ch+cch;
                }
                cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                }
                else 
                {
                    if (passwardlength % 3 == 1)
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                    passwardlength=passwardlength-1;
                    cch = 'a' + rand()%26;
	                ch=ch+cch;
                    for (int i = 1; i <= passwardlength/3 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch+cch;
	                cch = '-' + rand()%4;
	                ch=ch+cch;
	                cch = 'A' + rand()%26;
                    ch=ch+cch;
                    }
                   cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                    }
                    else 
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                     passwardlength=passwardlength-2;
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
                    cch = 'A' + rand()%26;
                    ch=ch + cch;
                    for (int i = 1; i <= passwardlength/3 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
	                cch = '-' + rand()%4;
	                ch=ch + cch;
	                cch = 'A' + rand()%26;
                    ch=ch + cch;
                    }
                    cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                }
            }
            }
            else
            {
                //TF
                cout << "debug: specialcar=true, capitialized=flase" << endl ;
                    if (passwardlength % 2 == 0)
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength/2 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
	                cch = '-' + rand()%4;
	                ch=ch + cch;
                    }
                   cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                    }
                    else 
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                     passwardlength=passwardlength-1;
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
                    for (int i = 1; i <= passwardlength/2 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
	                cch = '-' + rand()%4;
	                ch=ch + cch;
                    }
                    cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                    }
            }
         }
         else
         {
            if (capitalized_int == 1)
            {
               //FT
               cout << "debug: specialcar=flase, capitialized=true" << endl ;
                  if (passwardlength % 2 == 0)
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength/2 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
	                cch = 'A' + rand()%26;
	                ch=ch + cch;
                    }
                    cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                    }
                    else 
                    {
                    char cch;
                    string ch; 
                    unsigned seed= time(0);
                    srand(seed);
                     passwardlength=passwardlength-1;
                    cch = 'A' + rand()%26;
	                ch=ch + cch;
                    for (int i = 1; i <= passwardlength/2 ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
	                cch = 'A' + rand()%26;
	                ch=ch + cch;
                    }
                    cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
                    }   
            }
            else 
            {
                //FF
                cout << "debug: specialcar=flase, capitialized=false" << endl ;
                char cch;
                string ch;
                 for (int i = 1; i <= passwardlength ; ++i) {
                    cch = 'a' + rand()%26;
	                ch=ch + cch;
                    }
                    cout << endl << "Your passward is :" << ch << endl ;
                    cout << endl << "Debug:EOF=1";
            }
            }
         }
    return 0;
}