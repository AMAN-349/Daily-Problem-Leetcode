class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) {
        v.resize(rows,vector<int>(26,-1));
    }
    
    void setCell(string cell, int value) {
        char col=cell[0];
        int row=stoi(cell.substr(1));
        v[row-1][col-'A']=value;
    }
    
    void resetCell(string cell) {
        char col=cell[0];
        int row=stoi(cell.substr(1));
        v[row-1][col-'A']=0;
    }
    
    int getValue(string formula) {
    string temp1, temp2="";
    for(int i=1;i<formula.size();i++) {
        if(formula[i]=='+') {
            temp1=temp2;
            temp2="";
        } else {
            temp2+=formula[i];
        }
    }

    int sum = 0;
    if(isalpha(temp1[0])) {
        cout<<"Hi";
        char col = temp1[0];
        int newcol = col - 'A';
        int row = stoi(temp1.substr(1)) - 1;
        if(v[row][newcol] != -1) {
            sum += v[row][newcol];
        }
    } 
    else {
        sum += stoi(temp1);
    }

    if(isalpha(temp2[0])) {
        char col = temp2[0];
        int newcol = col - 'A';
        int row = stoi(temp2.substr(1)) - 1;
        if(v[row][newcol] != -1) {
            sum += v[row][newcol];
        }
        }
    else {
        sum += stoi(temp2);
    }
    return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */