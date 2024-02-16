#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int st,bt;
    cin >> bt;
    srand(time(0));
    string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    if(bt == 1 and st == 0){
        int x = rand()%26;
        cout << text[x];
    }

    return 0;
}
