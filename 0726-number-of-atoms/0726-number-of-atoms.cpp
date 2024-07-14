class Solution {
public:
    using int3 = array<int, 3>; // (pos for right ')', real ending, multiplier)
    vector<int3> mult;
    int n;
    int atom[702]; // Array to store counts of each atom

    // Convert chemical formula string to index
    inline int idx(string& s) {
        return (s[0] - 'A') * 27 + ((s.size() == 1) ? 0 : (s[1] - 'a' + 1));
    }

    // Convert index to chemical formula string
    inline string chemi(int x) {
        auto [q, r] = div(x, 27);
        string s = string(1, q + 'A');
        if (r > 0)
            s += (r - 1 + 'a');
        return s;
    }

    // Recursive function to count atoms
    void f(int i, string& formula, int l = -1, int r = -1, int times = 1) {
        while (i < r) {
            if (formula[i] == '(') {
                auto& m = mult[i];
                f(i+1, formula, i+1, m[0], m[2] * times);
                i = m[1] + 1;
            } 
            else if (isupper(formula[i])) {
                string chemi = string(1, formula[i]);
                int start = i;
                if (i+1 < r && islower(formula[i+1])) {
                    chemi+= formula[i+1];
                    i++;
                }
                i++;

                int x = 0;
                while (i < r && isdigit(formula[i])) {
                    x=x*10 + (formula[i]-'0');
                    i++;
                }
                if (x== 0) x= 1;
                atom[idx(chemi)]+= x* times;
            } 
            else 
                i++;
        }
    }

    // Convert atom array to result string
    inline string convert() {
        string result;
        for (int i = 0; i < 702; ++i) {
            if (atom[i] > 0) {
                result += chemi(i);
                if (atom[i] > 1)
                    result += to_string(atom[i]);
            }
        }
        return result;
    }

    string countOfAtoms(string& formula) {
        memset(atom, 0, sizeof(atom));
        n=formula.size();

        vector<int> st;
        mult.assign(n, {-1, -1, -1});
        for (int i = 0; i < n; i++) {
            char c = formula[i];
            if (c == '(')
                st.push_back(i);
            else if (c == ')') {
                int x = 0, r = i;
                while (i + 1 < n && isdigit(formula[i + 1])) {
                    x = 10 * x + (formula[++i] - '0');
                }
                if (x == 0)
                    x = 1;
                int l = st.back();
                st.pop_back();
                mult[l] = {r, i, x};
            }
        }
        f(0, formula, 0, n, 1); // Start recursive function
        return convert();       // Convert the atom array to result string
    }

};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();