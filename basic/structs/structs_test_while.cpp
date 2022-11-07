#include <iostream>
#include <cstring>

#define endl "\n"
using namespace std;
static int n3 = 0;

void function(char s[]) {
    s[n3++] += 2;
}

int main() {
    char str[10] = "abcd";
    cout << str << endl;
    int n1 = 1, n2 = strlen(str);
    cout << n2 << endl;
    while (n1++ < n2)
        function(str);
    cout << n1 << endl;
    cout << n3 << endl;
    cout << str << endl;
    return 0;
}