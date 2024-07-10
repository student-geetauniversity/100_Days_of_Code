#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string>& logs) {
    int folder = 0;
    for (const auto& log : logs) {
        if (log == "../") {
            if (folder > 0) folder--;
        } else if (log != "./") {
            folder++;
        }
    }
    return folder;
}

int main() {
    cout << "Enter logs (Please enter 'end' to finish input):\n";
    vector<string> logs;
    string log;
    while (true) {
        cin >> log;
        if (log == "end") break;
        logs.push_back(log);
    }

    int result = minOperations(logs);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
