#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
    int vertex;
        Matrix() {
            cout<<"Enter the number of cities :";
            cin>>vertex;
        }
        
        vector<vector<int>> Adj() {
            int n = vertex;
            vector<vector<int>> arr(n, vector<int>(n));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) {
                        arr[i][j] = 0;
                        break;
                    }
                    else {
                        string conn;
                        cout<<"Is city"<<i<<" and city "<<j<<" connected? (yes/no): ";
                        cin>>conn;
                        

                        if(conn == "yes") {
                            int cost;
                            cout<<"Enter the cost of connection: ";
                            cin>>cost;
                            arr[i][j] = cost;
                            arr[j][i] = cost;
                        }

                        else{
                            arr[i][j] = 0;
                        }
                    }
                }
            }
            return arr;
        }
      };

class Prim {

};


void display(vector<vector<int>> arr, int len) {
    for(int i =0; i < len; i++) {
        for(int j =0; j < len; j++) {
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }
}


int main() {
    Matrix m;
    vector<vector<int>> graph = m.Adj();
    display(graph, m.vertex);
}