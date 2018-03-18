//just translated my Python code into C++ & fixed some minor bugs (haven't added manual memory clear btw, i'll try to add it in future)
#include <fstream>
#include <iostream>
std::ifstream infile("in.txt");
std::ofstream outfile("out.txt");

int max_semipath = -1, counter = 0, needed_data = 0;

void delete_sub(struct node* root, struct node* n);
void delete_node(struct node* root, struct node *n);
void replace_child(struct node* root, struct node* p, struct node* old_n, struct node* new_n);

struct node
{
	int  data, semipath = 0, height = 0;
	struct node *l_child, *r_child, *parent;
};

struct node *new_node(int item)
{
	struct node *temp = new node();
	temp->data = item;
	temp->l_child = temp->r_child = nullptr;
	return temp;
}


struct node* insert(struct node* node, int value)
{
	if (node == nullptr) return new_node(value);

	if (value < node->data)
	{
		node->l_child = insert(node->l_child, value);
		node->l_child->parent = node;
	}
	else if (value > node->data)
	{
		node->r_child = insert(node->r_child, value);
		node->r_child->parent = node;
	}
	return node;
}




long long semipath(struct node *node)
{
	if (node == nullptr)
		return 0;
	long long left_height = semipath(node->l_child);
	long long  right_height = semipath(node->r_child);
	node->semipath = left_height + right_height;
	node->height = (left_height > right_height) ? left_height + 1 : right_height + 1;
	if (node->semipath > max_semipath)
	{
		max_semipath = node->semipath;
		counter = 1;
		needed_data = node->data;
	}
	else if (node->semipath == max_semipath)
		counter++;
	return node->height;
}

struct node* find(struct node* n, int data)
{
	while (n)
	{
		if (data < n->data)
			n = n->l_child;
		else if (data > n->data)
			n = n->r_child;
		else
			break;
	}
	return n;
}

void delete_chunk(struct node* root, struct node* node)
{
	if (node)
	{
		if (counter == 1)
		{
			delete_sub(root, node->r_child);
			delete_sub(root, node->l_child);
			delete_node(root, node);
		}
		else
		{
			delete_sub(root, node);
		}

	}

}

void delete_sub(struct node* root, struct node* n)
{
	if (n)
	{
		if (n->l_child && n->r_child)
		{
			if (n->l_child->height > n->r_child->height)
				delete_sub(root, n->l_child);
			else if (n->l_child->height < n->r_child->height)
				delete_sub(root, n->r_child);
			delete_node(root, n);
		}
		else if (!n->l_child && !n->r_child)
		{
			delete_node(root, n);
		}
		else
		{
			if (n->r_child)
				delete_sub(root, n->r_child);
			else
				delete_sub(root, n->l_child);
			delete_node(root, n);
		}

	}

}

void delete_node(struct node* root, struct node *n)
{
	node *result = nullptr;
	if (n)
	{
		if (!n->r_child) 
			result = n->l_child;
		else if (!n->l_child) 
			result = n->r_child;
		
		else
		{
			node *min_node = n->r_child;
			while (min_node->l_child != nullptr)
				min_node = min_node->l_child;

			result = n;
			n->data = min_node->data;
			replace_child(root, min_node->parent, min_node, min_node->r_child);
		}
		replace_child(root, n->parent, n, result);
	}
}

void replace_child(struct node *root, struct node* p, struct node* old_n, struct node* new_n)
{
	if (!p)
	{
		new_n->parent = nullptr;
		*root = *new_n;
	}
	else if (p->l_child == old_n)
	{
		p->l_child = new_n;
		if (new_n)
			new_n->parent = p;
	}
	else if (p->r_child == old_n)
	{
		p->r_child = new_n;
		if (new_n)
			new_n->parent = p;
	}
}


void preorder(struct node *root)
{
	if (root != nullptr)
	{
		outfile << root->data << "\n";
		preorder(root->l_child);
		preorder(root->r_child);
	}
}

int main()
{
	int  temp_value;
	node *root = nullptr;
	while (infile >> temp_value)
		root = insert(root, temp_value);
	semipath(root);
	node *start_node = find(root, needed_data);
	delete_chunk(root, start_node);
	preorder(root);
}