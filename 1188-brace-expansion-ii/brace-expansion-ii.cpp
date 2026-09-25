class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }

private:
    string s;
    int pos;

    // expr := term (',' term)*
    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (pos < (int)s.size() && s[pos] == ',') {
            pos++; // skip ','
            set<string> term = parseTerm();
            result.insert(term.begin(), term.end());
        }
        return result;
    }

    // term := factor+
    set<string> parseTerm() {
        vector<set<string>> factors;
        while (pos < (int)s.size() && s[pos] != ',' && s[pos] != '}') {
            factors.push_back(parseFactor());
        }

        // Cartesian product (concatenation) of all factors
        set<string> result;
        result.insert("");
        for (auto& f : factors) {
            set<string> newResult;
            for (const string& prefix : result) {
                for (const string& suffix : f) {
                    newResult.insert(prefix + suffix);
                }
            }
            result = std::move(newResult);
        }
        return result;
    }

    // factor := letters | '{' expr '}'
    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++; // skip '{'
            set<string> result = parseExpr();
            pos++; // skip '}'
            return result;
        } else {
            int start = pos;
            while (pos < (int)s.size() && islower(s[pos])) pos++;
            return {s.substr(start, pos - start)};
    }
    }
};