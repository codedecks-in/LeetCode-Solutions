//Beats 99.91% of the solutions

public List<List<Integer>> combinationSum(int[] candidates, int target) {
    List<List<Integer>> solutions = new ArrayList<>();
    List<Inetger> solution = new ArrayList<>();
    solve(solutions, solution, candidates, target, 0);
    return solutions;
}
private static void solve(List<List<Integer>> solutions, List<Integer> solution, int[] candidates, int target, int start){
    if(target == 0) {
        solutions.add(new ArrayList<>(solution));
    }
    for(int i = start; i < candidates.length; i++){
        if(candidates[i] <= target){
            solution.add(candidates[i]);
            solve(solutions, solution, candidates, target - candidates[i], i);
            solution.remove(solution.size() - 1);
        }
    }
}
