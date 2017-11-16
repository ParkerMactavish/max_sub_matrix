#include <iostream>

using namespace std;

int main()
{
    int width=0, length=0;
    while(cin>>width){
        cin>>length;
        int matrix[width][length];
        for(int i=0; i<width; i++)
            for(int j=0; j<length; j++)
                cin>>matrix[i][j];
        for(int i=0; i<width; i++){
            for(int j=0; j<length; j++){
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
