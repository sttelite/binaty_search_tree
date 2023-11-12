#ifndef BST_H_
#define BST_H_

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <tuple>

namespace mff {

    class Bst {
    public:

        Bst();
        ~Bst() noexcept;
        Bst(const Bst& other);
        Bst& operator=(const Bst& other);
        Bst(Bst&& other);
        Bst& operator=(Bst&& other);

        void insert(std::string_view key);
        std::optional<std::string> erase(std::string_view key);
        bool contains(std::string_view key) const;
        std::vector<std::string> keys() const;

    private:
        enum class ChildType {
            Left,
            Right,
        };

        struct Node {
            Node(std::string_view key) : data(key) {}
            std::string data; 
            std::unique_ptr<Node> p_left; 
            std::unique_ptr<Node> p_right; 
        };

        using FindTuple = std::tuple<Node*, Node*, std::optional<ChildType>>;
        using FindMinPair = std::pair<Node*, Node*>;

        static FindTuple find_node(Node* p_par, Node* p_node, std::string_view target);
        static FindMinPair find_min(Node* p_par, Node* p_node);
        static std::vector<const Node*> get_sorted_nodes(const Node* p_node);

        // Internally represents the tree
        std::unique_ptr<Node> _p_tree;
    };
} // namespace mff

#endif // BST_H_
