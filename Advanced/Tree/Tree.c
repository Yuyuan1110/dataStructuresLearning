# include <stdio.h>
# include <stdlib.h>
struct Node{
	int val;
	struct Node* left;
	struct Node* right;
	int height;
};

struct Node* createNode(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode -> val = val;
	newNode -> right = NULL;
	newNode -> left = NULL;
	newNode -> height = 0;
	return newNode;
}

int getHeight(struct Node *node){
	if(node == NULL){
		return -1;
	}
	return node -> height;
}

int getBalance(struct Node *node){
	if(node == NULL){
		return 0;
	}

	return getHeight(node -> left) - getHeight(node -> right);
}

struct Node* leftRotate(struct Node *node){
	struct Node *temp = node -> right;
	struct Node *T2 = temp -> left;

	temp -> left = node;
	node -> right = T2;

	node -> height = 1 + (getHeight(node -> left) > getHeight(node -> right) ? getHeight(node -> left) : getHeight(node -> right));
	temp -> height = 1 + (getHeight(node -> left) > getHeight(node -> right) ? getHeight(node -> left) : getHeight(node -> right));

	return temp;
}


struct Node* rightRotate(struct Node *node){
	struct Node *temp = node -> left;
	struct Node *T2 = temp -> right;

	temp -> right = node;
	node -> left = T2;

	node -> height = 1 + (getHeight(node -> left) > getHeight(node -> right) ? getHeight(node -> left) : getHeight(node -> right));
	temp -> height = 1 + (getHeight(node -> left) > getHeight(node -> right) ? getHeight(node -> left) : getHeight(node -> right));

	return temp;
}

struct Node* AVLUpdate(struct Node *node, int val){

	node -> height = 1 + (getHeight(node -> left) > getHeight(node -> right) ? getHeight(node -> left) : getHeight(node -> right));

	if(getBalance(node) > 1){
		if(val < node -> left ->val){
			node = rightRotate(node);
		}else{
			node -> left = leftRotate(node -> left);
			node  = rightRotate(node);	
		}
	}

	if(getBalance(node) < -1){
		if(val > node -> right -> val){
			node  = leftRotate(node);
		}else{
			node -> right = rightRotate(node -> right);
			node  = leftRotate(node);
		}
	}

	return node;
}

struct Node* insertNode(struct Node *node, int val){
	if(node == NULL){
		return createNode(val);
	}

	if(val > node -> val){
		node -> right = insertNode(node -> right, val);	
	}

	if(val < node -> val){
		node -> left = insertNode(node -> left, val);
	}

	node = AVLUpdate(node, val);
	return node;
}

struct Node* findMin(struct Node *node){
	while(node -> left != NULL){
		node = node -> left;
	}
	return node;
}

struct Node* deleteNode(struct Node *node, int val){
	if(node == NULL){
		return node;
	}else if(val > node -> val){
		node -> right = deleteNode(node -> right, val);
	}else if(val < node -> val){
		node -> left = deleteNode(node -> left, val);
	}else{
		if(node -> right == NULL){
			struct Node *temp = node -> left;	
			free(node);
			return temp;
		}

		if(node -> left == NULL){
			struct Node *temp = node -> right;
			free(node);
			return temp;
		}

		struct Node *temp = findMin(node -> right);
		node -> val = temp -> val;
		node -> right = deleteNode(node -> right, temp -> val);
	}

	node = AVLUpdate(node, val);
	return node;
}

void inorder(struct Node *node){
	if(node != NULL){
		inorder(node -> left);
		printf("%d", node -> val);
		inorder(node -> right);
	}
}

int main() {
	struct Node *node = createNode(3);
	node = insertNode(node, 2);
	node = insertNode(node, 1);
	node = insertNode(node, 0);
	inorder(node);
	printf("\n");
	return 0;
}

