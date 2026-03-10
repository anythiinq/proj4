#include "multimap.h"
#include <string>

Multimap::Iterator::Iterator() : values({}), current_index(0)
{}

Multimap::Iterator::Iterator(std::vector<std::string> vals) : values(vals), current_index(0)
{}

bool Multimap::Iterator::next(std::string& value)
{
    if (current_index < values.size()) {
        value = values[current_index];
        current_index++;
        return true;
    } else {
        return false;                  // no more next .txt files for the key, we r done
    }
}


Multimap::Multimap() : root(nullptr), m_size(0)
{}

Multimap::~Multimap()
{
    destroyTree(root);
}

void Multimap::destroyTree(Node* curr)
{
    if (curr == nullptr)       // do nothing if there is nothing to delete
        return;
    
    destroyTree(curr->left);
    destroyTree(curr->right);
    delete curr;
}

void Multimap::put(const std::string& key, const std::string& value)
{
    if (root == nullptr) {
        root = new Node(key, value);
        m_size = 1;
        return;
    }
    
    Node* curr = root;
    while (curr != nullptr) {
        if (key < curr->key) {
            if (curr->left == nullptr) {
                curr->left = new Node(key, value);
                m_size++;
                return;
            }
            curr = curr->left;
        } else if (key > curr->key) {
            if (curr->right == nullptr) {
                curr->right = new Node(key, value);
                m_size++;
                return;
            }
            curr = curr->right;
        } else {
            for (int i = 0; i < curr->values.size(); i++) {
                if (value == curr->values[i])
                    return;
            }
            curr->values.push_back(value);
            m_size++;
            return;
        }
    }
}

MultimapBase::IteratorBase* Multimap::get(const std::string& key) const
{
    Node* curr = root;
    while (curr != nullptr) {
        if (key < curr->key) {
            curr = curr->left;
        } else if (key > curr->key) {
            curr = curr->right;
        } else {
            return new Iterator(curr->values);
        }
    }
    
    // if NOT found
	return new Iterator();
}

bool Multimap::empty() const
{
    return root == nullptr;
}

int Multimap::size() const
{
    return m_size;
}
