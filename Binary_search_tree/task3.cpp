#include <iostream>
#include <vector>
#include <algorithm>
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

    Node(long long value, int x, int y)
    {
        this->value = value;
        this->x = x;
        this->y = y;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node*& current, vector<long long>& v)
{
    if (current != nullptr)
    {
        inorder(current->left, v);
        v.push_back(current->value);
        inorder(current->right, v);
    }
}

int main()
{
    int n, T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        vector<Node*> nodes(n);
        vector<long long> sorted;

        for (int i = 0; i < n; i++)
        {
            long long value, index1, index2;
            cin >> value >> index1 >> index2;
            nodes[i] = new Node(value, index1, index2);
        }

        int counter = 1;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2)
        {
            if (nodes[0]->value < nodes[1]->value)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            Node* currentNode = nodes[i];

            if (currentNode->x > -1)
            {
                currentNode->left = nodes[counter++];
            }

            if (currentNode->y > -1)
            {
                currentNode->right = nodes[counter++];
            }
        }

        inorder(nodes[0], sorted);

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (sorted[i] > sorted[i + 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}