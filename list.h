#pragma once
#include <iostream>
#include <sstream>

template<typename T>
class List {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;

    void push_back(const T& value) {
        Node* new_node = new Node;
        new_node->value = value;

        if (head == nullptr) {
            new_node->prev = new_node;
            new_node->next = new_node;
            head = new_node;

            return;
        }

        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
    }

public:

    List() : head(nullptr) {};

    ~List() {
        clear();
    }

    class ForwardIterator {
    private:
        const Node* current;
        const Node* head_ref;
        bool is_end;

    public:
        ForwardIterator(const Node* node, const Node* head, bool end): current(node), head_ref(head), is_end(end){}

        const T& operator*() const {
            if (head_ref == nullptr) {
                throw std::runtime_error("cannot get value, list is empty");
            }
            return current->value;
        }

        ForwardIterator& operator++() {
            if (head_ref == nullptr) {
                throw std::runtime_error("iteration impossible, list is empty");
            }
            current = current->next;
            if (current == head_ref) {
                is_end = true;
            }
            return *this;
        }

        ForwardIterator operator++(int) {
            if (head_ref == nullptr) {
                throw std::runtime_error("iteration impossible, list is empty");
            }
            ForwardIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const ForwardIterator& other) const {
            if (head_ref == nullptr) {
                return false;
            }
            return (current != other.current) || (is_end != other.is_end);
        }
        bool operator==(const ForwardIterator& other) const {
            if (head_ref == nullptr) {
                return true;
            }
            return (current == other.current) && (is_end == other.is_end);
        }
    };

    ForwardIterator begin() const {
        return ForwardIterator(head,head, false);
    }

    ForwardIterator end() const {
        return ForwardIterator(head,head, true);
    }

    void ascend_add(const T& value) {
        Node* new_node = new Node;
        new_node->value = value;

        if (head == nullptr) {
            new_node->prev = new_node;
            new_node->next = new_node;
            head = new_node;

            return;
        }

        if (head->value > value) {
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev->next = new_node;
            head->prev = new_node;
            head = new_node;
            return;
        }

        Node* current_node = head;
        while (current_node->next->value < value && current_node->next != head) {
            current_node = current_node->next;
        }

        new_node->next = current_node->next;
        new_node->prev = current_node;
        current_node->next->prev = new_node;
        current_node->next = new_node;

        return;
    }

    const T& get_element(int index)const{
        if(index < 0){
            throw std::runtime_error("invalid index");
        }
        if(head == nullptr){
            throw std::runtime_error("empty list");
        }
        if(index == 0){
            return head->value;
        }

        Node* current_node = head->next;
        int i = 1;
        while(current_node != head && i < index){
            current_node = current_node->next;
            i++;
        }

        if(i != index || current_node == head){
            throw std::runtime_error("invalid index");
        }

        return current_node->value;
    }

    void del_by_value(const T& value) {
        if (head == nullptr) {
            throw std::runtime_error("empty list");
        }

        Node* current_node = head->next;
        while (current_node != head) {
            if (current_node->value == value) {
                current_node->prev->next = current_node->next;
                current_node->next->prev = current_node->prev;

                Node* temp = current_node;
                current_node = current_node->next;
                delete temp;
            }
            else {
                current_node = current_node->next;
            }
        }

        if (head->value == value && head->next == head) {
            delete head;
            head = nullptr;
        }
        else if (head->value == value) {
            head->prev->next = head->next;
            head->next->prev = head->prev;

            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void del_first_entry(const T& value) {
        if (head == nullptr) {
            throw std::runtime_error("empty list");
        }

        if (head->value == value && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        if (head->value == value) {
            head->prev->next = head->next;
            head->next->prev = head->prev;

            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current_node = head;
        current_node = current_node->next;
        while (current_node != head) {
            if (current_node->value == value) {
                current_node->prev->next = current_node->next;
                current_node->next->prev = current_node->prev;

                delete current_node;
                return;
            }
            current_node = current_node->next;
        }
        throw std::runtime_error("not found value in list");
    }

    void pop_back() {
        if (head == nullptr) {
            throw std::runtime_error("empty list");
        }
        if (head == head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* del_node = head->prev;
        del_node->prev->next = head;
        head->prev = del_node->prev;
        delete del_node;
    }

    bool empty() const {
        return head == nullptr;
    }


    void clear() {
        if (head != nullptr) {
            Node* current_node = head->next;
            while (current_node != head) {
                Node* temp = current_node;
                current_node = current_node->next;
                delete temp;
            }
            delete head;
            head = nullptr;
        }
    }

    void print() const {
        Node* current_node = head;
        if (head == nullptr) {
            std::cout << "[]" << "\n";
            return;
        };

        std::cout << "[";
        std::cout << head->value;

        current_node = current_node->next;
        while (current_node != head) {
            std::cout << "," << current_node->value;
            current_node = current_node->next;
        }
        std::cout << "]" << "\n";
    }

    std::string to_string() const {
        std::stringstream result;

        Node* current_node = head;
        if (head == nullptr) {
            return "[]";
        };

        result << "[";
        result << head->value;

        current_node = current_node->next;
        while (current_node != head) {
            result << "," << current_node->value;
            current_node = current_node->next;
        }
        result << "]";

        return result.str();
    }
};