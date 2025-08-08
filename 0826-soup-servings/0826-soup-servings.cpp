class Solution
{

   	// LOGIC

   	// 1. Choices hain 4 operations ki to Recusrsion and optimise karne ke liye 
   	// Memoization.
   	// 2. Is question mein 4800 ka figure has come from hit and trial, I have not found it
   	// out but by discussion I got to know.
   	// 3. Very low chance of this question to come in interview.
   	// 4. 2D Dp array kyo liya❓-> Because 2 params are changing qty a and qty b.
   	// 5. Rest explained below.
//============================================================================================================
    public:
        vector<int> optionA = { 100,
            75,
            50,
            25
        };
    vector<int> optionB = { 0,
        25,
        50,
        75
    };

    double solve(int a, int b, vector<vector < double>> &dp)
    {
        if (a == 0 && b == 0)
           	//Dono ek saath khali ho gaye
            return 0.5;
        if (a == 0)
           	//A pehle khali ho gaya jo ham chahte the
            return 1;
        if (b == 0) return 0;
       	//b pehle khali ho gaya

        if (dp[a][b] != -1) return dp[a][b];
       	//Pehle se solved tha to

        double ans = 0;
        for (int k = 0; k < 4; k++)
       	//Will try all 4 operations
        {
            int rema = a - optionA[k];
           	//Remaining kitna bacha hain a mein
            int remb = b - optionB[k];
           	//Remaining kitna bacha hain b mein
            ans = ans + 0.25* solve(max(0, rema), max(0, remb), dp);
           	//rema ya rem b dono mein se koi -ve nahin hona chahiye
        }

        return dp[a][b] = ans;
    }

    double soupServings(int n)
    {
        if (n >= 4800) return 1;
       	//since we want to calculate the probability of a .
       	//so we can see that the a will become 0 at fast rate as we increase n 
        //because a is decresing at more faster rate 
       	//at sume point probaility reaches 1 for soup A will be empty first .
        vector<vector < double>> dp(n + 1, vector<double> (n + 1, -1));
        return solve(n, n, dp);
    }
};