class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.size();
        int num=0;
        int den=1;
        int i=0;
        while(i<n)
        {
            int curr_num=0,curr_den=0;
            bool is_neg=false;
            if(expression[i]=='-' || expression[i]=='+') 
            {
                if(expression[i]=='-') is_neg=true;
                i++;
            }
            while(expression[i]>='0' && expression[i]<='9')
            {
                int dig=expression[i]-'0';
                curr_num=curr_num*10 + dig;
                i++;
            }
            i++;
            if(is_neg==true) curr_num=-1*curr_num;

            while(i<n && (expression[i]>='0' && expression[i]<='9'))
            {
                int dig=expression[i]-'0';
                curr_den=curr_den*10 + dig;
                i++;
            }

            num=(num*curr_den) + (den*curr_num);     // cross multiplying the fractions
            den=(den* curr_den);

            int g=1;
            if(num>0) g=__gcd(num,den);
            else g=__gcd(-1*num,den);

            if(g>0)
            {
                num/=g;
                den/=g;
            }    
        }
        return to_string(num)+"/"+to_string(den);
    }
};