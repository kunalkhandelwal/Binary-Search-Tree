#define MAX 10
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
typedef struct node tree;
void opr();
tree* create(int *,int);
void traverse(tree *);
void preorder(tree *);
void postorder(tree *);
void inorder(tree *);
void levelorder(tree *);
int height(tree *root);
void nodes_level(tree *,int);
int search(tree *,int);
void main()
{
	opr();
}
void opr()
{
	int *a,c=1,i=0,h=0,key,flag=0,p=0;
	tree *root=NULL;
	a=(int *)calloc(MAX,sizeof(int));
	a[MAX-1]=99;
	while(a[i]!=99)
	{
		printf("Enter the data: ");
		scanf("%d",&a[i]);
		i++;
	}
	while(c!=0)
	{	
		printf("\n		***********MENU***********\n1. Create\n2. Traverse\n3. Height\n4. Search\nChoose the Operation or 0 to Exit: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				root=create(a,p);
				traverse(root);
				break;
			case 2:
				traverse(root);
				break;
			case 3:
			        h=height(root);
			        printf("Height of the Tree is %d.",h);
			        break;
			case 4:
               		    	printf("\nEnter the Search Value: ");
                		scanf("%d",&key);
			        flag = search(root,key);
			        if(flag == 0)
			            printf("\n%d is not found.\n",key);
			        break;
			case 5:
				opr();
			case 0:
				printf("\n			***********EXIT***********\n");
				exit(0);
			default:
				printf("\n Invalid Choice. ");
		}	
	}
}
tree* create(int a[],int p)
{
	tree *t;
	if(p<(MAX-1) && a[p]!=99 && a[p]!=-1)
	{
    		t=(tree *)malloc(sizeof(t));
    		if(t==NULL)
    		{
    	    		printf("\nNot able to create a node.\n");
    	   		return(t);
    		}   
		t->data= a[p];
		t->left=create(a,2*p+1);
		t->right=create(a,2*p+2);
	}
	else
		t=NULL;
	return(t);
}
void traverse(tree *root)
{
	int c;
	printf("\n			******Types of Traverse******\n1. Pre-Order\n2. in-Order\n3. Post-Order\n4. Level-Order\n5. Menu\n  Choose the type of Traverse[1-4] or 0 to Exit: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			preorder(root);
			break;
		case 2:
			inorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			levelorder(root);
			break;
		case 5:
             		opr();
		case 0:
		        printf("\n			***********EXIT***********\n");
		        exit(0);
		default:
				printf("\n Invalid Choice. ");
				traverse(root);
	}
}
void preorder(tree *root)
{
	if(root!=NULL)
	{
		if(root->data!=-1)
			printf(" %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}
void postorder(tree *root)
{
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            if(root->data!=-1)
                printf(" %d ",root->data);
        }
}
void inorder(tree *root)
{
        if(root!=NULL)
        {
            inorder(root->left);
            if(root->data!=-1)
                printf(" %d ",root->data);
            inorder(root->right);
        }
}
void levelorder(tree *root)
{
    int h,level=0;
    h=height(root);
    while(level<=h)
    {
        nodes_level(root,level);
        level++;
    }
}
int height(tree *root)
{
    int lh,rh;
    if(root->left==NULL && root->right==NULL)
        return (0);
    if(root==NULL)
        return (1);
    lh=height(root->left);
    rh=height(root->right);
    if(lh>=rh)
        return(lh+1);
    else
        return(rh+1);
}   
void nodes_level(tree *root,int level)
{
    if(root==NULL)
        return;
    if(level==0)
        printf(" %d ",root->data);
    nodes_level(root->left,level-1);
    nodes_level(root->right,level-1);
}
int search(tree *root,int key)
{
	int flag = 0;
	if(root!=NULL)
	{
		if(root->data==key)
		{
			    printf("\n%d is found.\n",key);
			    flag=1;
			    return(flag);
		}
		flag = search(root->left,key);
                flag = search(root->right,key);
	}	
}
