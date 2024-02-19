#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};

int main() {
    srand(time(0));

    ifstream qs,checkaws,aws_now;
    ofstream dest;
    string tl,aws,tl_now;
    int st = 1;
    int bt = 0;
    int score = 0;

    while(st == 1){
        qs.open("Question\\1st_Q-list.txt");
        dest.open("Answer_now.txt");

        cout << "pls Enter number 1 : ";
        cin >> bt;
        cout << "-----------------------------------"<< endl;

        if(bt == 1){
            int x = rand()%26;
            cout <<  "*-----------------------*" << endl;
            cout << endl << "your letter is "<< text[x] << endl;
            cout << endl << "*-----------------------*" << endl;
            cout << endl ;
        }
        // **countdown timer**

        while(getline(qs, tl)){
            cout << tl << ' ';
            cin >> aws;
            dest << aws << endl;
        }

        qs.close();
        dest.close();

        cout << endl <<"*-----------------------*" << endl;
        cout << endl ;

        for(int i = 0; i < 10 ; i++){
            aws_now.open("Answer_now.txt");
            checkaws.open("Answer\\"+aws1[i]);
            cout << i+1 << ". ";
            while(getline(aws_now,tl_now)){
                while(getline(checkaws,tl)){
                    if(tl == tl_now){
                        cout << tl_now << " +1score" << " ";
                        score++ ;
                    }
                }
            }
            checkaws.close();
            aws_now.close();
            
        }

        cout << endl << "*-----------------------*" << endl;
        cout << endl <<"your score is : " << score << endl;

        cout << endl << "-----------------------------------"<< endl;

        //-------------------------------------------------------------------
        st = 0;
    }
    return 0;
}
