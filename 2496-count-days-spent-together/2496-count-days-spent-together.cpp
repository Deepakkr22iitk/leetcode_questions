class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string start;
        if (arriveAlice > arriveBob) {
            start = arriveAlice;
        } else {
            start = arriveBob;
        }

        string end;
        if (leaveAlice < leaveBob) {
            end = leaveAlice;
        } else {
            end = leaveBob;
        }

        if (end < start) {
            return 0;
        }

        int sm = stoi(start.substr(0, 2)), em = stoi(end.substr(0, 2));
        int sd = stoi(start.substr(3, 2)), ed = stoi(end.substr(3, 2));

        int d = 0;
        for (int i = sm - 1; i < em; i++) {
            d += days[i];
        }

        return d - (sd - 1) - (days[em - 1] - ed);
    }
};