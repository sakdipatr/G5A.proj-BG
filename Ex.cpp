#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    srand(time(0));

    string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string textline;
    int st,bt;

    //cin >> bt;

    /*if(bt == 1){
        int x = rand()%26;
        cout << text[x];
    }*/
    ifstream source("1st_Q-list.text");
    while(getline(source, textline)){
        cout << textline << '\n';
    }

    return 0;
}
