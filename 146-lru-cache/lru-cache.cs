class Node {
    public int Key {get; private set;}
    public int Value {get;set;}
    public Node Next {get;set;}
    public Node Prev {get;set;}

    public Node(int key, int value) {
        Key = key;
        Value = value;
    }
    public Node(int key, int value, Node next, Node prev) {
        Key = key;
        Value = value;
        Next = next;
        Prev = prev;
    }
}

public class LRUCache {
    private readonly Node Head;
    private readonly Node Tail;
    private readonly int Capacity;
    private int Size;
    private readonly IDictionary<int, Node> nodeMap;

    public LRUCache(int capacity) {
        Head = new Node(-1, -1, null, null);
        Tail = new Node(-1, -1, null, Head);

        Head.Next = Tail;
        
        Capacity = capacity;
        Size = 0;

        nodeMap = new Dictionary<int, Node>();
    }
    
    public int Get(int key) {
        if (nodeMap.ContainsKey(key)) {
            var node = nodeMap[key];
            Remove(node);
            Insert(node);

            return node.Value;
        }

        return -1;
    }

    public void Put(int key, int value) {
        if (nodeMap.ContainsKey(key)) {
            var node = nodeMap[key];
            node.Value = value;
            Remove(node);
            Insert(node);
        } else {
            if (Size == Capacity) {
                nodeMap.Remove(RemoveLast());
            }

            var node = new Node(key, value);
            Insert(node);
            nodeMap.Add(key, node);
        }

    }

    private void Insert(Node node) {
        node.Next = Head.Next;
        node.Prev = Head;
        Head.Next.Prev = node;
        Head.Next = node;
        Size++;
    }

    private void Remove(Node node) {
        node.Next.Prev = node.Prev;
        node.Prev.Next = node.Next;
        Size--;
    }

    private int RemoveLast() {
        var node = Tail.Prev;
        node.Prev.Next = Tail;
        Tail.Prev = node.Prev;
        Size--;

        return node.Key;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */