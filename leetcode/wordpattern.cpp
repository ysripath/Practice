

class Solution {
public:
    bool wordPattern(string pattern, string s) {
	string arr[200];
	for (int i = 97; i <= 122; i++)
	    arr[i] = string();
    char* token = strtok((char*)s.c_str()," ");
    int l = pattern.size();
    char* buf = new char[l];
    strcpy(buf,pattern.c_str());
    for (int i = 0; i < l; i++)
    {
        if (token != NULL)
        {
        if (arr[(int)buf[i]] == string())
        {
            for (int i = 97; i <= 122; i++)
            {
                if (!arr[i].compare(token))
                    return false;
            }
            arr[(int)buf[i]] = string(token);
            token = strtok(NULL," ");
        }
        else
        {
            string temp = arr[(int)buf[i]];
            if (temp.compare(token))
                return false;
            else
                token = strtok(NULL, " ");
        }
        }
        else
            return false;
    }
    if (token != NULL)
        return false;
    return true;
}
};
