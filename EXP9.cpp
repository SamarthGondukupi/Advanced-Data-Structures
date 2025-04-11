//  Study of Optimal Binary Search Tree (OBST) algorithm. 

#include <iostream> 
#include <vector> 
#include <string> 
#include <climits> 
using namespace std; 
const int MAX = 100; 
class OBST { 
private: 
vector<string> keys; 
vector<int> frequency; 
int n; 
vector<vector<int>> cost; 
vector<vector<int>> root; 
public: 
OBST(const vector<string>& keys, const vector<int>& frequency) : keys(keys), 
frequency(frequency), n(keys.size()) { 
cost.resize(n + 1, vector<int>(n + 1, 0)); 
root.resize(n + 1, vector<int>(n + 1, 0)); 
buildOptimalBST(); 
    } 
 
    void buildOptimalBST() { 
        vector<int> cumulativeFreq(n + 1, 0); 
        for (int i = 1; i <= n; ++i) { 
            cumulativeFreq[i] = cumulativeFreq[i - 1] + frequency[i - 1]; 
        } 
 
        for (int i = 0; i <= n; ++i) { 
            cost[i][i] = 0; 
        } 
 
        for (int len = 1; len <= n; ++len) { 
            for (int i = 0; i <= n - len; ++i) { 
                int j = i + len; 
                cost[i][j] = INT_MAX; 
 
                for (int r = i; r < j; ++r) { 
                    int c = cost[i][r] + cost[r + 1][j] + cumulativeFreq[j] - cumulativeFreq[i]; 
                    if (c < cost[i][j]) { 
                        cost[i][j] = c; 
                        root[i][j] = r; 
                    } 
                } 
            } 
        } 
    } 
 
    void printOptimalBST() { 
        cout << "Optimal BST Cost: " << cost[0][n] << endl; 
        cout << "Root of the tree: " << keys[root[0][n]] << endl; 
    } 
}; 
 
int main() { 
    vector<string> keys = {"auto", "break", "case", "char", "const", "continue"}; 
    vector<int> frequency = {5, 40, 8, 10, 10, 23}; 
 
    OBST obst(keys, frequency); 
    obst.printOptimalBST(); 
 
    return 0; 
} 
 