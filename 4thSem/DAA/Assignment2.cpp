#include <iostream>
#include <queue>
#include <stack>
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

        
        int visited[20];
        void DFSrec() {
            for(int i = 0; i < n; i++) {
                visited[i] = 0;
            }
            int search;
            cout<<"Enter the id for searching:";
            cin>>search;
            DFS(search);
        }

        void DFS(int v) {
            cout<<head[v]->id<<" "<<head[v]->name<<endl;
            visited[v] = 1;
            gnode *temp = head[v];
            while(temp != NULL) {
                temp = temp->next;
                if(!visited[temp->id]) {
                    DFS(temp->id);
                }
            }
        }

        void DFSnonrec(int v) {
            stack<int> s;
            for(int i = 0; i < n; i++) {
                visited[i] = 0;
            }
            s.push(v);
            visited[v]= 1;
            do {
                v = s.top();
                s.pop();
                cout<<head[v]->id<<" "<<head[v]->name<<endl;
                gnode *temp = head[v];
                while(temp != NULL) {
                    if(!visited[temp->id]) {
                        s.push(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp->next;
                }
            }while(!s.empty());
        }

        void BFS(int v) {
            queue<int> q;
            for(int i = 0; i < n; i++) {
                visited[i] = 0;
            }
            q.push(v);
            while(!q.empty()) {
                v = q.front();
                q.pop();
                cout<<head[v]->id<<" "<<head[v]->name<<endl;
                gnode *temp = head[v];
                while(temp != NULL) {
                    if(!visited[temp->id]) {
                        q.push(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp->next;
                }
            }
        }
};

int main() {
    graph friends;
    friends.create();
    friends.display();
    friends.BFS(0);

}