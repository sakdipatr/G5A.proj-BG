#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std::chrono;
using namespace std;

char letters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ques[3] = {"1st_Q-list.txt","2nd_Q-list.txt","3rd_Q-list.txt"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};
string aws2[10] = {"Body parts.txt","Colors.txt","Programming Languages.txt","Gemstones.txt","Disney Character Names.txt","Video Games.txt","Job titles.txt","Holidays.txt","Celebrities.txt","Indoors and Outdoor Hobbies.txt"};
string aws3[10] = {"Sports.txt","Vegetables.txt","Subjects.txt","Construction.txt","Thing in a museum.txt","Board Games.txt","Ice cream flavors.txt","Clothing Brands.txt","Fruits.txt","Car brands.txt"};
int r =1;

void Countdown_Timer(int seconds){
    if(seconds <= 0){
        cout << endl << "Time's up." << endl;
        ::r = 0;
        return;
    }
    if(seconds==10){
        cout << seconds << "SECOND LEFT!!!!" << endl;
    }
    this_thread::sleep_for(std::chrono::seconds(1));
    Countdown_Timer(seconds -1);
}

int main() {
    srand(time(0));

    ifstream qs,checkaws;
    string tl,aws,name;
    vector<string> ans_arch;
    vector<string> q_ans;
    vector<string> name_ply;
    int st = 1;
    int bt = 0;
    int sec = 0;
    int score = 0;
    int n_name = 0;

    while(st == 1){

        cout << "pls Enter number 1 : ";
        cin >> bt;
        cout << "-----------------------------------"<< endl;

        if(bt == 1){
            cout << "player = ";
            cin >> n_name;
            for (int i = 0 ; i < n_name; i++){
                cout << "name player " << i+1 << " = ";
                cin >> name;
                name_ply.push_back(name);
            }
            int x = rand()%26;
            cout <<  "*-----------------------*" << endl;
            cout << endl << "your letter is "<< letters[x] << endl;
            cout << endl << "*-----------------------*" << endl;
            cout << endl ;
            cout << "Enter time (sec) : ";
            cin >> sec;
            cout << endl << "*-----------------------*" << endl;
            thread taskCD(Countdown_Timer, sec);
            // cd timer
            for(int n = 0 ; n < n_name ; n++){
                cout << "round "<< n+1 << " player : "<< name_ply[n] << endl;
                cout << endl;

                int q = rand()%3;
                if( q == 0 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws1[i]);
                    }
                }else if( q == 1 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws2[i]);
                    }
                }else if( q == 2 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws3[i]);
                    }
                }

                qs.open("Question\\"+ques[q]);
                        
                //พิมพ์คำตอบ
                while(getline(qs, tl)){
                    cout << tl << ' ';
                    cin >> aws;
                    ans_arch.push_back(aws);
                    if(r != 1) break;
                }

                qs.close();

                cout << endl <<"*-----------------------*" << endl;
                cout << endl ;

                //เช็คคะแนน
                for(int i = 0; i < 10; i++){
                    checkaws.open("Answer\\"+q_ans[i]);
                    cout << i+1 << ". ";
                    while(getline(checkaws,tl)){
                        if(tl == ans_arch[i]){
                            cout << ans_arch[i] << " +1score" << " ";
                            score++ ;
                        }
                    }
                    checkaws.close();
                }

                cout << endl << "*-----------------------*" << endl;
                cout << endl << name_ply[n]<<" score is : " << score << endl << sec << " " << r << " ";
                cout << endl << "-----------------------------------"<< endl;

                score = 0;
            }
        }
    st = 0;
    }
    return 0;
}