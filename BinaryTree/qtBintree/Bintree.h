#ifndef BINTREE_H
#define BINTREE_H

#endif // BINTREE_H

#pragma once
#include <vector>
#include <queue>
#include <string>

//using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
    Tree* parent;

    Tree(int val, Tree* par, Tree* l, Tree* r)
    {
        data = val;
        left = l;
        right = r;
        parent = par;
    }

    Tree(int val)
        {
            this->data = val;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }

    Tree()
    {
        data = -1337;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Tree* minTree(Tree* tree)
    {
        if (tree->left == nullptr) return this;
        return tree->left->minTree(tree->left);
    }

    Tree* maxTree(Tree* tree)
    {
        if (tree->right == nullptr) return this;
        return tree->right->minTree(tree->right);
    }

    void insert(int val)
        {
            Tree* temp_tree = this;
            while (temp_tree != nullptr)
            {
                if (val > temp_tree->data)
                {
                    if (temp_tree->right != nullptr)
                    {
                        temp_tree = temp_tree->right;
                    }
                    else
                    {
                        Tree* tmp = new Tree(val);
                        tmp->parent = temp_tree;
                        temp_tree->right = tmp;
                        break;
                    }
                }
                else if (val < temp_tree->data)
                {
                    if (temp_tree->left != nullptr)
                    {
                        temp_tree = temp_tree->left;
                    }
                    else
                    {
                        Tree* tmp = new Tree(val);
                        tmp->parent = temp_tree;
                        temp_tree->left = tmp;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

    Tree* find(int val)
        {
            if (this == nullptr)
            {
                return nullptr;
            }

            if (this->data == val)
            {
                return this;
            }
            else if (val < this->data)
            {
                return this->left->find(val);
            }
            else if (val > this->data)
            {
                return this->right->find(val);
            }
        }

    bool erase(int val)
        {
            Tree* node = this->find(val);
            if (node == nullptr) return false;

            if ( (node->left == nullptr) && (node->right == nullptr) )
            {
                Tree* node_par = node->parent;
                if (node_par->left == node)
                {
                    node->parent->left = nullptr;
                }
                else
                {
                    node->parent->right = nullptr;
                }
                delete node;
            }

            else if ( (node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr) )
            {
                Tree* node_par = node->parent;
                if (node->left == nullptr)
                {
                    if (node_par->left == node)
                    {
                        node->parent->left = node->right;
                    }
                    else
                    {
                        node->parent->right = node->right;
                    }
                    node->right->parent = node->parent;
                }
                else
                {
                    if (node_par->left == node)
                    {
                        node->parent->left = node->left;
                    }
                    else
                    {
                        node->parent->right = node->left;
                    }
                    node->left->parent = node->parent;
                }
                delete node;
            }

            else
            {
                Tree* r_tree_min = node->right->minTree(node->right);

                if (r_tree_min->left == nullptr && r_tree_min->right == nullptr)
                {
                    int tmp = r_tree_min->data;
                    this->erase(r_tree_min->data);
                    node->data = tmp;
                }
                else
                {
                    int tmp = r_tree_min->data;
                    this->erase(r_tree_min->data);
                    node->data = tmp;
                }
            }
            return true;
        }

    void clear()
    {
        if(this != nullptr)
        {
            this->left->clear();
            this->right->clear();
            delete this;
            return;
        }
        else
        {
            return;
        }
    }


    //БАЛАНСИРОВКА ДЕРЕВА

    void balance()
    {
        // Получаем отсортированный массив значений из дерева
        std::vector<int> values;
        inorderTraversal(this, values);

        // Создаем новое сбалансированное дерево
        Tree* balancedTree = buildBalancedTree(values, 0, values.size() - 1);

        // Заменяем текущее дерево на сбалансированное
        *this = *balancedTree;
    }

    // Рекурсивный обход дерева в порядке возрастания значений
    void inorderTraversal(Tree* node, std::vector<int>& values)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left, values);
        values.push_back(node->data);
        inorderTraversal(node->right, values);
    }

    // Рекурсивное построение сбалансированного дерева из отсортированного массива
    Tree* buildBalancedTree(const std::vector<int>& values, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Tree* newNode = new Tree(values[mid]);

        newNode->left = buildBalancedTree(values, start, mid - 1);
        if (newNode->left != nullptr)
            newNode->left->parent = newNode;

        newNode->right = buildBalancedTree(values, mid + 1, end);
        if (newNode->right != nullptr)
            newNode->right->parent = newNode;

        return newNode;
    }

    // Вертикальная печать дерева
    std::string verticalPrint()
        {
            std::queue<Tree*> nodes;
            std::queue<int> levels;
            std::string result;

            if (this != nullptr)
            {
                nodes.push(this);
                levels.push(0);
            }

            int currentLevel = 0;
            while (!nodes.empty())
            {
                Tree* node = nodes.front();
                nodes.pop();

                int level = levels.front();
                levels.pop();

                if (level > currentLevel)
                {
                    result += '\n';
                    currentLevel = level;
                }

                result += std::to_string(node->data);
                result += ' ';

                if (node->left != nullptr)
                {
                    nodes.push(node->left);
                    levels.push(level + 1);
                }

                if (node->right != nullptr)
                {
                    nodes.push(node->right);
                    levels.push(level + 1);
                }
            }

            return result;
        }

};

// ГОРИЗОНТАЛЬНАЯ ПЕЧАТЬ
struct HorizontalPrint
{
    void getextremes(Tree* tnode, int* minimumd, int* maximumd, int hordist)
    {
        if (tnode == nullptr)
        {
            return;
        }
        if (hordist < *minimumd)
        {
            *minimumd = hordist;
        }
        else if (hordist > *maximumd)
        {
            *maximumd = hordist;
        }
        getextremes(tnode->left, minimumd, maximumd, hordist - 1);
        getextremes(tnode->right, minimumd, maximumd, hordist + 1);
    }

    void printvl(Tree* node, int lno, int hordist, std::string* res)
    {
        if (node == nullptr)
        {
            return;
        }
        if (hordist == lno)
        {
            *res += std::to_string(node->data) + " ";
        }
        printvl(node->left, lno, hordist - 1, res);
        printvl(node->right, lno, hordist + 1, res);
    }

    std::string vertiorder(Tree* root)
    {
        int minimumd = 0, maximumd = 0;
        std::string RESULT;
        getextremes(root, &minimumd, &maximumd, 0);
        for (int lno = minimumd; lno <= maximumd; lno++)
        {
            printvl(root, lno, 0, &RESULT);
            RESULT += '\n';
        }
        return RESULT;
    }

    std::string operator() (Tree* tree)
    {
        return vertiorder(tree);
    }
};

struct BinTree
{
    Tree* root;

    BinTree()
    {
        root = nullptr;
    }

    BinTree(int val)
    {
        root = new Tree(val, nullptr, nullptr, nullptr);
    }

    void insert(int val)
    {
        this->root->insert(val);
    }

    Tree* find(int val)
    {
        return (this->root->find(val));
    }

    bool erase(int val)
    {
        return (this->root->erase(val));
    }

    void balance()
    {
        if(this->root != nullptr)
        {
            this->root->balance();
        }
    }

    void clear()
    {
        this->root->clear();
        this->root = nullptr;
    }

    std::string printV()
    {
        return this->root->verticalPrint();
    }

    std::string printH()
    {
        HorizontalPrint HP;
        return HP(this->root);
    }

};
