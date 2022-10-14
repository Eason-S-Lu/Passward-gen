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
  cout <<
    "Passward:>Please type the webside you are going to craete a passward for:";
  cin >> webside;
  cout << "Passward:>Please type how long you want your passward:";
  cin >> passwardlength;
  while (true)
    {
      cout <<
	"Passward:>Do you want to use CAPITALIZED letter? [yes/no]:";
      cin >> capitalized;
      if (capitalized == "yes")
	{
	  capitalized_int = 1;
	  cout << "Passward:>Imput accepted as yes. " << "Your imput is:" <<
	    capitalized;
	  break;
	}
      //end if
      else if (capitalized == "no")
	{
	  capitalized_int = 0;
	  cout << "Passward:>Imput accepted as no. " << "Your imput is:" <<
	    capitalized;
	  break;
	}
      //end else if
      else
	{
	  cout << "Error:invalid input please try again.";
	}
      //end else
    }
  //end while
  while (true)
    {
      cout << endl << "Passward:>Do you want special letters? [yes/no]:";
      cin >> special;
      if (special == "yes")
	{
	  special_int = 1;
	  cout << "Passward:>Imput accepted as yes. " << "Your imput is:" <<
	    special;
	  break;
	}
      //end if
      else if (special == "no")
	{
	  special_int = 0;
	  cout << "Passward:>Imput accepted as no. " << "Your imput is:" <<
	    special;
	  break;
	}
      //end else if
      else
	{
	  cout << "Passward:>Error:invalid input please try again.";
	}
    }
  //end else
  //end while
  while (true)
    {
      cout << endl << "Passward:>Do you want reversable algeoism?" << endl <<
	"Passward:>Warning:Choosing yes will ignore all settings." << endl <<
	"Passward:>Yor input[yes/no]:";
      cin >> reversable;
      if (reversable == "yes")
	{
	  reversable_int = 1;
	  cout << "Passward:>Imput accepted as yes. " << "Your imput is:" <<
	    reversable;
	  break;
	}
      //end if
      else if (reversable == "no")
	{
	  reversable_int = 0;
	  cout << "Passward:>Imput accepted as no. " << "Your imput is:" <<
	    reversable;
	  break;
	}
      //end else if
      else
	{
	  cout << "Passward:>Error:invalid input please try again.";
	}
    }
  cout << endl << "Passward:>Start genrating......" << endl;
  if (reversable_int == 1)
    {
      string procress_string;
      procress_string = name + "-" + webside;
      cout << "debug:" << procress_string;
	  cout <<endl << "debug:eof=1";
    }
  else
    {
      if (special_int == 1)
	{
	  if (capitalized_int == 1)
	    {
	      //tt
		  cout << "debug: specialcar=true, capitialized=ture" << endl ;
	 	  cout <<endl << "debug:eof=1";

	    }
	  else
	    {
	      //tf
		   cout << "debug: specialcar=true, capitialized=flase" << endl ;
		   cout <<endl << "debug:eof=1";
	    }
	}
      else
	{
	  if (capitalized_int == 1)
	    {
	      //ft
		   cout << "debug: specialcar=flase, capitialized=true" << endl ;
		   cout <<endl << "debug:eof=1";
	    }
	  else
	    {
	      //ff
		  cout << "debug: specialcar=flase, capitialized=false" << endl ;
		   char cch;
    string ch; 
    unsigned seed= time(0);
    srand(seed);
     for (int i = 1; i <= passwardlength; ++i) {
    cch = 'a' + rand()%26;
    ch=ch + cch;
    }
    cout << endl << "Your passward is :" << ch <<endl;
		  cout <<endl << "debug:eof=1";
	    }
	}
    }
  return 0;
}
