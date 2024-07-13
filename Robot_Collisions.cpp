#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> Robots_health(vector<int>& positions, vector<int>& healths, string& direction) {
        int n = positions.size();
        vector<Robot> vals;
        for (int i = 0; i < n; i++) {
            vals.push_back({positions[i], healths[i], direction[i], i});
        }
        sort(vals.begin(), vals.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        vector<Robot> stack;
        for (auto& robot : vals) {
            if (robot.direction == 'R') {
                stack.push_back(robot);
                continue;
            }

            bool gone = false;

            while (!stack.empty() && stack.back().health <= robot.health && stack.back().direction == 'R') {
                if (stack.back().health == robot.health) {
                    stack.pop_back();
                    gone = true;
                    break;
                }
                robot.health--;
                stack.pop_back();
            }

            if (!gone && !stack.empty() && stack.back().direction == 'R' && stack.back().health > robot.health) {
                stack.back().health--;
                gone = true;
            }

            if (!gone) {
                stack.push_back(robot);
            }
        }

        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        vector<int> result;
        for (const auto& robot : stack) {
            result.push_back(robot.health);
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of robots: ";
    cin >> n;

    vector<int> positions(n);
    vector<int> healths(n);
    string direction;

    cout << "Enter the positions of the robots: ";
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    cout << "Enter the healths of the robots: ";
    for (int i = 0; i < n; i++) {
        cin >> healths[i];
    }

    cout << "Enter the direction of the robots: ";
    cin >> direction;

    vector<int> survivedHealths = solution.Robots_health(positions, healths, direction);

    cout << "Survived robot's healths: ";
    for (int health : survivedHealths) {
        cout << health << " ";
    }
    cout << endl;

    return 0;
}
