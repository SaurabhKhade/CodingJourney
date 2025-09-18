public class TaskManager {
    IDictionary<int, int> task_user;
    IDictionary<int, int> task_pr;
    PriorityQueue<(int priority, int taskId), (int priority, int taskId)> task_queue;

    public TaskManager(IList<IList<int>> tasks) {
        task_queue = new PriorityQueue<(int, int), (int, int)>();
        task_user = new Dictionary<int, int>();
        task_pr = new Dictionary<int, int>();

        foreach (var entry in tasks) {
            task_user[entry[1]] = entry[0];
            task_pr[entry[1]] = entry[2];
            task_queue.Enqueue((entry[2], entry[1]), (-entry[2], -entry[1]));
        }
    }
    
    public void Add(int userId, int taskId, int priority) {
        // Console.WriteLine("Add");
        task_user[taskId] = userId;
        task_pr[taskId] = priority;
        task_queue.Enqueue((priority, taskId), (-priority, -taskId));
    }
    
    public void Edit(int taskId, int newPriority) {
        // Console.WriteLine("Edit");
        task_pr[taskId] = newPriority;
        task_queue.Enqueue((newPriority, taskId), (-newPriority, -taskId));
    }
    
    public void Rmv(int taskId) {
        // Console.WriteLine("Rmv");
        task_pr[taskId] = -1;
    }
    
    public int ExecTop() {
        // Console.WriteLine("ExecTop");
        while (task_queue.Count > 0) {
            var (priority, task) = task_queue.Dequeue();

            if (task_pr[task] == priority) {
                task_pr[task] = -1;
                return task_user[task];
            }
        }

        return -1;
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.Add(userId,taskId,priority);
 * obj.Edit(taskId,newPriority);
 * obj.Rmv(taskId);
 * int param_4 = obj.ExecTop();
 */