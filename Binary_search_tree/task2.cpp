#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
    int value;
    Node* parent;

    Node(int value, Node* parent)
    {
        this->value = value;
        this->parent = parent;
    }
};

bool findParent(Node* currentNode, int parent)
{
    if (currentNode == nullptr)
    {
        return false;
    }

    if (currentNode->value < parent)
    {
        return false;
    }

    if (currentNode->value == parent)
    {
        return true;
    }

    return findParent(currentNode->parent, parent);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Node*> arr(n);

    for (int i = 0; i < n - 1; i++)
    {
        int parentValue, childValue;
        cin >> parentValue >> childValue;
        if (arr[parentValue] == nullptr)
        {
            arr[parentValue] = new Node(parentValue, nullptr);
        }
        arr[childValue] = new Node(childValue, arr[parentValue]);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int parent, child;
        cin >> parent >> child;
        if (findParent(arr[child], parent))
        {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}