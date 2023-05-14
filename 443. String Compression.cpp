class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int idx = 0;
        int counter = 0;
        char curchar = chars[0];
        char prevchar = curchar;
        while (idx < chars.size()){
            curchar = chars[idx];
            if (prevchar == curchar){
                counter++;
            }else {
                if (counter == 1){
                    s += prevchar;
                }else {
                    s+= prevchar;
                    string temp = "";
                    while (counter != 0){
                        temp+= '0' + counter % 10;
                        counter /=10;
                    }
                    //s+= '0' + counter;
                    reverse (temp.begin(), temp.end());
                    s += temp;
                }
                counter = 1;
            }
            prevchar = curchar;
            idx++;
        }
        if (counter ==1){
            s += curchar;
        }else {
            s += prevchar;
            //s += '0' + counter;
            string temp = "";
            while (counter != 0){
                temp+= '0' + counter % 10;
                counter /=10;
            }
            reverse (temp.begin(), temp.end());
            s += temp;
        }
        for (int i = 0; i<s.length(); i++){
            chars[i] = s[i];
        }
        return s.length();
    }
};

//Alternative Solution
int compress(vector<char>& chars) {
	int i = 0;
	for(int j = 1, count = 1; j <= chars.size(); j++, count++) {
		if(j == chars.size() || chars[j] != chars[j - 1]) {
			chars[i++] = chars[j - 1];  
			if(count >= 2) 
				for(char digit : to_string(count)) 
					chars[i++] = digit;
			count = 0;
		}
	}
	return i;
}
