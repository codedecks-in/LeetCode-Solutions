class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        Map<Node, Node> map = new HashMap<>();
        Node current = head;

        // First pass: Create a copy of each node and store it in the map
        while (current != null) {
            map.put(current, new Node(current.val));
            current = current.next;
        }

        current = head;

        // Second pass: Connect the copied nodes' next and random pointers
        while (current != null) {
            Node copyNode = map.get(current);
            copyNode.next = map.get(current.next);
            copyNode.random = map.get(current.random);
            current = current.next;
        }

        return map.get(head);
    }
}