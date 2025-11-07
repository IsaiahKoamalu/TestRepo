//
// Created by iskobr on 11/5/25.
//

#include <iosfwd>
#include <string>

class Node
{
    int data;
public:

    explicit Node(int d) : data(d) {}

    bool operator==(const Node &node)
    {
        return data == node.data;
    }

    bool operator<(const Node &node) const
    {
        return data < node.data;
    }

    bool operator>(const Node &node) const
    {
        return data > node.data;
    }

    friend std::ostream &operator<<(std::ostream &out, Node &node);
};

inline std::ostream &operator<<(std::ostream &out, Node &node)
{
    std::string dataS = std::to_string(node.data);
    out << dataS;
    return out;
}
