#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
public:
    long long value;
    int x;
    int y;
    Node* left;
    Node* right;

    Node()
    {
        value = x = y = 0;
        left = right = nullptr;
    }

    Node(long long value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        left = nullptr;
        right = nullptr;
    }
};

void printVerticalSum(Node* root, int position, map<int, long long>& map)
{
    if (root == nullptr)
    {
        return;
    }

    map[position] += root->value;

    printVerticalSum(root->left, position - 1, map);

    printVerticalSum(root->right, position + 1, map);
}

int main()
{
    int n;
    cin >> n;
    vector<Node*> nodes(n);
    map<int, long long> map;

    for (int i = 0; i < n; i++)
    {
        int value, index1, index2;
        cin >> value >> index1 >> index2;
        nodes[i] = new Node(value, index1, index2);
    }

    Node* root = new Node();
    int counter = 1;
    for (int i = 0; i < n; i++)
    {
        Node* currentNode = nodes[i];
        if (currentNode == nodes[0])
        {
            root = currentNode;
            root->left = nodes[1];
            root->right = nodes[2];
        }

        if (currentNode->x > -1)
        {
            currentNode->left = nodes[counter++];
        }

        if (currentNode->y > -1) {
            currentNode->right = nodes[counter++];
        }
    }

    printVerticalSum(root, 0, map);

    for (auto it : map)
    {
        cout << it.second << " ";
    }
}