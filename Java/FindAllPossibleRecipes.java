import java.util.*;

public class FindAllPossibleRecipes {
    public List<String> findAllRecipes(
            String[] recipes,
            List<List<String>> ingredients,
            String[] supplies
    ) {
        // Store available supplies
        Set<String> availableSupplies = new HashSet<>();
        // Map recipe to its index
        Map<String, Integer> recipeToIndex = new HashMap<>();
        // Map ingredient to recipes that need it
        Map<String, List<String>> dependencyGraph = new HashMap<>();

        // Initialize available supplies
        for (String supply : supplies) {
            availableSupplies.add(supply);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.length; idx++) {
            recipeToIndex.put(recipes[idx], idx);
        }

        // Count of non-supply ingredients needed for each recipe
        int[] inDegree = new int[recipes.length];

        // Build dependency graph
        for (int recipeIdx = 0; recipeIdx < recipes.length; recipeIdx++) {
            for (String ingredient : ingredients.get(recipeIdx)) {
                if (!availableSupplies.contains(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph.putIfAbsent(
                            ingredient,
                            new ArrayList<String>()
                    );
                    dependencyGraph.get(ingredient).add(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Start with recipes that only need supplies
        Queue<Integer> queue = new LinkedList<>();
        for (int recipeIdx = 0; recipeIdx < recipes.length; recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.add(recipeIdx);
            }
        }

        // Process recipes in topological order
        List<String> createdRecipes = new ArrayList<>();
        while (!queue.isEmpty()) {
            int recipeIdx = queue.poll();
            String recipe = recipes[recipeIdx];
            createdRecipes.add(recipe);

            // Skip if no recipes depend on this one
            if (!dependencyGraph.containsKey(recipe)) continue;

            // Update recipes that depend on current recipe
            for (String dependentRecipe : dependencyGraph.get(recipe)) {
                if (--inDegree[recipeToIndex.get(dependentRecipe)] == 0) {
                    queue.add(recipeToIndex.get(dependentRecipe));
                }
            }
        }

        return createdRecipes;
    }
}
