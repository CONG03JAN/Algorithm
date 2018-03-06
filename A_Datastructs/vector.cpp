// Vector Example

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        //int tmp;
        //cin >> tmp;
        //v.push_back(tmp);
        cin >> v[i];
    }
    //v[4] = 1;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;

    v.erase(v.begin() + 1, v.begin() + 2);

    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }

    v.clear();
    cout << "Clear Ok" << endl;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
