public class Node {
    public string word;
    public bool isEnd;
    public readonly IDictionary<string, Node> map;

    public Node(string w) {
        word = w;
        isEnd = false;
        map = new Dictionary<string, Node>();
    }

    public Node(string w, bool end) {
        word = w;
        isEnd = end;
        map = new Dictionary<string, Node>();
    }
}

public class Solution {
    public IList<string> RemoveSubfolders(string[] folder) {
        Node root = new Node(string.Empty);
        var result = new List<string>();

        Array.Sort(folder);

        foreach (var path in folder) {
            var dirs = path.Split('/');

            bool isSub = false;
            var temp = root;
            for (var i=0; i<dirs.Length; i++) {
                if (temp.isEnd) {
                    isSub = true;
                    break;
                }

                if (!temp.map.ContainsKey(dirs[i])) {
                    temp.map[dirs[i]] = new Node(dirs[i]);
                }
                temp = temp.map[dirs[i]];
            }

            if (!isSub) {
                temp.isEnd = true;
                result.Add(path);
            }
        }

        return result;
    }
}