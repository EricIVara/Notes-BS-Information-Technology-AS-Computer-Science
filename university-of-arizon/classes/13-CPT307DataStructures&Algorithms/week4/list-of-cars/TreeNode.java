// TreeNode.java
import java.util.ArrayList;
import java.util.List;

public class TreeNode<T> {
    private T data;
    private List<TreeNode<T>> children;

    public TreeNode(T data) {
        this.data = data;
        this.children = new ArrayList<>();
    }

    // Getters and Setters
    public T getData() {
        return data;
    }

    public List<TreeNode<T>> getChildren() {
        return children;
    }

    public void addChild(TreeNode<T> child) {
        this.children.add(child);
    }

    // Method to add a node with its children, encapsulating the logic for tree manipulation
    public void addNodeWithChildren(T parentData, List<T> childrenData) {
        TreeNode<T> parentNode = findNode(this, parentData);
        if (parentNode == null) {
            parentNode = new TreeNode<>(parentData);
            this.addChild(parentNode); // This line was missing, now it adds the parent node to the tree.
        }
        for (T childData : childrenData) {
            parentNode.addChild(new TreeNode<>(childData));
        }
    }

    // Helper method to find a node
    public TreeNode<T> findNode(TreeNode<T> current, T data) {
        if (current.getData().equals(data)) {
            return current;
        }
        for (TreeNode<T> child : current.getChildren()) {
            TreeNode<T> found = findNode(child, data);
            if (found != null) {
                return found;
            }
        }
        return null;
    }
}
