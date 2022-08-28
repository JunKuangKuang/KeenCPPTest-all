#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int index1;
    int index2;
    int sum;

    // i1+i2=sum
    Node(int i1, int i2, int sum) {
        this->index1 = i1;
        this->index2 = i2;
        this->sum = sum;
    }

    //从小到大排列，会形成大顶堆
    friend bool operator<(Node n1, Node n2) {
        return n1.sum < n2.sum;
    }
};

priority_queue<Node> m;//默认大顶堆辅助
set<string> s;

vector<int> topKSum(vector<int> arr1, vector<int> arr2, int k) {
    vector<int> res;//结果集
    int len1 = arr1.size();
    int len2 = arr2.size();
    k = min(k, len1 * len2); //len1*len2表示最多能够组成的结果的个数，防止给了2x2的数组，却要100个

    m.push(Node(len1 - 1, len2 - 1, arr1[len1 - 1] + arr2[len2 - 1]));
    s.insert(to_string(len1 - 1) + to_string(len2 - 1));
    while (res.size() < k) {
        Node currentNode = m.top();
        res.push_back(currentNode.sum);
        m.pop();//从大顶堆取出一个值并记入结果集

        //两个if是为了剪枝，保证不会循环到已经走过的组合
        if (s.count(to_string(currentNode.index1 - 1) +
                    to_string(currentNode.index2)) == 0) {
            m.push(Node(currentNode.index1 - 1, currentNode.index2,
                        arr1[currentNode.index1 - 1] + arr2[currentNode.index2]));
        }
        if (s.count(to_string(currentNode.index1) +
                    to_string(currentNode.index2 - 1)) == 0) {
            m.push(Node(currentNode.index1, currentNode.index2 - 1,
                        arr1[currentNode.index1] + arr2[currentNode.index2 - 1]));
        }
    }
    return res;
}

int main() {
    vector<int> arr1{1, 2, 3, 4, 5};
    vector<int> arr2{3, 5, 7, 9, 11};
    int k = 4;
    vector<int> result = topKSum(arr1, arr2, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}