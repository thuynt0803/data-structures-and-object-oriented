typedef struct childlist
{
    typelabel lable; // nhãn của một nút trên cây
    childlist *next;
} childlist;
typedef struct node
{
    typedata data;
    childlist *children;
} node;
node tree[maxsize];
