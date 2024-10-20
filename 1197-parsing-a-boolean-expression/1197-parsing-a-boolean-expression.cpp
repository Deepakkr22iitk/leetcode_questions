class Solution {
public:
    bool evaluate(string &exp, int &ind)
    {
        char curr=exp[ind++];

        if(curr=='t') return true;
        if(curr=='f') return false;

        // Handle NOT operation '!(...)'
        if (curr=='!') 
        {
            ind++;  // Skip '('
            bool result = !evaluate(exp, ind);
            ind++;  // Skip ')'
            return result;
        }

        // Handle AND '&(...)' and OR '|(...)'
        vector<bool> values;
        ind++;  // Skip '('
        while (exp[ind] != ')') 
        {
            if (exp[ind] != ',') values.push_back(evaluate(exp, ind));  // Collect results of subexpressions
            else ind++;  // Skip commas
        }
        ind++;  // Skip ')'

        // Manual AND operation: returns false if any value is false
        if (curr=='&') 
        {
            for (bool v:values) 
            {
                if (v==false) return false;
            }
            return true;
        }

        // Manual OR operation: returns true if any value is true
        if (curr=='|') 
        {
            for (bool v:values) 
            {
                if (v==true) return true;
            }
            return false;
        }

        return false;  // This point should never be reached
    }
    bool parseBoolExpr(string expression) {
        int ind=0;
        return evaluate(expression,ind);
    }
};