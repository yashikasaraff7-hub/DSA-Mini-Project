#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// ================= FAMILY MEMBER NODE =================
class FamilyMember
{
public:
    int id;
    string name;
    int birthYear;

    FamilyMember *left;
    FamilyMember *right;

    FamilyMember(int i, string n, int b)
    {
        id = i;
        name = n;
        birthYear = b;

        left = NULL;
        right = NULL;
    }
};

// ================= FAMILY TREE =================
class FamilyTree
{
private:
    FamilyMember *root;

    // ---------- Recursive Traversals ----------
    void inorderRecursive(FamilyMember *node)
    {
        if (node == NULL)
            return;

        inorderRecursive(node->left);

        cout << "ID: " << node->id
             << " | Name: " << node->name
             << " | Birth Year: " << node->birthYear << endl;

        inorderRecursive(node->right);
    }

    void preorderRecursive(FamilyMember *node)
    {
        if (node == NULL)
            return;

        cout << "ID: " << node->id
             << " | Name: " << node->name
             << " | Birth Year: " << node->birthYear << endl;

        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void postorderRecursive(FamilyMember *node)
    {
        if (node == NULL)
            return;

        postorderRecursive(node->left);
        postorderRecursive(node->right);

        cout << "ID: " << node->id
             << " | Name: " << node->name
             << " | Birth Year: " << node->birthYear << endl;
    }

    // ---------- Height ----------
    int calculateHeight(FamilyMember *node)
    {
        if (node == NULL)
            return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    // ---------- Count Members ----------
    int countMembers(FamilyMember *node)
    {
        if (node == NULL)
            return 0;

        return 1 + countMembers(node->left) + countMembers(node->right);
    }

    // ---------- Search Node ----------
    FamilyMember *searchNode(FamilyMember *node, int id)
    {
        if (node == NULL)
            return NULL;

        if (node->id == id)
            return node;

        FamilyMember *leftSearch = searchNode(node->left, id);

        if (leftSearch != NULL)
            return leftSearch;

        return searchNode(node->right, id);
    }

    // ---------- Find Path ----------
    bool findPath(FamilyMember *node, int id, vector<FamilyMember *> &path)
    {
        if (node == NULL)
            return false;

        path.push_back(node);

        if (node->id == id)
            return true;

        if (findPath(node->left, id, path) ||
            findPath(node->right, id, path))
            return true;

        path.pop_back();
        return false;
    }

public:
    FamilyTree()
    {
        root = NULL;
    }

    // ================= ADD MEMBER =================
    void addMember()
    {
        int id, birthYear, parentId;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        cout << "Enter Birth Year: ";
        cin >> birthYear;

        FamilyMember *newMember = new FamilyMember(id, name, birthYear);

        // First member becomes root
        if (root == NULL)
        {
            root = newMember;
            cout << "Root family member added successfully.\n";
            return;
        }

        cout << "Enter Parent Member ID: ";
        cin >> parentId;

        FamilyMember *parent = searchNode(root, parentId);

        if (parent == NULL)
        {
            cout << "Parent not found.\n";
            delete newMember;
            return;
        }

        int choice;

        cout << "Add as:\n";
        cout << "1. Left Child\n";
        cout << "2. Right Child\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (parent->left == NULL)
            {
                parent->left = newMember;
                cout << "Member added successfully.\n";
            }
            else
            {
                cout << "Left child already exists.\n";
                delete newMember;
            }
        }
        else if (choice == 2)
        {
            if (parent->right == NULL)
            {
                parent->right = newMember;
                cout << "Member added successfully.\n";
            }
            else
            {
                cout << "Right child already exists.\n";
                delete newMember;
            }
        }
        else
        {
            cout << "Invalid choice.\n";
            delete newMember;
        }
    }

    // ================= DISPLAY TREE =================
    void displayLevelOrder()
    {
        if (root == NULL)
        {
            cout << "Family tree is empty.\n";
            return;
        }

        queue<FamilyMember *> q;
        q.push(root);

        cout << "\n===== FAMILY TREE LEVEL ORDER =====\n";

        while (!q.empty())
        {
            FamilyMember *current = q.front();
            q.pop();

            cout << "ID: " << current->id
                 << " | Name: " << current->name
                 << " | Birth Year: " << current->birthYear << endl;

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }
    }

    // ================= INORDER =================
    void inorderRecursiveDisplay()
    {
        cout << "\n===== INORDER RECURSIVE =====\n";
        inorderRecursive(root);
    }

    void inorderIterative()
    {
        cout << "\n===== INORDER ITERATIVE =====\n";

        stack<FamilyMember *> st;
        FamilyMember *current = root;

        while (current != NULL || !st.empty())
        {
            while (current != NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            cout << "ID: " << current->id
                 << " | Name: " << current->name
                 << " | Birth Year: " << current->birthYear << endl;

            current = current->right;
        }
    }

    // ================= PREORDER =================
    void preorderRecursiveDisplay()
    {
        cout << "\n===== PREORDER RECURSIVE =====\n";
        preorderRecursive(root);
    }

    void preorderIterative()
    {
        cout << "\n===== PREORDER ITERATIVE =====\n";

        if (root == NULL)
            return;

        stack<FamilyMember *> st;
        st.push(root);

        while (!st.empty())
        {
            FamilyMember *current = st.top();
            st.pop();

            cout << "ID: " << current->id
                 << " | Name: " << current->name
                 << " | Birth Year: " << current->birthYear << endl;

            if (current->right != NULL)
                st.push(current->right);

            if (current->left != NULL)
                st.push(current->left);
        }
    }

    // ================= POSTORDER =================
    void postorderRecursiveDisplay()
    {
        cout << "\n===== POSTORDER RECURSIVE =====\n";
        postorderRecursive(root);
    }

    void postorderIterative()
    {
        cout << "\n===== POSTORDER ITERATIVE =====\n";

        if (root == NULL)
            return;

        stack<FamilyMember *> st1, st2;

        st1.push(root);

        while (!st1.empty())
        {
            FamilyMember *current = st1.top();
            st1.pop();

            st2.push(current);

            if (current->left != NULL)
                st1.push(current->left);

            if (current->right != NULL)
                st1.push(current->right);
        }

        while (!st2.empty())
        {
            FamilyMember *current = st2.top();
            st2.pop();

            cout << "ID: " << current->id
                 << " | Name: " << current->name
                 << " | Birth Year: " << current->birthYear << endl;
        }
    }

    // ================= HEIGHT =================
    void displayHeight()
    {
        cout << "\nHeight of Family Tree: "
             << calculateHeight(root) << endl;
    }

    // ================= MEMBER COUNT =================
    void displayMemberCount()
    {
        cout << "\nTotal Family Members: "
             << countMembers(root) << endl;
    }

    // ================= COMMON ANCESTOR =================
    void findCommonAncestor()
    {
        int id1, id2;

        cout << "\nEnter First Member ID: ";
        cin >> id1;

        cout << "Enter Second Member ID: ";
        cin >> id2;

        vector<FamilyMember *> path1, path2;

        if (!findPath(root, id1, path1) ||
            !findPath(root, id2, path2))
        {
            cout << "One or both members not found.\n";
            return;
        }

        int i = 0;

        while (i < path1.size() &&
               i < path2.size() &&
               path1[i] == path2[i])
        {
            i++;
        }

        FamilyMember *ancestor = path1[i - 1];

        cout << "\nCommon Ancestor:\n";
        cout << "ID: " << ancestor->id
             << " | Name: " << ancestor->name
             << " | Birth Year: " << ancestor->birthYear << endl;
    }

    // ================= SEARCH MEMBER =================
    void searchMember()
    {
        int id;

        cout << "\nEnter Member ID to Search: ";
        cin >> id;

        FamilyMember *result = searchNode(root, id);

        if (result == NULL)
        {
            cout << "Member not found.\n";
        }
        else
        {
            cout << "\nMember Found:\n";
            cout << "ID: " << result->id
                 << " | Name: " << result->name
                 << " | Birth Year: " << result->birthYear << endl;
        }
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    FamilyTree tree;

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n       FAMILY TREE EXPLORER";
        cout << "\n====================================";

        cout << "\n1. Add Family Member";
        cout << "\n2. Display Family Tree";
        cout << "\n3. Inorder Recursive";
        cout << "\n4. Inorder Iterative";
        cout << "\n5. Preorder Recursive";
        cout << "\n6. Preorder Iterative";
        cout << "\n7. Postorder Recursive";
        cout << "\n8. Postorder Iterative";
        cout << "\n9. Find Height of Tree";
        cout << "\n10. Count Total Members";
        cout << "\n11. Find Common Ancestor";
        cout << "\n12. Search Family Member";
        cout << "\n13. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.addMember();
            break;

        case 2:
            tree.displayLevelOrder();
            break;

        case 3:
            tree.inorderRecursiveDisplay();
            break;

        case 4:
            tree.inorderIterative();
            break;

        case 5:
            tree.preorderRecursiveDisplay();
            break;

        case 6:
            tree.preorderIterative();
            break;

        case 7:
            tree.postorderRecursiveDisplay();
            break;

        case 8:
            tree.postorderIterative();
            break;

        case 9:
            tree.displayHeight();
            break;

        case 10:
            tree.displayMemberCount();
            break;

        case 11:
            tree.findCommonAncestor();
            break;

        case 12:
            tree.searchMember();
            break;

        case 13:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 13);

    return 0;
}
