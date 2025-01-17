#include <iostream>
#include <string>
 
using namespace std;
 
class user {
	long int mobile;
	string name;
	int billamount;
 
	public:
		user() {
			mobile = 0000000000;
			name = "xxxxxxxxxx";
			billamount = 000;
		}
 
	friend class record;
};
 
class record {
	user u[10];
	static int n;
 
	public:
		int accept() {
			cout<<"Enter the number of user(max 10): ";
			cin>>n;
 
			for(int i = 0; i < n; i++) {
				cout<<"Enter the Mobile number: ";
				cin>>u[i].mobile;
				cout<<"Enter the Name: ";
				cin>>u[i].name;
				cout<<"Enter the Bill Amount: ";
				cin>>u[i].billamount;
			}
            return n;
		}
 
		void display() {
			cout<<endl<<"MobileNumber\tCustomerName\tBillAmount"<<endl;
			for(int i = 0; i < n; i++) {
				cout<<u[i].mobile<<"\t\t"<<u[i].name<<"\t\t"<<u[i].billamount<<endl;
			}
		}
		int LinearSearch(int num) {
			for(int i = 0; i < n; i++){
				if(num == u[i].mobile) {
					cout<<"Mobile Number:"<<u[i].mobile<<endl;
					cout<<"Name:"<<u[i].name<<endl;
					cout<<"Bill Amount:"<<u[i].billamount<<endl;
                    return 1;
				}
			}
            return 0;
		}

        int IterativeBinarySearch(int num) {
            int l = 0;
            int h = n-1;
            while (l <= h) {
                int mid = (h+l)/2;
                if(num == u[mid].mobile) {
                    cout<<"Mobile Number:"<<u[mid].mobile<<endl;
					cout<<"Name:"<<u[mid].name<<endl;
					cout<<"Bill Amount:"<<u[mid].billamount<<endl;
                    return 1;
                }
                else if(num > u[mid].mobile) {
                    l = mid+1;
                }
                else {
                    h = mid-1;
                }
            }
            return 0;
        }

        int RecusrsiveBinarySearch(int num, int l = 0, int h = n-1) {
            int mid = (l+h)/2;
            if(num == u[mid].mobile) {
                cout<<"Mobile Number:"<<u[mid].mobile<<endl;
				cout<<"Name:"<<u[mid].name<<endl;
				cout<<"Bill Amount:"<<u[mid].billamount<<endl;
                return 1;
            }
            else if(num > u[mid].mobile) {
                RecusrsiveBinarySearch(num, mid+1, h);
            }
            else {
                RecusrsiveBinarySearch(num, l, mid-1);
            }
            return 0;
        }
 
};
 
int record :: n;

int main() {
	record jio;
	int total = jio.accept();
	int choice = 0;
    cout<<"1.Display data in descending order of Mobile number.\n2.Display data in ascending order of Mobile Number.\n3.Display data in ascending order of Bill Amount.\n4.Display details of a specific Mobile Number.\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice) {
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            int target = 0;
            cout<<"Enter the number to be searched: ";
            cin>>target;
            int option = 0;
            cout<<"1.Linear Search.\n2.Non-Recursive Binary Search\n3.Recursive Binary Search\n";
            cout<<"Choose the Algorithm:";
            cin>>option;
            int flag = 0;
            switch(option) {
                case 1: {
                    flag = jio.LinearSearch(target);
                    break;
                }
                case 2: {
                    flag = jio.IterativeBinarySearch(target);
                    break;
                }
                case 3: {
                    flag = jio.RecusrsiveBinarySearch(target, 0, total-1);
                    break;
                }
                default: {
                    cout<<"Invaild Algorithm"<<endl;
                    break;
                }
            }
            break;
        }
        default: {
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }	
	return 0;
}