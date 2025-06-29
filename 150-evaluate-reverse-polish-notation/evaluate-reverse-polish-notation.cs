public class Solution {
    public int EvalRPN(string[] tokens) {
        var stack = new Stack<int>();

        foreach (var token in tokens) {
            if (token == "+") {
                var a = stack.Pop();
                var b = stack.Pop();
                stack.Push(a+b);
            }
            else if (token == "-") {
                var a = stack.Pop();
                var b = stack.Pop();
                stack.Push(b-a);
            }
            else if (token == "*") {
                var a = stack.Pop();
                var b = stack.Pop();
                stack.Push(a*b);
            }
            else if (token == "/") {
                var a = stack.Pop();
                var b = stack.Pop();
                stack.Push(b/a);
            }
            else {
                stack.Push(int.Parse(token));
            }
        }

        return stack.Peek();
    }
}