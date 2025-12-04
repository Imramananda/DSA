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
    Tree()
    {
        root = nullptr;
    }
    void createTree(int d)
    {
        Node *leaf = new Node(d);
        if (root == nullptr)
        {
            root = leaf;
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
                        cur->left = leaf;
                        break;
                    }
                    else
                        cur = cur->left;
                }
                else if (cur->data < d)
                {
                    if (cur->right == nullptr)
                    {
                        cur->right = leaf;
                        break;
                    }
                    else
                        cur = cur->right;
                }
                else
                {
                    delete leaf;
                    break;
                }
            }
        }
    }
    // 3,5,7,10,12,15,18
    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void postOrder()
    {
        cout << "PostOrder Traversal: ";
        postOrderTraversal(root);
        cout << endl;
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

private:
    Node *root;

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

    cout << "Tree Structure:" << endl;
    t.printTree();
    cout << endl;

    t.postOrder();

    return 0;
}