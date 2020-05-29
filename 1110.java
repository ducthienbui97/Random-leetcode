/**
 * leetcode 1110. Delete Nodes And Return Forest
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> to_delete_set = new HashSet<>();
        for(int val: to_delete) {
            to_delete_set.add(val);
        }
        List<TreeNode> nodes = new ArrayList<>();
        delNodes(root, to_delete_set, nodes, true);
        return nodes;
    }
    private TreeNode delNodes(TreeNode root, Set<Integer> to_delete, List<TreeNode> nodes, boolean addRoot) {
        if(root == null) {
            return null;
        }
        if(to_delete.contains(root.val)) {
            delNodes(root.left, to_delete, nodes, true);
            delNodes(root.right, to_delete, nodes, true);
            return null;
        }
        else {
            if(addRoot){
                nodes.add(root);
            }
            root.left = delNodes(root.left, to_delete, nodes, false);
            root.right = delNodes(root.right, to_delete, nodes, false);
        }
        return root;
    }
}
