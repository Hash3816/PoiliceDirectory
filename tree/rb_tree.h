#pragma once
#include "I_tree.h"
#include "../Pair.h"
#include "../list.h"
#include "string"
#include <sstream>
#include <iostream>


template <typename Key, typename Value> 
class RB_tree:public ITree<Key,Value>{
private:
    enum class ColorNode {
        red,
        black,
    };

	struct Node {
		Key key;
		List<Value>* list;
        ColorNode color;

		Node* left;
		Node* right;
		Node* parent;
	};

	Node* root;
	Node* nil;

    std::string color_node_to_string(const ColorNode& color) const{
        return (color == ColorNode::black ? "B" : "R");
    }

	void left_rotate(Node* subtree) {
		Node* right_node = subtree->right;
		subtree->right = right_node->left;

		if (right_node->left != nil) {
			right_node->left->parent = subtree;
		}

		right_node->parent = subtree->parent;
		if (subtree->parent == nil) {
			root = right_node;
		}

		else if (subtree == subtree->parent->left) {
			subtree->parent->left = right_node;
		}

		else {
			subtree->parent->right = right_node;
		}

		right_node->left = subtree;
		subtree->parent = right_node;
	}

	void right_rotate(Node* subtree) {
        Node* left_node = subtree->left; //Сохраняем адрес левого дочернего узла

        subtree->left = left_node->right;
		if (left_node->right != nil) {
            left_node->right->parent = subtree;
		}

        left_node->parent = subtree->parent;
		if (subtree->parent == nil) {
			root = left_node;
		}

		else if (subtree == subtree->parent->right) {
			subtree->parent->right = left_node;
		}
		else {
			subtree->parent->left = left_node;
		}

		left_node->right = subtree;
		subtree->parent = left_node;
	}

	void insert_fixup(Node* new_node) {
        while (new_node->parent->color == ColorNode::red) {

            if (new_node->parent == new_node->parent->parent->left) {
				Node* uncle_node = new_node->parent->parent->right;

                if (uncle_node->color == ColorNode::red) {
                    new_node->parent->color = ColorNode::black;
                    uncle_node->color = ColorNode::black;
                    new_node->parent->parent->color = ColorNode::red;
                    new_node = new_node->parent->parent;
				}

                else { // Дядя чёрный
                    if (new_node == new_node->parent->right) {
						new_node = new_node->parent;
                        left_rotate(new_node);
					}

                    new_node->parent->color = ColorNode::black;
                    new_node->parent->parent->color = ColorNode::red;
                    right_rotate(new_node->parent->parent);
				}
			}

			else { 
				Node* uncle_node = new_node->parent->parent->left;

                if (uncle_node->color == ColorNode::red) {
                    new_node->parent->color = ColorNode::black;
                    uncle_node->color = ColorNode::black;
                    new_node->parent->parent->color = ColorNode::red;
					new_node = new_node->parent->parent;
				}

				else {
					if (new_node == new_node->parent->left) {
						new_node = new_node->parent;
						right_rotate(new_node);
					}

                    new_node->parent->color = ColorNode::black;
                    new_node->parent->parent->color = ColorNode::red;
					left_rotate(new_node->parent->parent);
				}
			}
		}
        root->color = ColorNode::black;
	}

	void erase_fixup(Node* replacement_node) {
        while (replacement_node != root && replacement_node->color == ColorNode::black) {

			if (replacement_node == replacement_node->parent->left) {

				Node* neighbor = replacement_node->parent->right;
                if (neighbor->color == ColorNode::red) {
                    neighbor->color = ColorNode::black;
                    replacement_node->parent->color = ColorNode::red;
					left_rotate(replacement_node->parent);
					neighbor = replacement_node->parent->right;
				}

                if ((neighbor->left->color == ColorNode::black) && (neighbor->right->color == ColorNode::black)) {
                    neighbor->color = ColorNode::red;
					replacement_node = replacement_node->parent;
				}

				else {
                    if (neighbor->right->color == ColorNode::black) {
                        neighbor->left->color = ColorNode::black;
                        neighbor->color = ColorNode::red;
						right_rotate(neighbor);
						neighbor = replacement_node->parent->right;
					}

					neighbor->color = replacement_node->parent->color;
                    replacement_node->parent->color = ColorNode::black;
                    neighbor->right->color = ColorNode::black;
					left_rotate(replacement_node->parent);
					replacement_node = root;
				}
			}

			else {
				Node* neighbor = replacement_node->parent->left;
                if (neighbor->color == ColorNode::red) {
                    neighbor->color = ColorNode::black;
                    replacement_node->parent->color = ColorNode::red;
					right_rotate(replacement_node->parent);
					neighbor = replacement_node->parent->left;
				}

                if ((neighbor->right->color == ColorNode::black) && (neighbor->left->color == ColorNode::black)) {
                    neighbor->color = ColorNode::red;
					replacement_node = replacement_node->parent;
				}

				else {
                    if (neighbor->left->color == ColorNode::black) {
                        neighbor->right->color = ColorNode::black;
                        neighbor->color = ColorNode::red;
						left_rotate(neighbor);
						neighbor = replacement_node->parent->left;
					}

					neighbor->color = replacement_node->parent->color;
                    replacement_node->parent->color = ColorNode::black;
                    neighbor->left->color = ColorNode::black;
					right_rotate(replacement_node->parent);
					replacement_node = root;
				}
			}
		}
        replacement_node->color = ColorNode::black;
	}

