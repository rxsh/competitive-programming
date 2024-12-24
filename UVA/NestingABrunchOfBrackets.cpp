#include <iostream>
#include <stack>

using namespace std;

bool isMatchingPair(char open, char close){
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}' || (open == '<' && close == '>') || (open == '*' && close == '*'));
}

bool isOpen(char c){
    return c == '(' || c == '[' || c == '{' || c == '<';
}

bool isClose(char c){
    return c == ')' || c == ']' || c == '}' || c == '>';
}


int main(){

    string line;
    while(getline(cin, line)){
        stack<pair<char,int>> s;
        bool isValid = true;
        int errorPosition = 0;

        for(int i=0; i<line.length(); i++){
            char c = line[i];
            errorPosition++;

            // handle special case for (* and *)
            if(c == '(' && i+1 < line.length() && line[i+1] == '*'){
                s.push(make_pair('*',errorPosition));
                i++; // skip the "*"" character
                continue;
            } else if(c == '*' && i+1 < line.length() && line[i+1] == ')'){
                if(!s.empty() && s.top().first == '*'){
                    s.pop();
                    i++;
                } else{
                    isValid = false;
                    break;
                }
                continue;
            }

            if(isOpen(c)){
                s.push(make_pair(c,errorPosition));
            } else if(isClose(c)){
                if(!s.empty() && isMatchingPair(s.top().first,c)){
                    s.pop();
                } else{
                    isValid = false;
                    break;
                }
            }
        }

        if(!s.empty() && isValid){
            isValid = false;
            errorPosition = s.top().second;
        }

        if(isValid){
            cout << "YES" << endl;
        } else{
            cout << "NO " << errorPosition << endl;
        }

    }    
    
    
    return 0;

}