#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        data = d;
        right = nullptr;
        left = nullptr;
    }
};

class Tree
{
public:
    void createTree(int d)
    {
        Node *node = new Node(d);
        if (root == nullptr)
        {
            root = node;
        }
        else
        {
            Node *cur = root;
            while (true)
            {
                if (cur->data > d)
                {
                    if (cur->left == nullptr)
                    {
                        cur->left = node;
                        break;
                    }
                    else
                    {
                        cur = cur->left;
                    }
                }
                else if (cur->data < d)
                {
                    if (cur->right == nullptr)
                    {
                        cur->right = node;
                        break;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
                else
                {
                    // Duplicate value - don't insert
                    delete node;
                    break;
                }
            }
        }
    }

    void printTree()
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
    void levelOrderTraversal()
    {
        cout << "Here is level order traversal : " << endl;
        queue<Node *> q;
        q.push(root);

        while (q.size() > 0)
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " , ";
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        cout<<" ---------------- "<<endl;
    }

    void levelOrderTraversalNewLine()
    {
        cout << "Here is level order traversal in New Line: " << endl;
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);
        while (q.size() > 0)
        {
            Node *cur = q.front();
            q.pop();
            if (cur == nullptr)
            {
                if (!q.empty())
                {
                    q.push(nullptr);
                    cout << endl;
                    continue;
                }
                else
                    break;
            }
            cout << cur->data << " , ";
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
    }

private:
    Node *root = nullptr;
    queue<Node *> q;
    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};

int main()
{
    Tree t;
    t.createTree(10);
    t.createTree(5);
    t.createTree(15);
    t.createTree(3);
    t.createTree(7);
    t.createTree(12);
    t.createTree(18);
    t.printTree();
    t.levelOrderTraversal();
    t.levelOrderTraversalNewLine();
    return 0;
}