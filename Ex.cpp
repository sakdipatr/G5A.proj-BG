#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string ques[3] = {"1st_Q-list.txt","2nd_Q-list.txt","3rd_Q-list.txt"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};
string aws2[10] = {"Body parts.txt","Colors.txt","Programming Languages.txt","Gemstones.txt","Disney Character Names.txt","Video Games.txt","Job titles.txt","Holidays.txt","Celebrities.txt","Indoors and Outdoor Hobbies.txt"};
string aws3[10] = {"Sports.txt","Vegetables.txt","Subjects.txt","Construction.txt","Thing in a museum.txt","Board Games.txt","Ice cream flavors.txt","Clothing Brands.txt","Fruits.txt","Car brands.txt"};

int main() {
    srand(time(0));

    ifstream qs,checkaws;
    ofstream dest;
    string tl,aws;
    vector<string> ans_arch;
    string q_ans[10];
    int st = 1;
    int bt = 0;
    int sec = 0;
    int score = 0;

    while(st == 1){
        int q = rand()%3;

        if( q == 0 ){
            for(int i = 0; i < 10; i++ ){
                q_ans[i] = aws1[i];
            }
        }else if( q == 1 ){
            for(int i = 0; i < 10; i++ ){
                q_ans[i] = aws2[i];
            }
        }else if( q == 2 ){
            for(int i = 0; i < 10; i++ ){
                q_ans[i] = aws3[i];
            }
        }
        
        qs.open("Question\\"+ques[q]);

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

        cout << "Enter time (sec) : ";
        cin >> sec;

        while(getline(qs, tl)){
            cout << tl << ' ';
            cin >> aws;
            ans_arch.push_back(aws);
        }

        qs.close();

        cout << endl <<"*-----------------------*" << endl;
        cout << endl ;

        for(int i = 0 ; i < 10 ; i ++){
            cout << ans_arch[i] <<endl;
        }

        for(int i = 0; i < 10; i++){
            checkaws.open("Answer\\"+q_ans[i]);
            cout << i+1 << ". ";
            while(getline(checkaws,tl)){
                if(tl == ans_arch[i]){
                    cout << tl << " +1score" << " ";
                    score++ ;
                }
            }
            checkaws.close();
        }

        cout << endl << "*-----------------------*" << endl;
        cout << endl <<"your score is : " << score << endl;
        cout << endl << "-----------------------------------"<< endl;

        st = 0;
    }
    return 0;
}
