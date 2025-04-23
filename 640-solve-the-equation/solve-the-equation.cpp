class Solution {
public:
    string solveEquation(string equation) {
        int xcoeff=0,constant=0;
        int sign=1;
        int i=0;
        int n=equation.size();
        while(i<n)
        {
            if(equation[i]=='=')
            {
                sign=-1;
                i++;
                continue;
            }
            int currsign=sign;
            if(equation[i]=='+' || equation[i]=='-')
            {
                currsign=(equation[i]=='+')?sign:-sign;
                i++;
            }
            bool isnumber=false;
            int num=0;
            while(i<n && isdigit(equation[i]))
            {
                num=num*10+(equation[i]-'0');
                i++;
                isnumber=true;
            }
            if(i<n && equation[i]=='x')
            {
                xcoeff+=currsign*((isnumber)?num:1);
                i++;
            }
            else{
                constant+=currsign*num;
            }


        }
        if (xcoeff == 0) {
            if (constant == 0) return "Infinite solutions";
            else return "No solution";
        }

        int result = -(constant) / xcoeff;
        return "x=" + to_string(result);
    }
};