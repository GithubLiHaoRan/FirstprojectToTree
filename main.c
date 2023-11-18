#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a=0;
typedef struct TreeNode   //二叉树结点定义
{
    struct TreeNode *lchild,*rchild;  // 地址域
    char data;   // 数据域
} RTreeNode; //

RTreeNode *initnode(char data,RTreeNode *lchild,RTreeNode *rchild) //生成一个二叉树结点
{
    RTreeNode *SS;
    SS=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    SS->data=data;
    SS->lchild=lchild;
    SS->rchild=rchild;
    return(SS);
}

RTreeNode *inittree()  //生成一棵二叉树
{
    RTreeNode *root,*A,*B,*C,*D,*E,*F,*G;
    C=initnode('c',NULL,NULL);
    D=initnode('#',NULL,NULL);
    F=initnode('&',NULL,NULL);
    E=initnode('%',F,NULL);
    B=initnode('b',NULL,E);
    A=initnode('a',D,C);
    root=initnode('r',A,B);
    return(root);
}

void preorder(RTreeNode *p) //先序遍历二叉树，p是根结点指针
{
    if(p!=NULL)
    {
        printf("%c ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(RTreeNode *p) //中序遍历二叉树，p是根结点指针
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%c ",p->data);
        inorder(p->rchild);
    }
}

void postorder(RTreeNode *p) //后序遍历二叉树，p是根结点指针
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c ",p->data);
    }
}

int count(RTreeNode *p) //求二叉树的所有结点 数目
{
    if(p==NULL)
        return(0);
    else
        return(1+count(p->lchild)+count(p->rchild));
}


int leafcount(RTreeNode *p) //求二叉树的叶子结点数目
{
    //学生完成
    if(p==NULL)
        return(0);
    else if(p->lchild==NULL&&p->rchild==NULL){return 1;}
    else return (leafcount(p->lchild)+ leafcount(p->rchild));
}


int lcount(RTreeNode *p) //求二叉树的所有的小写结点数目
{
    //学生完成
    if(p==NULL)
        return(0);
    else if(p->data>=97&&p->data<=122){return 1+lcount(p->lchild)+ lcount(p->rchild);}
    else return(lcount(p->rchild)+ lcount(p->lchild));
}


int subln(RTreeNode *p) //求二叉树的所有的小写结点数目和非小写字母结点数目之差
{
    //思考题
    //方法一：
    //return -((count(p)- lcount(p))- lcount(p));//方法一：一行代码就搞定直接调用之前的函数

    //方法二：
    if (p == NULL)
        return 0;
    else if (p->data >= 97 && p->data <= 122) {
        return 1+subln(p->lchild)+ subln(p->rchild);
    }
    else {
        int a=-1;
        return a+subln(p->rchild) + subln(p->lchild);
    }
}

// //求三个值x、y和z的最小值
char cmin(char x,char y,char z)
{
    if((x<=y)&&(x<=z))
        return(x);

    if((y<x)&&(y<z))
        return(y);

    return(z);
}

//求二叉树中最小的小写字母，如果没有小写字母，返回'{'
char minlc(RTreeNode *p)
{
    //思考题
    if(p==NULL)
        return('{');
    else if(p->data>=97&&p->data<=122){return cmin(p->data,p->rchild->data,p->lchild->data);}
        //else return(cmin(p,p->rchild,p->lchild));
    else
        return cmin('z' + 1, minlc(p->rchild), minlc(p->lchild));
}


int main()
{
    RTreeNode *tree;  //定义二叉树

/*	printf("先序结果是:\n");
	preorder(tree);    //先序遍历二叉树
	printf("\n");
	printf("中序结果是:\n");
	inorder(tree);    //中序遍历二叉树
	printf("\n");
	printf("后序结果是:\n");
	postorder(tree);    //后序遍历二叉树
	printf("\n");
    printf("二叉树的结点数目为:%d\n",count(tree));
    printf("二叉树的叶子结点数目为:%d\n",leafcount(tree));
    printf("二叉树的小写字母结点数目为:%d\n",lcount(tree));
    printf("二叉树的小写和非小写结点数目之差为:%d\n",subln(tree));
    printf("二叉树中最小的小写字母为:%c\n",minlc(tree));
	printf("\n");  */
    printf("************************************\n");

    printf("欢迎进入简易二叉树系统\n");
    printf("\n");
    printf("选择操作\n");
    printf("1   创建二叉树\n");
    printf("2   先序遍历二叉树\n");
    printf("3   中序遍历二叉树\n");
    printf("4   后序遍历二叉树\n");
    printf("5   求二叉树的结点数目\n");
    printf("6   求二叉树叶子结点数目\n");
    printf("7   求二叉树的小写字母结点数目\n");
    printf("8   求小写和非小写结点数目之差\n");
    printf("9   求二叉树中最小的小写字母\n");
    printf("10  退出\n");
    printf("************************************\n");

    int c;
    printf("请选择操作:\n");
    scanf("%d",&c);
    if(c>=1&&c<=10)
        while(c>0)
        {
            switch(c)
            {
                case 1:{
                    tree=inittree();    //生成二叉树
                    break;
                }
                case 2:{
                    printf("先序结果是:\n");
                    preorder(tree);    //先序遍历二叉树
                    printf("\n");
                    break;
                }
                case 3:{
                    printf("中序结果是:\n");
                    inorder(tree);    //中序遍历二叉树
                    printf("\n");
                    break;
                }
                case 4:{
                    printf("后序结果是:\n");
                    postorder(tree);    //后序遍历二叉树
                    printf("\n");
                    break;
                }
                case 5:{
                    printf("二叉树的结点数目为:%d\n",count(tree));
                    break;
                }
                case 6:{
                    printf("二叉树的叶子结点数目为:%d\n",leafcount(tree));
                    break;
                }
                case 7:{
                    printf("二叉树的小写字母结点数目为:%d\n",lcount(tree));
                    break;
                }
                case 8:{
                    printf("二叉树的小写和非小写结点数目之差为:%d\n",subln(tree));
                    break;
                }
                case 9:{
                    printf("二叉树中最小的小写字母为:%c\n",minlc(tree));
                    //printf("%c",min3('a','b','c'));
                    break;
                }
                case 10:{
                    exit(0);
                }
            }
            printf("请选择操作:\n");
            scanf("%d",&c);
        }
    else
    {
        printf("选择的值不合法:\n");
        exit(0);
    }
    return(0);
}