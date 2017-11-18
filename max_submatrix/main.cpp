#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    int width=0, length=0, front_x, end_x, front_y, end_y, tmp_front_y, tmp_end_y, overall_max, local_max;
    char raw_input[11];
    cout<<"Input \'Q\' to quit"<<endl<<"Or type the width of the matrix"<<endl;
    while(cin>>raw_input&&(raw_input[0]!='q'&&raw_input[0]!='Q')){
        width=0;
        length=0;
        for(int i=0; raw_input[i]!=0; i++){
            width*=10;
            width+=raw_input[i]-'0';
        }
        cout<<"Type the length of the matrix"<<endl;
        cin>>raw_input;
        for(int i=0; raw_input[i]!=0; i++){
            length*=10;
            length+=raw_input[i]-'0';
        }
        vector<vector<int> > matrix(length, vector<int>(width, 0));
        vector<int> one_dimension(length, 0);
        cout<<"Would you like to enter the values in the matrix?"<<endl;
        cin>>raw_input;
        while(raw_input[0]!='y'&&raw_input[0]!='Y'&&raw_input[0]!='N'&&raw_input[0]!='n'){
            cout<<"Please enter \'Y\' for yes, and \'N\' for no."<<endl;
            cin>>raw_input;
        }
        if(raw_input[0]=='y'||raw_input[0]=='Y'){
            cout<<"Please type the "<<width*length<<" numbers below:"<<endl;
            for(int i=0; i<length; i++)
                for(int j=0; j<width; j++)
                    cin>>matrix[i][j];
        }
        else{
            srand(time(NULL));
            for(int i=0; i<length; i++)
                for(int j=0; j<width; j++)
                    matrix[i][j]=pow(-1, rand())*rand();
        }
        cout<<"Original matrix:"<<endl;
        for(int i=0; i<length; i++){
            for(int j=0; j<width; j++) cout<<setw(10)<<left<<matrix[i][j];
            cout<<endl;
        }
        overall_max=-10000000;
        for(int i=1; i<=width; i++){
            for(int j=0; j<i; j++){
                for(int k=0; k<length; k++) one_dimension[k]=0;
                for(int k=0; k<length; k++){
                    for(int l=j; l<i; l++) one_dimension[k]+=matrix[k][l];
                }
                local_max=one_dimension[0];
                tmp_front_y=0;
                tmp_end_y=1;
                for(int k=1; k<length; k++){
                    if(local_max+one_dimension[k]>one_dimension[k]){
                        local_max+=one_dimension[k];
                        tmp_end_y++;
                    }
                    else{
                        local_max=one_dimension[k];
                        tmp_front_y=k;
                        tmp_end_y=k+1;
                    }
                    if(overall_max<local_max){
                        overall_max=local_max;
                        front_x=j;
                        end_x=i;
                        front_y=tmp_front_y;
                        end_y=tmp_end_y;
                    }
                }
            }
        }
        cout<<"Maximum Submatrix:"<<endl;
        for(int i=front_y; i<end_y; i++){
            for(int j=front_x; j<end_x; j++) cout<<setw(10)<<left<<matrix[i][j];
            cout<<endl;
        }
         cout<<"Input \'Q\' to quit"<<endl<<"Or type the width of the matrix"<<endl;
    }
    return 0;
}
