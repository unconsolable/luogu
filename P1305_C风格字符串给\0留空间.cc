/*char数组记得给终止符留空间*/
#include <iostream>
#include <cstdio>
#include <string>
struct LinkTree
{
    char data;
    LinkTree *left = nullptr;
    LinkTree *right = nullptr;
    ~LinkTree();
private:
    void del(LinkTree *tr);
};
void LinkTree::del(LinkTree *tr)
{
    if (tr->left)
        del(tr->left);
    if (tr->right)
        del(tr->right);
    delete tr;
}
LinkTree::~LinkTree() { del(this); }
LinkTree *Find(LinkTree *tr, char data)
{
    if (tr->data == data)
        return tr;
    LinkTree *left = nullptr, *right = nullptr;
    if (tr->left)
        left = Find(tr->left, data);
    if (tr->right)
        right = Find(tr->right, data);
    if (!left && !right)
        return nullptr;
    else
    {
        if (left)
            return left;
        else
            return right;
    }
}
void First(LinkTree *tr)
{
    printf("%c",tr->data);
    if (tr->left)
        First(tr->left);
    if (tr->right)
        First(tr->right);
    return;
}
int main()
{
    LinkTree *tr1 = new LinkTree();
    int numNode;
    std::cin >> numNode;
    bool isFirst = true;
    for (int i = 0; i < numNode; ++i)
    {
        //char tmpchar[4];
        std::string tmpchar;
        std::cin >> tmpchar;
        LinkTree *result = Find(tr1, tmpchar[0]);
        if (result || isFirst)
        {
            if (isFirst)
            {
                isFirst = false;
                result = tr1;
                result->data = tmpchar[0];
            }
            if (tmpchar[1] != '*')
            {
                LinkTree *tmpnode = new LinkTree();
                tmpnode->data = tmpchar[1];
                result->left = tmpnode;
            }
            if (tmpchar[2] != '*')
            {
                LinkTree *tmpnode = new LinkTree();
                tmpnode->data = tmpchar[2];
                result->right = tmpnode;
            }
        }
    }
    First(tr1);
    std::cout<<std::endl;
}