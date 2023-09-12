#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <locale>
#include <algorithm>
#include <stdexcept>
#include <random>
using namespace std;
#define SIZE 1000

// Takes string to be encoded as input
// and its length and returns encoded string
char *base64Encoder(char input_str[], int len_str)
{
    // Character set of base64 encoding scheme
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    // Resultant string
    char *res_str = (char *)malloc(SIZE * sizeof(char));
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
    int i, j, k = 0;
    // Loop takes 3 characters at a time from
    // input_str and stores it in val
    for (i = 0; i < len_str; i += 3)
    {
        val = 0, count = 0, no_of_bits = 0;
        for (j = i; j < len_str && j <= i + 2; j++)
        {
            // binary data of input_str is stored in val
            val = val << 8;
            // (A + 0 = A) stores character in val
            val = val | input_str[j];
            // calculates how many time loop
            // ran if "MEN" -> 3 otherwise "ON" -> 2
            count++;
        }
        no_of_bits = count * 8;
        // calculates how many "=" to append after res_str.
        padding = no_of_bits % 3;
        // extracts all bits from val (6 at a time)
        // and find the value of each block
        while (no_of_bits != 0)
        {
            // retrieve the value of each block
            if (no_of_bits >= 6)
            {
                temp = no_of_bits - 6;
                // binary of 63 is (111111) f
                index = (val >> temp) & 63;
                no_of_bits -= 6;
            }
            else
            {
                temp = 6 - no_of_bits;
                // append zeros to right if bits are less than 6
                index = (val << temp) & 63;
                no_of_bits = 0;
            }
            res_str[k++] = char_set[index];
        }
    }
    // padding is done here
    for (i = 1; i <= padding; i++)
    {
        res_str[k++] = '=';
    }
    res_str[k] = '\0';
    return res_str;
}
int main()
{
    random_device rd;
    mt19937 gen(rd());
    // init var(s).
    string name;
    string webside;
    int passwardlength;
    string capitalized;
    int capitalized_int;
    string special;
    int special_int;
    string reversable;
    int reversable_int;
    // question
    cout << "Passward:>Welcome to the passward generater." << endl;
    cout << "Passward:>Please type your name:";
    cin >> name;
    cout << "Passward:>Please type the webside you are going to craete a passward for:";
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
            cout << "Passward:>Imput accepted as yes. "
                 << "Your imput is:" << capitalized;
            break;
        }
        else if (capitalized == "no")
        {
            capitalized_int = 0;
            cout << "Passward:>Imput accepted as no. "
                 << "Your imput is:" << capitalized;
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
        cout << endl
             << "Passward:>Do you want special letters? [yes/no]:";
        cin >> special;
        if (special == "yes")
        {
            special_int = 1;
            cout << "Passward:>Imput accepted as yes. "
                 << "Your imput is:" << special;
            break;
        }
        else if (special == "no")
        {
            special_int = 0;
            cout << "Passward:>Imput accepted as no. "
                 << "Your imput is:" << special;
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
        cout << endl
             << "Passward:>Do you want reversable algeoism?" << endl
             << "Passward:>Warning:Choosing yes will ignore all settings." << endl
             << "Passward:>Yor input[yes/no]:";
        cin >> reversable;
        if (reversable == "yes")
        {
            reversable_int = 0;
            // set it to one when algerism is complete.
            cout << "Passward:>Imput accepted as yes. "
                 << "Your imput is:" << reversable;
            break;
        }
        else if (reversable == "no")
        {
            reversable_int = 0;
            cout << "Passward:>Imput accepted as no. "
                 << "Your imput is:" << reversable;
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
    cout << endl
         << "Passward:>Start genrating......" << endl;
    if (reversable_int == 1)
    {
        char input_str[] = "MENON";
        int len_str;
        // calculates length of string
        len_str = sizeof(input_str) / sizeof(input_str[0]);
        // to exclude '\0' character
        len_str -= 1;
        cout << "Input string is : " << input_str << endl;
        cout << "Encoded string is : " << base64Encoder(input_str, len_str) << endl;
    }
    else
    {
        if (special_int == 1)
        {
            if (capitalized_int == 1)
            {
                // TT
                cout << "debug: specialcar=true, capitialized=ture" << endl;
                if (passwardlength % 3 == 0)
                {
                    char cch;
                    string ch;
                    unsigned seed = time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength / 3; ++i)
                    {
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 3);
                        cch = '-' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'A' + distribution(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "Your passward is :" << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else
                {
                    if (passwardlength % 3 == 1)
                    {
                        char cch;
                        string ch;
                        unsigned seed = time(0);
                        srand(seed);
                        passwardlength = passwardlength - 1;
                        cch = 'a' + rand() % 26;
                        ch = ch + cch;
                        for (int i = 1; i <= passwardlength / 3; ++i)
                        {
                            uniform_int_distribution<int> distribution(0, 25);
                            cch = 'a' + distribution(gen);
                            ch = ch + cch;
                            uniform_int_distribution<int> distribution(0, 3);
                            cch = '-' + distribution(gen);
                            ch = ch + cch;
                            uniform_int_distribution<int> distribution(0, 25);
                            cch = 'A' + distribution(gen);
                            ch = ch + cch;
                        }
                        cout << endl
                             << "Your passward is :" << ch << endl;
                        cout << endl
                             << "Debug:EOF=1" << endl;
                    }
                    else
                    {
                        char cch;
                        string ch;
                        unsigned seed = time(0);
                        srand(seed);
                        passwardlength = passwardlength - 2;
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'A' + distribution(gen);
                        ch = ch + cch;
                        for (int i = 1; i <= passwardlength / 3; ++i)
                        {
                            uniform_int_distribution<int> distribution(0, 25);
                            cch = 'a' + distribution(gen);
                            ch = ch + cch;
                            uniform_int_distribution<int> distribution(0, 3);
                            cch = '-' + distribution(gen);
                            ch = ch + cch;
                            uniform_int_distribution<int> distribution(0, 25);
                            cch = 'A' + distribution(gen);
                            ch = ch + cch;
                        }
                        cout << endl
                             << "Your passward is :" << ch << endl;
                        cout << endl
                             << "Debug:EOF=1" << endl;
                    }
                }
            }
            else
            {
                // TF
                cout << "debug: specialcar=true, capitialized=flase" << endl;
                if (passwardlength % 2 == 0)
                {
                    char cch;
                    string ch;
                    unsigned seed = time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 3);
                        cch = '-' + distribution(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "Your passward is :" << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else
                {
                    char cch;
                    string ch;
                    unsigned seed = time(0);
                    srand(seed);
                    passwardlength = passwardlength - 1;
                    uniform_int_distribution<int> distribution(0, 25);
                    cch = 'a' + distribution(gen);
                    ch = ch + cch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 3);
                        cch = '-' + distribution(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "Your passward is :" << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
            }
        }
        else
        {
            if (capitalized_int == 1)
            {
                // FT
                cout << "debug: specialcar=flase, capitialized=true" << endl;
                if (passwardlength % 2 == 0)
                {
                    char cch;
                    string ch;
                    unsigned seed = time(0);
                    srand(seed);
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'A' + distribution(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "Your passward is :" << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else
                {
                    char cch;
                    string ch;
                    unsigned seed = time(0);
                    srand(seed);
                    passwardlength = passwardlength - 1;
                    uniform_int_distribution<int> distribution(0, 25);
                    cch = 'A' + distribution(gen);
                    ch = ch + cch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'a' + distribution(gen);
                        ch = ch + cch;
                        uniform_int_distribution<int> distribution(0, 25);
                        cch = 'A' + distribution(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "Your passward is :" << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
            }
            else
            {
                // FF
                cout << "debug: specialcar=flase, capitialized=false" << endl;
                char cch;
                string ch;
                for (int i = 1; i <= passwardlength; ++i)
                {
                    uniform_int_distribution<int> distribution(0, 25);
                    cch = 'a' + distribution(gen);
                    ch = ch + cch;
                }
                cout << endl
                     << "Your passward is :" << ch << endl;
                cout << endl
                     << "Debug:EOF=1" << endl;
            }
        }
    }
    return 0;
}