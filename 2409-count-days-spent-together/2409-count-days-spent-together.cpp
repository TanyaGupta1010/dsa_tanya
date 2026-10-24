
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto toDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 1; i < month; i++) {
                day += days[i];
            }

            return day;
        };

        int a1 = toDays(arriveAlice);
        int a2 = toDays(leaveAlice);
        int b1 = toDays(arriveBob);
        int b2 = toDays(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};
