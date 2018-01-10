#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

#define IN 0
#define PRE 1
#define POST 2

//node

template <typename T>
struct BinaryTreeNode{
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

void insert_level(unique_ptr<BinaryTreeNode<int>> &root, const int val){
	queue <unique_ptr<BinaryTreeNode<int>>> q ;	
	q.push(move(root));
	while (!q.empty()){
		// cant directly push back without move as unique ptr does not allow duplicate ownership
		unique_ptr<BinaryTreeNode<int>> nxt;
		nxt = move(q.front());
		q.pop();
		// get the first element from front and process
		if (NULL == nxt->left){
			unique_ptr<BinaryTreeNode<int>> tmp_node (new (BinaryTreeNode<int>));
			tmp_node->data = val;
			tmp_node->left = NULL;
			tmp_node->right = NULL;
			nxt->left = move(tmp_node);
			return;				
		}else {
			q.push(move(nxt->left));
		}
		if (NULL == nxt->right){
			unique_ptr<BinaryTreeNode<int>> tmp_node (new (BinaryTreeNode<int>));
			tmp_node->data = val;
			tmp_node->left = NULL;
			tmp_node->right = NULL;
			nxt->right = move(tmp_node);
			return;				
		}else {
			q.push(move(nxt->right));
		}

	}
	
}

void insert(unique_ptr <BinaryTreeNode<int>> &root ,const int val){
	if (root == NULL){
		//insert at root
		unique_ptr<BinaryTreeNode<int>> node (new (BinaryTreeNode<int>));
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		root = move(node);
	}else {
		//find the first free space at a level and insert
		if (root->left == NULL){
                	unique_ptr<BinaryTreeNode<int>> node (new (BinaryTreeNode<int>));
                	node->data = val;
                	node->left = NULL;
                	node->right = NULL;
			root->left = move(node);
			return;
		} else if (root->right == NULL){
                        unique_ptr<BinaryTreeNode<int>> node (new (BinaryTreeNode<int>));
                        node->data = val;
                        node->left = NULL;
                        node->right = NULL;
                        root->right = move(node);
                        return;
		}else{
			insert(root->left, val);
		}
	}	
}

void print_tree(const unique_ptr <BinaryTreeNode<int>> &root, int traversal_type) {
	switch (traversal_type) {
		case IN:
			if (root == NULL){
				return;
			}else{
				print_tree(root->left,IN);
				cout << root->data << endl;
				print_tree(root->right,IN);
			}
			
			break;	
		case PRE:
			if (root == NULL){
				return;
			}else{
				cout << root->data << endl;
				print_tree(root->left,PRE);
				print_tree(root->right,PRE);
			}
			break;	
		case POST:
			if (root == NULL){
				return;
			}else{
				print_tree(root->left,POST);
				print_tree(root->right,POST);
				cout << root->data << endl;
			}
			break;	
		default:
			break;
	}
}

int main(){
	unique_ptr <BinaryTreeNode<int>> root = NULL;
	insert_level (root, 5);
/*
	insert_level (root, 6);
	insert_level (root, 7);
	insert_level (root, 8);
	insert_level (root, 9);
	insert_level (root, 10);
	insert_level (root, 11);
*/
	cout << "IN" << endl;	
	print_tree(root, IN);
	cout << "PRE" << endl;	
	print_tree(root, PRE);
	cout << "POST" << endl;	
	print_tree(root, POST);
	return 0;
}
