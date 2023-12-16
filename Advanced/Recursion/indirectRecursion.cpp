#include <iostream>
using namespace std;
// Forward declarations
bool odd(int n);

bool even(int n) {
    if (n == 0)
        return true;
    else
        return odd(n - 1);
}

bool odd(int n) {
    if (n == 0)
        return false;
    else
        return even(n - 1);
}

int main() {
    int num = 5;

    cout << "Is " << num << " even? " << (even(num) ? "Yes" : "No") << endl;
    cout << "Is " << num << " odd? " << (odd(num) ? "Yes" : "No") << endl;

    return 0;
}
