#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<char> findClosure(set<char> attrs, vector<pair<set<char>, set<char>>> fds) {
    set<char> result = attrs;
    bool changed = true;

    while (changed) {
        changed = false;

        for (auto fd : fds) {
            
            bool ok = true;
            for (char c : fd.first) {
                if (result.find(c) == result.end()) {
                    ok = false;
                    break;
                }
            }

            
            if (ok) {
                int before = result.size();
                for (char c : fd.second) {
                    result.insert(c);
                }
                if (result.size() > before)
                    changed = true;
            }
        }
    }

    return result;
}

void printSet(set<char> s) {
    cout << "{ ";
    for (char c : s)
        cout << c << " ";
    cout << "}" << endl;
}

int main() {

   
    vector<pair<set<char>, set<char>>> fds;
    fds.push_back({{'A'}, {'B'}});
    fds.push_back({{'B','C'}, {'D'}});
    fds.push_back({{'D'}, {'E'}});
    fds.push_back({{'E'}, {'A'}});

    set<char> A = {'A'};
    set<char> Aplus = findClosure(A, fds);

    cout << "A+ = ";
    printSet(Aplus);


    set<char> BC = {'B','C'};
    set<char> BCplus = findClosure(BC, fds);

    cout << "BC+ = ";
    printSet(BCplus);

    
    set<char> all = {'A','B','C','D','E'};

    if (Aplus == all)
        cout << "A is a candidate key" << endl;
    else
        cout << "A is NOT a candidate key" << endl;

    return 0;
}