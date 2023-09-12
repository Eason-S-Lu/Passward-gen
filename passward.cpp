#include <iostream>
#include <cstring>
#include <string>
#include <random>

using namespace std;

char *safeStrcat(const char *s1, const char *s2){
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL){
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
static const char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char *base64Encoder(const char input_str[], int len_str){
    char *res_str = (char *)malloc(((len_str * 4 / 3) + 4) * sizeof(char));
    if (res_str == NULL){
        return NULL;
    }
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
    int i, j, k = 0;
    for (i = 0; i < len_str; i += 3){
        val = 0, count = 0, no_of_bits = 0;
        for (j = i; j < len_str && j <= i + 2; j++){
            val = val << 8;
            val = val | input_str[j];
            count++;
        }
        no_of_bits = count * 8;
        padding = no_of_bits % 3;
        while (no_of_bits != 0)
        {
            if (no_of_bits >= 6){
                temp = no_of_bits - 6;
                index = (val >> temp) & 63;
                no_of_bits -= 6;
            }
            else{
                temp = 6 - no_of_bits;
                index = (val << temp) & 63;
                no_of_bits = 0;
            }
            res_str[k++] = char_set[index];
        }
    }
    for (i = 1; i <= padding; i++){
        res_str[k++] = '=';
    }
    res_str[k] = '\0';
    return res_str;
}
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution_26(0, 25);
    uniform_int_distribution<int> distribution_3(0, 3);
    string name;
    string webside;
    int passwardlength;
    string capitalized;
    int capitalized_int;
    string special;
    int special_int;
    string reversable;
    int reversable_int;
    cout << "Passward:>Welcome to the passward generater." << endl;
    cout << "Passward:>Please type your name:";
    cin >> name;
    cout << "Passward:>Please type the webside you are going to craete a passward for:";
    cin >> webside;
    cout << "Passward:>Please type how long you want your passward:";
    cin >> passwardlength;
    while (true){
        cout << "Passward:>Do you want to use CAPITALIZED letter? [yes/no]:";
        cin >> capitalized;
        if (capitalized == "yes"){
            capitalized_int = 1;
            cout << "Passward:>Imput accepted as yes. "
                 << "Your imput is:" << capitalized;
            break;
        }
        else if (capitalized == "no"){
            capitalized_int = 0;
            cout << "Passward:>Imput accepted as no. "
                 << "Your imput is:" << capitalized;
            break;
        }
        else{
            cout << "Error:invalid input please try again.";
        }
    }
    while (true)
    {
        cout << endl
             << "Passward:>Do you want special letters? [yes/no]:";
        cin >> special;
        if (special == "yes"){
            special_int = 1;
            cout << "Passward:>Imput accepted as yes. "
                 << "Your imput is:" << special;
            break;
        }
        else if (special == "no"){
            special_int = 0;
            cout << "Passward:>Imput accepted as no. "
                 << "Your imput is:" << special;
            break;
        }
        else{
            cout << "Passward:>Error:invalid input please try again.";
        }
    }
    while (true)
    {
        cout << endl
             << "Passward:>Do you want reversable algeoism?" << endl
             << "Passward:>Warning:Choosing yes will ignore all settings." << endl
             << "Passward:>Yor input[yes/no]:";
        cin >> reversable;
        if (reversable == "yes"){
            reversable_int = 1;
            // set it to one when algerism is complete.
            cout << "Passward:>Imput accepted as yes."
                 << "Your imput is:" << reversable;
            break;
        }
        else if (reversable == "no"){
            reversable_int = 0;
            cout << "Passward:>Imput accepted as no."
                 << "Your imput is:" << reversable;
            break;
        }
        else{
            cout << "Passward:>Error:invalid input please try again.";
        }
    }
    cout << endl
         << "Passward:>Start genrating......" << endl;
    if (reversable_int == 1)
    {
        const char *sname = name.c_str();
        const char *surl = webside.c_str();
        char *combined_str = safeStrcat(sname, "@");
        if (combined_str != NULL){
            combined_str = safeStrcat(combined_str, surl);
            char *encoded_str = base64Encoder(combined_str, strlen(combined_str));
            if (encoded_str != NULL){
                printf("Encoded string: %s\n", encoded_str);
                free(encoded_str);
            }
            else{
                printf("Memory allocation failed for encoded string.\n");
            }
            free(combined_str);
        }
        else{
            printf("Memory allocation failed for combined string.\n");
        }
    }
    else{
        if (special_int == 1){
            if (capitalized_int == 1){
                cout << "debug: specialcar=true, capitialized=ture" << endl;
                if (passwardlength % 3 == 0){
                    char cch;
                    string ch;
                    for (int i = 1; i <= passwardlength / 3; ++i)
                    {
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = '-' + distribution_3(gen);
                        ch = ch + cch;
                        cch = 'A' + distribution_26(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "  Your passward is :      " << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else
                {
                    if (passwardlength % 3 == 1){
                        char cch;
                        string ch;
                        passwardlength = passwardlength - 1;
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        for (int i = 1; i <= passwardlength / 3; ++i)
                        {
                            cch = 'a' + distribution_26(gen);
                            ch = ch + cch;
                            cch = '-' + distribution_3(gen);
                            ch = ch + cch;
                            cch = 'A' + distribution_26(gen);
                            ch = ch + cch;
                        }
                        cout << endl
                             << "  Your passward is :      " << ch << endl;
                        cout << endl
                             << "Debug:EOF=1" << endl;
                    }
                    else{
                        char cch;
                        string ch;
                        passwardlength = passwardlength - 2;
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = 'A' + distribution_26(gen);
                        ch = ch + cch;
                        for (int i = 1; i <= passwardlength / 3; ++i)
                        {
                            cch = 'a' + distribution_26(gen);
                            ch = ch + cch;
                            cch = '-' + distribution_3(gen);
                            ch = ch + cch;
                            cch = 'A' + distribution_26(gen);
                            ch = ch + cch;
                        }
                        cout << endl
                             << "  Your passward is :      " << ch << endl;
                        cout << endl
                             << "Debug:EOF=1" << endl;
                    }
                }
            }
            else
            {
                cout << "debug: specialcar=true, capitialized=flase" << endl;
                if (passwardlength % 2 == 0){
                    char cch;
                    string ch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = '-' + distribution_3(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "  Your passward is :      " << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else{
                    char cch;
                    string ch;
                    passwardlength = passwardlength - 1;
                    cch = 'a' + distribution_26(gen);
                    ch = ch + cch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = '-' + distribution_3(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "  Your passward is :      " << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
            }
        }
        else{
            if (capitalized_int == 1)
            {
                cout << "debug: specialcar=flase, capitialized=true" << endl;
                if (passwardlength % 2 == 0){
                    char cch;
                    string ch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = 'A' + distribution_26(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "  Your passward is :      " << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
                else{
                    char cch;
                    string ch;
                    passwardlength = passwardlength - 1;
                    cch = 'A' + distribution_26(gen);
                    ch = ch + cch;
                    for (int i = 1; i <= passwardlength / 2; ++i)
                    {
                        cch = 'a' + distribution_26(gen);
                        ch = ch + cch;
                        cch = 'A' + distribution_26(gen);
                        ch = ch + cch;
                    }
                    cout << endl
                         << "  Your passward is :      " << ch << endl;
                    cout << endl
                         << "Debug:EOF=1" << endl;
                }
            }
            else{
                cout << "debug: specialcar=flase, capitialized=false" << endl;
                char cch;
                string ch;
                for (int i = 1; i <= passwardlength; ++i)
                {
                    cch = 'a' + distribution_26(gen);
                    ch = ch + cch;
                }
                cout << endl
                     << "  Your passward is :      " << ch << endl;
                cout << endl
                     << "Debug:EOF=1" << endl;
            }
        }
    }
    return 0;
}