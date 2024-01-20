#include <iostream>
#include <list>
using namespace std;

list<int> insert(list<int>& l){
    int el;
    cin >> el;
    l.push_front(el);
    cout << el << " inserted!" << endl;

    return l;
}

list<int> remove(list<int>& l){
    cout << l.front() << " deleted." << endl;
    l.pop_front();

    return l;
}

void show(list<int>& l){
    if(l.size() == 0) cout << "Stack is empty!" << endl;
    else {
        cout << "Elements in the stack are: ";
        for(int i : l){
            cout << i << " ";
        } cout << endl;
    }
}

int main(){
    list<int> l;
    while(1){
        int choice;
        cin >> choice;

        switch(choice){
            case 1: insert(l);
                    break;
            
            case 2: remove(l);
                    break;

            case 3: show(l);
                    break;
            
            case 4: exit(0);
            
            default: cout << "Invalid Choice!" << endl;
        }
    }
}