	void transplant(Node* u, Node* v) {
		if (u->parent == nil) {
			root = v;
		}
		else if (u == u->parent->left) {
			u->parent->left = v;
		}
		else {
			u->parent->right = v;
		}

		v->parent = u->parent;
	}

	Node* minimum(Node* subtree) const  {
		while (subtree->left != nil) {
			subtree = subtree->left;
		}
		return subtree;
	}

	
	void _inorder_walk(Node* node, std::stringstream& result) const{
		if (node != nil) {
			_inorder_walk(node->left, result);
            result <<  color_node_to_string(node->color) << ": " << (node->key) << "->";
			result << node->list->to_string();
			result << "\n";
			_inorder_walk(node->right, result);
		}
	}

	
	void _print(Node* node, unsigned int level = 0) const{
		if (node != nil) {
            _print(node->right, level + 1);
            std::cout << std::string(level * 8, ' ') << color_node_to_string(node->color) << ": " << node->key << "->";
			node->list->print();
			std::cout << "\n";
            _print(node->left, level + 1);
		}
	}

    Node* _find_node(const Key& key){
        Node* current_node = root;
        while(current_node != nil){
            if(key < current_node->key){
                current_node = current_node ->left;
            }
            else if(key > current_node->key){
                current_node = current_node->right;
            }
            else{
                return current_node;
            }
        }
        return current_node;
    }

	void _to_string(Node* node, std::stringstream& result, unsigned int level = 0) const{
		if (node != nil) {
            _to_string(node->right,result, level + 1);
			result << std::string(level * 8, ' ');
            result << color_node_to_string(node->color) << ": " << node->key << " ";
			result << node->list->to_string();
			result << "\n";
            _to_string(node->left, result, level + 1);
		}
	}
	void clear_tree(Node* node) {
		if (node != nil) {
			clear_tree(node->left);
			clear_tree(node->right);

            delete node->list;
			delete node;
		}
	}
	
public:
	RB_tree() {
		nil = new Node;
        nil->color = ColorNode::black;
		nil->left = nil;
		nil->right = nil;
		nil->parent = nil;
        nil->list = new List<Value>;

		root = nil;
	}

	~RB_tree() {
		clear_tree(root);
        delete nil->list;
        delete nil;
	}
    RB_tree(const RB_tree&) = delete;
    RB_tree& operator=(const RB_tree&) = delete;

	std::string inorder_walk() const{ 
		if (root == nil) {
			return "empty tree\n";
		}

		std::stringstream result;
		_inorder_walk(root,result);

		return result.str();
	}

	std::string to_str() const override{
		if (root == nil) {
			return "empty tree\n";
		}

		std::stringstream result;
		_to_string(root, result);
		result << "\n";

		return result.str();
	}

	void print() const override{
		if (root == nil) {
			std::cout << "empty tree" << "\n";
			return;
		}

		_print(root);
	}

	void insert(const Key& key, const Value& value) override{
		Node* last_visit_node = nil;
		Node* current_node = root;

		while (current_node != nil) {
			last_visit_node = current_node;
			if (key < current_node->key) {
				current_node = current_node->left;
			}
			else if (key == current_node->key) {
				current_node->list->ascend_add(value);
				return;
			}
			else {
				current_node = current_node->right;
			}
		}

		Node* new_node = new Node;
		new_node->key = key;
		new_node->list = new List<Value>;
		new_node->list->ascend_add(value);
		new_node->parent = last_visit_node;

		if (last_visit_node == nil) {
			root = new_node;
		}
		else if (new_node->key < last_visit_node->key) {
			last_visit_node->left = new_node;
		}
		else {
			last_visit_node->right = new_node;
		}

		new_node->left = nil;
		new_node->right = nil;
        new_node->color = ColorNode::red;

		insert_fixup(new_node);
	}


	void erase(const Key& key, const Value& value) override{
        Node* del_node = _find_node(key);
		if (del_node == nil) {
            throw std::runtime_error("Не найден узел с заданным ключом в дереве.");
		}
		del_node->list->del_by_value(value);
		if (!del_node->list->empty()) {
			return;
		}


		Node* current_node = del_node;
        ColorNode current_node_color = current_node->color;
		Node* replacement_node;

		if (del_node->left == nil) {
			replacement_node = del_node->right;
			transplant(del_node, del_node->right);
		}
		else if (del_node->right == nil) {
			replacement_node = del_node->left;
			transplant(del_node, del_node->left);
		}
		else {
			current_node = minimum(del_node->right);
			current_node_color = current_node->color;
			replacement_node = current_node->right;

			if (current_node->parent == del_node) {
				replacement_node->parent = current_node;
			}
			else {
				transplant(current_node, current_node->right);
				current_node->right = del_node->right;
				current_node->right->parent = current_node;
			}

			transplant(del_node, current_node);
			current_node->left = del_node->left;
			current_node->left->parent = current_node;
			current_node->color = del_node->color;
		}

        if (current_node_color == ColorNode::black) {
			erase_fixup(replacement_node);
		}
		delete del_node->list;
		delete del_node;
	}

    Pair<unsigned int,const List<Value>&> find(const Key& key) const override{
		Node* current_node = root;
		unsigned int step = 1;
		while (current_node != nil) {
            if (key < current_node->key) {
				current_node = current_node->left;
				step += 1;
			}
            else if(key > current_node->key) {
				current_node = current_node->right;
				step += 1;
			}
            else {
                return Pair<unsigned int,  const List<Value>&>(step, *current_node->list);
            }
		}

        return Pair<unsigned int, const List<Value>&>(0, *nil->list);
	}

	void clear() override {
		clear_tree(root);
        root = nil;
	}
};