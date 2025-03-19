#include <iostream>
using namespace std;
int moveXR,moveXC,move0R,move0C;
int win=0,check=1;
void generate(char a[4][4]){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cout << "[ ";
            cout << a[i][j]<< " ";
            cout << "]";
        }
        cout << endl;
    }  
}
int checkdiag(char a[4][4]){
    win=0;
    if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[2][2]!='_')
        win=1;
    else if(a[3][1]==a[2][2] && a[2][2]==a[1][3] && a[2][2]!='_')
        win=1;
    return win;
}
int checkline(char a[4][4]){
    win=0;
    if(a[1][1]==a[1][2] && a[1][2]==a[1][3] && a[1][1]!='_')
        win=1;
    else if(a[2][1]==a[2][2] && a[2][2]==a[2][3] && a[2][1]!='_')
        win=2;
    else if(a[3][1]==a[3][2] && a[3][2]==a[3][3] && a[3][1]!='_')
        win=3;
    return win;
}
int checkcol(char a[4][4]){
    win=0;
    if(a[1][1]==a[2][1] && a[2][1]==a[3][1] && a[1][1]!='_')
        win=1;
    else if(a[1][2]==a[2][2] && a[2][2]==a[3][2] && a[2][2]!='_')
        win=2;
    else if(a[1][3]==a[2][3] && a[2][3]==a[3][3] && a[3][3]!='_')
        win=3;
    return win;
}
void chooseX(){
    cout << "Input move position for X:"<<endl;
    cout << "Row:";
    cin >> moveXR;
    cout << "Column:";
    cin >> moveXC;
}
void choose0(){
    cout << "Input move position for 0:"<<endl;
    cout << "Row:";
    cin >> move0R;
    cout << "Column:";
    cin >> move0C;
}
int main(){
    char a[4][4];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            a[i][j]='_';
    generate(a);
    for(int i=1;i<=9;i++){
        if(i%2==1){
            chooseX();
            while(a[moveXR][moveXC]!='_'){
                cout << "Position already occupied, choose again."<< endl;
                chooseX();
            }
            a[moveXR][moveXC]='X';
            generate(a);
            if(checkdiag(a)==1){
                cout << "Match won by: " << a[2][2] << " CONGRATULATIONS!!!!!!";
                break;
            }
            if(checkline(a)!=0){
                cout << "Match won by: " << a[win][2] << " CONGRATULATIONS!!!!!!";
                break;
            }
            if(checkcol(a)){
                cout << "Match won by: " << a[2][win] << " CONGRATULATIONS!!!!!!";
                break;
            }
            if(i==9){
                cout << "Draw! Play again.";
            }
        }
        else{
            choose0();
            while(a[move0R][move0C]!='_'){
                cout << "Position already occupied, choose again."<< endl;
                choose0();
            }
            a[move0R][move0C]='0';
            generate(a);
            if(checkdiag(a)==1){
                cout << "Match won by: " << a[2][2] << " CONGRATULATIONS!!!!!!";
                break;
            }
            if(checkline(a)!=0){
                cout << "Match won by: " << a[win][2] << " CONGRATULATIONS!!!!!!";
                break;
            }
            if(checkcol(a)){
                cout << "Match won by: " << a[2][win] << " CONGRATULATIONS!!!!!!";
                break;
            }
        }        
    }
    return 0;
}