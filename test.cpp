#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <locale>
#include <algorithm>
#include <stdexcept>
using namespace std;
int main (){
    string name;
    string webside;
    string temp1;
    string temp2;
    string input;
    string output;
    name = "john";
    webside = "outlook.com";
    input = name + "-" + webside;
    cout << input;
}