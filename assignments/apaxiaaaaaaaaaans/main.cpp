/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
|                                                  |
|     Code to solve kattis problem "Apaxiaaans"    |
|    https://open.kattis.com/problems/apaxiaaans   |
|               Written by June West               |
|                                                  |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/


#include <iostream>
#include <cassert>

using namespace std;

string unApaxify(string);
void test();

int main(int argc, char* argv[]) {
    if(argc > 1 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    string name = "";
    cin >> name;
    name = unApaxify(name);
    cout << name << endl;
}

string unApaxify(string name) {
    for(size_t i = 0; i < name.length()-1; i++) {
        
        if(name[i] == name[i+1]) {
            name.erase(i,1);
            i--;
            // cout << "DEBUG: i = " << i << endl;            
        } else {
            // cout << "DEBUG: i = " << i << endl;
            continue;
        }
        
    }
    return name;
}

void test() {
    string testCase = "rooooooooobert";
    assert(unApaxify(testCase) == "robert");
    testCase = "roooooobertapalaxxxxios";
    assert(unApaxify(testCase) == "robertapalaxios");
    testCase = "robert";
    assert(unApaxify(testCase) == "robert");
    cout << "Test cases passed." << endl;
}