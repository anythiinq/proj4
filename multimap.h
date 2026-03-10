#ifndef MULTIMAP_H
#define MULTIMAP_H

#include "provided.h"
#include <string>

// headers i added !!
#include <vector>

class Multimap : public MultimapBase
{
public:
    // Nested Iterator class
    class Iterator : public MultimapBase::IteratorBase
    {
    public:
        Iterator();
        Iterator(std::vector<std::string> vals);
        virtual bool next(std::string& value);  // gives next value but returns false when done

    private:
        std::vector<std::string> values;  // all values for a key
        int current_index;                // where we are at rn
    };

    Multimap();
    virtual ~Multimap();
    virtual void put(const std::string& key, const std::string& value);
    virtual MultimapBase::IteratorBase* get(const std::string& key) const;
    virtual bool empty() const;
    virtual int size() const;

private:

    struct Node {
        std::string key;
        std::vector<std::string> values;
        Node* left;
        Node* right;
        
        Node(const std::string& k, const std::string& v) { key = k; values.push_back(v); }
    };
    
    Node* root; // the root -> top of the tree
    int m_size;
    
    void destroyTree(Node* curr); // helper function for the destructor
};

#endif // MULTIMAP_H
