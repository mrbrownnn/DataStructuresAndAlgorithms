#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = createNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = createNode(data);
            return root;
        }
    }
    return root;
}

int findMinDepth(Node* root) {
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int size = q.size();
        depth++;

        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL && temp->right == NULL)
                return depth;

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            root = insertNode(root, data);
        }

        int minDepth = findMinDepth(root);
        cout << minDepth << endl;
    }

    return 0;
}