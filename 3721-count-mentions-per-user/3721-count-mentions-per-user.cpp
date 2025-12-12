class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> onlineUntil(numberOfUsers, 0); 

        struct Event {
            string type;
            int time;
            string data;
        };

        vector<Event> ev;
        for (auto &e : events) {
            ev.push_back({e[0], stoi(e[1]), e[2]});
        }
        sort(ev.begin(), ev.end(), [](const Event &a, const Event &b){
            if (a.time != b.time) return a.time < b.time;
            if (a.type != b.type) {
                if (a.type == "OFFLINE") return true;
                if (b.type == "OFFLINE") return false;
            }
            return false; 
        });

        for (const auto &e : ev) {
            int currentTime = e.time;
            for (int i = 0; i < numberOfUsers; ++i) {
                if (onlineUntil[i] != 0 && currentTime >= onlineUntil[i]) {
                    onlineUntil[i] = 0; 
                }
            }

            if (e.type == "OFFLINE") {
                int id = stoi(e.data);
                onlineUntil[id] = currentTime + 60;
            } else {
                const string &s = e.data;
                if (s == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) mentions[i]++;
                } else if (s == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (onlineUntil[i] == 0) mentions[i]++;
                    }
                } else {
                    stringstream ss(s);
                    string token;
                    while (ss >> token) {
                        if (token.rfind("id", 0) == 0) {
                            int id = stoi(token.substr(2));
                            mentions[id]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};