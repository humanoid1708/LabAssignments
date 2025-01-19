#include <iostream>
#include <queue>
using namespace std;

class gnode {
    int id;
    string name;
    gnode *next = NULL;
    friend class graph;
};

class graph {
    int n;
    gnode *head[20];
    
    public:
        graph() {
            cout<<"Enter the number of users: ";
            cin>>n;
            for(int i = 0; i < n; i++) {
                head[i] = new gnode;
                head[i]->id = i;
                cout<<"Enter the name of "<<i+1<<" user:";
                cin>>head[i]->name;
                head[i]->next = NULL;
            }
        }

        void create() {
            for(int i = 0; i < n; i++) {
                string choice = "yes";
                do {
                    int v;
                    cout<<"Enter ID of a user, friend with "<<head[i]->name<<" :";
                    cin>>v;
                    if(v == i) {
                        cout<<"Selfloop is not possible";
                    }
                    else {
                        gnode *temp = head[i];
                        while(temp->next != NULL) {
                            temp = temp->next;
                        }
                        gnode *curr = new gnode;
                        curr->id = v;
                        curr->name = head[v]->name;
                        curr->next = NULL;
                        temp->next = curr;
                        
                    }
                    cout<<"Any more friends? (yes/no):";
                    cin>>choice;
                }
                while(choice == "yes");
            }
        }

        void display() {
            for(int i = 0; i < n; i++) {
                gnode *temp = head[i];
                while(temp != NULL) {
                    cout<<temp->id<<"\t"<<temp->name<<endl;
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        /*void BFS(int v) {
            int visited[n];
            for (int i = 0; i < n; i++) {
                visited[i] = 0;
            }
            queue<int> q;
            q.push(v);
            while(!q.empty()) {
            }
        }*/

};

int main() {
    graph friends;
    friends.create();
    friends.display();
}