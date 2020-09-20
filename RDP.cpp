#include <iostream>
#include <string>

using namespace std;

/* Grammar:
    Set : { List }
    List: Head Tail | e
    Head: number | Set
    Tail: , Head Tail | e
*/

bool parseSet (string);
bool parseList(string);
bool parseHead(string);
bool parseTail(string);
bool parseNum (string);
bool endOfStr (string);

int pos; // global variable used for easier parsing

int main(){
    pos = 0;
    //get input
    string input;
    getline(cin, input);
    
    //Parse and display result
    bool result = parseSet(input);
    if(pos != input.size() or !result)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    
    return 0;
}

bool endOfStr(string s){
    return pos >= s.size();
}

bool parseSet(string s){
    if(!endOfStr(s) and s[pos] == '{'){
        pos++;
        if(parseList(s)){
            if(!endOfStr(s) and s[pos] == '}'){
                pos++;
                return true;
            }
        }
    }
    return false;
}

bool parseList(string s){
    int marker = pos;
    if(parseHead(s)){
        if(parseTail(s)){
            return true;
        }
    }
    pos = marker;
    return true;
}

bool parseHead(string s){
    int marker = pos;
    if(parseNum(s)){
        return true;
    }
    pos = marker;
    return parseSet(s);
}

bool parseTail(string s){
    int marker = pos;
    if(!endOfStr(s) and s[pos] == ','){
        pos++;
        return parseHead(s) and parseTail(s);
    }
    pos = marker;
    return true;
}

//Helper function to check for and get past numbers
bool parseNum(string s){
    if(!endOfStr(s) and s[pos] >= '0' and s[pos] <= '9'){
        while(++pos < s.size() and 
              s[pos] >= '0'  and 
              s[pos] <= '9');

        return true;
    }
    return false;
}