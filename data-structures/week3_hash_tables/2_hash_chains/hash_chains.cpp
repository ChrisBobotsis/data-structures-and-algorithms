#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using std::string;
using std::vector;
using std::cin;
using std::set;


long long compute_string_hash(string s, int m) {

    size_t p = 1000000007;
    size_t x = 263;

    long long result = 0;

    for (int i = 0; i < s.length(); i++) {
        
        long long pwr = pow(x, i);
        long long tmp = s[i]*pwr % p;
        std::cout << tmp << std::endl;
        result += tmp;

    }

    return result % m;
}


struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;

    vector<vector<string>> elements;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), elements(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {

        if (query.type == "check") {
            // use reverse order, because we append strings to the end

            vector<string> string_set = elements[query.ind];

            for (auto it = string_set.rbegin(); it != string_set.rend(); it++) {
                std::cout << *it << " ";
            }
            std::cout << "\n";
        } 
        
        else {

            size_t hash = hash_func(query.s);
            //std::cout << hash << std::endl;
            vector<string> string_set = elements[hash];

            vector<string>::iterator it = std::find(string_set.begin(), string_set.end(), query.s);

            if (query.type == "find")
                writeSearchResult(it != string_set.end());
            else if (query.type == "add") {
                if (it == string_set.end())
                    elements[hash].push_back(query.s);
            } else if (query.type == "del") {
                if (it != string_set.end())
                    elements[hash].erase(std::remove(elements[hash].begin(), elements[hash].end(), query.s), elements[hash].end()); 
                    //elements[hash].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
