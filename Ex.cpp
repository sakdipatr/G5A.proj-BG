#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string aws1[] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};

int main() {
    srand(time(0));

    ifstream qs;
    ifstream checkaws;
    ofstream dest;
    string tl;
    string tla;
    string aws;
    int st = 1;
    int bt,score;
    
    while(st == 1){
        qs.open("Question\\1st_Q-list.txt");
        dest.open("Answer_now");

        cout << "pls Enter number 1 : ";
        cin >> bt;
        cout << "-----------------------------------"<< endl;

        if(bt == 1){
            int x = rand()%26;
            cout << "your letter is "<< text[x] << endl;
            cout << "*-----------------------*" << endl;
        }
        // **countdown timer**

        while(getline(qs, tl)){
            cout << tl << ' ';
            cin >> aws;
            dest << aws << endl;
        }

        qs.close();
        dest.close();

        //**check aws**


        cout << "-----------------------------------"<< endl;

        //-------------------------------------------------------------------
        st = 0;
    }
    return 0;
}
