#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, pair<string, int>> cows = {
    { "Bessie", { "Ox", 0 } }
};
unordered_map<string, int> animals = {
    { "Ox", 0 },
    { "Tiger", 1 },
    { "Rabbit", 2 },
    { "Dragon", 3 },
    { "Snake", 4 },
    { "Horse", 5 },
    { "Goat", 6 },
    { "Monkey", 7 },
    { "Rooster", 8 },
    { "Dog", 9 },
    { "Pig", 10 },
    { "Rat", 11 },
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, time, animal, target, _;
        cin >> name >> _ >> _ >> time >> animal >> _ >> _ >> target;

        const int prevYear = cows[target].second;
        const string prevAnimal = cows[target].first;
        int year;
        if (time == "previous") {
            year = prevYear - (12 - (animals[animal] - animals[prevAnimal]));
            if (abs(year - prevYear) > 12)
                year += 12;
        } else {
            year = prevYear + (12 - (animals[prevAnimal] - animals[animal]));
            if (abs(year - prevYear) > 12)
                year -= 12;
        }
        cows[name] = { animal, year };

        if (name == "Elsie")
            break;
    }

    cout << abs(cows["Elsie"].second) << endl;

    return 0;
}