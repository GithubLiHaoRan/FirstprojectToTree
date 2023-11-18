#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a=0;
typedef struct TreeNode   //��������㶨��
{
    struct TreeNode *lchild,*rchild;  // ��ַ��
    char data;   // ������
} RTreeNode; //

RTreeNode *initnode(char data,RTreeNode *lchild,RTreeNode *rchild) //����һ�����������
{
    RTreeNode *SS;
    SS=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    SS->data=data;
    SS->lchild=lchild;
    SS->rchild=rchild;
    return(SS);
}

RTreeNode *inittree()  //����һ�ö�����
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

void preorder(RTreeNode *p) //���������������p�Ǹ����ָ��
{
    if(p!=NULL)
    {
        printf("%c ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(RTreeNode *p) //���������������p�Ǹ����ָ��
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%c ",p->data);
        inorder(p->rchild);
    }
}

void postorder(RTreeNode *p) //���������������p�Ǹ����ָ��
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c ",p->data);
    }
}

int count(RTreeNode *p) //������������н�� ��Ŀ
{
    if(p==NULL)
        return(0);
    else
        return(1+count(p->lchild)+count(p->rchild));
}


int leafcount(RTreeNode *p) //���������Ҷ�ӽ����Ŀ
{
    //ѧ�����
    if(p==NULL)
        return(0);
    else if(p->lchild==NULL&&p->rchild==NULL){return 1;}
    else return (leafcount(p->lchild)+ leafcount(p->rchild));
}


int lcount(RTreeNode *p) //������������е�Сд�����Ŀ
{
    //ѧ�����
    if(p==NULL)
        return(0);
    else if(p->data>=97&&p->data<=122){return 1+lcount(p->lchild)+ lcount(p->rchild);}
    else return(lcount(p->rchild)+ lcount(p->lchild));
}


int subln(RTreeNode *p) //������������е�Сд�����Ŀ�ͷ�Сд��ĸ�����Ŀ֮��
{
    //˼����
    //����һ��
    //return -((count(p)- lcount(p))- lcount(p));//����һ��һ�д���͸㶨ֱ�ӵ���֮ǰ�ĺ���

    //��������
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

// //������ֵx��y��z����Сֵ
char cmin(char x,char y,char z)
{
    if((x<=y)&&(x<=z))
        return(x);

    if((y<x)&&(y<z))
        return(y);

    return(z);
}

//�����������С��Сд��ĸ�����û��Сд��ĸ������'{'
char minlc(RTreeNode *p)
{
    //˼����
    if(p==NULL)
        return('{');
    else if(p->data>=97&&p->data<=122){return cmin(p->data,p->rchild->data,p->lchild->data);}
        //else return(cmin(p,p->rchild,p->lchild));
    else
        return cmin('z' + 1, minlc(p->rchild), minlc(p->lchild));
}


int main()
{
    RTreeNode *tree;  //���������

/*	printf("��������:\n");
	preorder(tree);    //�������������
	printf("\n");
	printf("��������:\n");
	inorder(tree);    //�������������
	printf("\n");
	printf("��������:\n");
	postorder(tree);    //�������������
	printf("\n");
    printf("�������Ľ����ĿΪ:%d\n",count(tree));
    printf("��������Ҷ�ӽ����ĿΪ:%d\n",leafcount(tree));
    printf("��������Сд��ĸ�����ĿΪ:%d\n",lcount(tree));
    printf("��������Сд�ͷ�Сд�����Ŀ֮��Ϊ:%d\n",subln(tree));
    printf("����������С��Сд��ĸΪ:%c\n",minlc(tree));
	printf("\n");  */
    printf("************************************\n");

    printf("��ӭ������׶�����ϵͳ\n");
    printf("\n");
    printf("ѡ�����\n");
    printf("1   ����������\n");
    printf("2   �������������\n");
    printf("3   �������������\n");
    printf("4   �������������\n");
    printf("5   ��������Ľ����Ŀ\n");
    printf("6   �������Ҷ�ӽ����Ŀ\n");
    printf("7   ���������Сд��ĸ�����Ŀ\n");
    printf("8   ��Сд�ͷ�Сд�����Ŀ֮��\n");
    printf("9   �����������С��Сд��ĸ\n");
    printf("10  �˳�\n");
    printf("************************************\n");

    int c;
    printf("��ѡ�����:\n");
    scanf("%d",&c);
    if(c>=1&&c<=10)
        while(c>0)
        {
            switch(c)
            {
                case 1:{
                    tree=inittree();    //���ɶ�����
                    break;
                }
                case 2:{
                    printf("��������:\n");
                    preorder(tree);    //�������������
                    printf("\n");
                    break;
                }
                case 3:{
                    printf("��������:\n");
                    inorder(tree);    //�������������
                    printf("\n");
                    break;
                }
                case 4:{
                    printf("��������:\n");
                    postorder(tree);    //�������������
                    printf("\n");
                    break;
                }
                case 5:{
                    printf("�������Ľ����ĿΪ:%d\n",count(tree));
                    break;
                }
                case 6:{
                    printf("��������Ҷ�ӽ����ĿΪ:%d\n",leafcount(tree));
                    break;
                }
                case 7:{
                    printf("��������Сд��ĸ�����ĿΪ:%d\n",lcount(tree));
                    break;
                }
                case 8:{
                    printf("��������Сд�ͷ�Сд�����Ŀ֮��Ϊ:%d\n",subln(tree));
                    break;
                }
                case 9:{
                    printf("����������С��Сд��ĸΪ:%c\n",minlc(tree));
                    //printf("%c",min3('a','b','c'));
                    break;
                }
                case 10:{
                    exit(0);
                }
            }
            printf("��ѡ�����:\n");
            scanf("%d",&c);
        }
    else
    {
        printf("ѡ���ֵ���Ϸ�:\n");
        exit(0);
    }
    return(0);
}