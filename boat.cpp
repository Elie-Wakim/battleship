#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <cctype>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
using namespace std;
void show(string arrays[6][6]){
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << arrays[i][j];
        }
        cout << endl;
    }
}
void touppers(string& str){
    transform(str.begin(),str.end(),str.begin(),[](unsigned char c){return toupper(c);});
}
bool hit(int row,int col,int cpurow[],int cpuol[]){
for (int i = 0; i < 3; i++){
    if (row == cpurow[i] && cpuol[i] == col)
{
    return true;
}
}
return false;
}
bool found(int randrow[3],int randcol[3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if (randrow[i]==randrow[j]||randcol[i]==randcol[j])
            {
                return true;
            }   
        }
    }return false;
}
void random(int randrow[3],int randcol[3]){
    for (int i = 0; i < 3; i++)
    {
       randrow[i]=1+rand()%5;
       randcol[i]=1+rand()%5;
    }
    while (found(randrow,randcol))
       {
        random(randrow,randcol);
       }
}
int main(){
    srand(time(0));
    string ans="y";
    while (ans=="y")
    {
    string row, col, arrays[6][6] = {{" ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 "},
                    {"A", " # ", " # ", " # ", " # ", " # "},
                    {"B", " # ", " # ", " # ", " # ", " # "},
                    {"C", " # ", " # ", " # ", " # ", " # "},
                    {"D", " # ", " # ", " # ", " # ", " # "},
                    {"E", " # ", " # ", " # ", " # ", " # "}};
    int hp=10,cpurow[3],cpucol[3],count=0;
    random(cpurow,cpucol);
    show(arrays);
    while (hp>0)
    {
       int indexrow = -1, indexcol = -1;
    cout << "Pick a row \"A-E\":"; cin >> row; 
    cout << "Pick a column\"1-5\":"; cin >> col;
    touppers(row);
    for (int i = 0; i < 6; i++)
    {
        if (row==arrays[i][0])
        {
            indexrow=i;
        }
        if (col==arrays[0][i].substr(1,1))
        {
            indexcol=i;
        }
    }if (indexcol == -1 || indexrow == -1)
    {
        cout << "Invalid Row or Column try again\n";
    }else if(arrays[indexcol][indexrow]==" X " || arrays[indexcol][indexrow]==" O " ){
        cout << "You have already chose this row and column\n";
    }
    else{
    if (hit(indexrow,indexcol,cpurow,cpucol))
    {
        arrays[indexrow][indexcol]=" O ";
        cout << GREEN << "You got a hit!\n" << RESET;
        count++;
    }else{
    arrays[indexrow][indexcol]=" X ";
    hp--;
    cout << RED << "You Have Missed you have, " << hp << " hp left\n" << RESET;
    }
    show(arrays);
    if (hp==0)
    {
        cout << "The rows and columns were: \n";
        for (int i = 0; i < 3; i++)
        {
            cout << arrays[cpurow[i]][0]<< arrays[0][cpucol[i]]<<endl;
        }
    }
    if (count == 3)
    {
        cout << GREEN << "You have won!" << RESET << endl;
        break;
    }
}
} cout << "Try again? y/n \n"; cin >>ans;
}
}