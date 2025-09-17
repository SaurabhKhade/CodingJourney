public class FoodRatings
{
    private readonly IDictionary<string, (int rating, string cuisine)> fc;
    private readonly IDictionary<string, PriorityQueue<(int rating, string food), (int rating, string food)>> cf;

    public FoodRatings(string[] foods, string[] cuisines, int[] ratings)
    {
        fc = new Dictionary<string, (int, string)>();
        cf = new Dictionary<string, PriorityQueue<(int, string), (int, string)>>();

        var comparer = Comparer<(int rating, string food)>.Create(((int rating, string food) a, (int rating, string food) b) =>
        {
            if (a.rating != b.rating) return b.rating.CompareTo(a.rating);
            return a.food.CompareTo(b.food);
        });

        for (int i = 0; i < foods.Length; i++)
        {
            fc[foods[i]] = (ratings[i], cuisines[i]);

            if (!cf.ContainsKey(cuisines[i]))
            {
                cf[cuisines[i]] = new PriorityQueue<(int rating, string food), (int rating, string food)>(comparer);
            }

            cf[cuisines[i]].Enqueue((ratings[i], foods[i]), (ratings[i], foods[i]));
        }
    }

    public void ChangeRating(string food, int newRating)
    {
        fc[food] = (newRating, fc[food].cuisine);
        cf[fc[food].cuisine].Enqueue((newRating, food), (newRating, food));
    }

    public string HighestRated(string cuisine)
    {
        var peek = cf[cuisine].Peek();
        while (peek.rating != fc[peek.food].rating)
        {
            cf[cuisine].Dequeue();
            peek = cf[cuisine].Peek();
        }

        return peek.food;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.ChangeRating(food,newRating);
 * string param_2 = obj.HighestRated(cuisine);
 */