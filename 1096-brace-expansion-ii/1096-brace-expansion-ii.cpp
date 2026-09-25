class Solution {
public:

    vector<string> braceExpansionII(string expression) {

        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }

private:

    set<string> parse(const string& s, int& i) {

        set<string> result;

        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {

                result.insert(
                    current.begin(),
                    current.end()
                );

                current = {""};

                i++;
            }

            else {

                set<string> part;

                if (s[i] == '{') {
                    i++;

                    part = parse(s, i);

                    i++;
                }
                else {

                    string word;

                    while (i < s.size() &&
                           isalpha(s[i])) {

                        word += s[i];
                        i++;
                    }

                    part.insert(word);
                }


                set<string> next;

                for (const string& a : current) {

                    for (const string& b : part) {

                        next.insert(a + b);
                    }
                }

                current = next;
            }
        }

        result.insert(
            current.begin(),
            current.end()
        );

        return result;
    }
};
