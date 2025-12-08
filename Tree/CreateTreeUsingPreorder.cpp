#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class CreatingTree
{
public:

    Node *createTree(vector<int> v)
    {
        indx++;
        if (v[indx] == -1)
            return nullptr;
        Node* node = new Node(v[indx]);  // Use local variable
        node->left = createTree(v);
        node->right = createTree(v);
        return node;
    }
    void printTree(Node* root)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty!" << endl;
            return;
        }

        int h = getHeight(root);
        queue<Node *> q;
        q.push(root);

        for (int level = 0; level < h; level++)
        {
            int levelNodes = 1 << level; // 2^level
            int spaceBefore = (1 << (h - level - 1)) - 1;
            int spaceBetween = (1 << (h - level)) - 1;

            // Print spaces before first node
            for (int i = 0; i < spaceBefore; i++)
                cout << " ";

            for (int i = 0; i < levelNodes; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr != nullptr)
                {
                    if (curr->data < 10)
                        cout << curr->data;
                    else
                        cout << curr->data;
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else
                {
                    cout << "N";
                    q.push(nullptr);
                    q.push(nullptr);
                }

                // Print spaces between nodes
                if (i < levelNodes - 1)
                {
                    for (int j = 0; j < spaceBetween; j++)
                        cout << " ";
                }
            }
            cout << endl;

            // Print branch lines
            if (level < h - 1)
            {
                int branchSpace = (1 << (h - level - 2));

                // Spacing before first branch
                for (int i = 0; i < spaceBefore - branchSpace; i++)
                    cout << " ";

                for (int i = 0; i < levelNodes; i++)
                {
                    cout << "/";
                    for (int j = 0; j < 2 * branchSpace - 1; j++)
                        cout << " ";
                    cout << "\\";

                    if (i < levelNodes - 1)
                    {
                        for (int j = 0; j < spaceBetween - 2 * branchSpace; j++)
                            cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }

private:

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int indx = -1;
};

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    CreatingTree obj;
    Node *root = obj.createTree(preOrder);
    cout<<"Root->"<<root->data<<endl;
    obj.printTree(root);
    cout<<"Root->"<<root->data<<endl;
    return 0;
}