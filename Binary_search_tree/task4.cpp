#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string value;
    Node* left, * right;

    Node(string value)
    {
        this->value = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, string key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->value)
        root->left = insert(root->left, key);
    else if (key > root->value)
        root->right = insert(root->right, key);
    return root;
}

bool findElement(Node* current, string querry)
{
    if (current == nullptr)
    {
        return false;
    }

    if (current->value == querry)
    {
        return true;
    }

    if (current->value < querry)
    {
        return findElement(current->right, querry);
    }
    else
    {
        return findElement(current->left, querry);
    }

}


int main()
{
    int n;
    cin >> n;

    string text;
    cin >> text;
    Node* root = nullptr;
    root = insert(root, text);

    for (int i = 1; i < n; i++)
    {
        string text;
        cin >> text;
        insert(root, text);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string querry;
        cin >> querry;
        if (findElement(root, querry))
        {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}