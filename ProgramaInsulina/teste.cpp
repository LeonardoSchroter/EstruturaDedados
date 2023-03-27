#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(){
    string  linha= "sadasd       1231";
    int valor = stoi(linha.substr(linha.find(" "),200));
    cout << valor;
    return 1;
}