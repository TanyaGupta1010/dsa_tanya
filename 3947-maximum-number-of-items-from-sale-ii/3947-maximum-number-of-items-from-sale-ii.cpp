class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long minPrice = 2e9;
        
        // 1. Count frequencies of each factor and find the cheapest item
        vector<int> factorFreq(n + 1, 0);
        for (const auto& item : items) {
            factorFreq[item[0]]++;
            minPrice = min(minPrice, (long long)item[1]);
        }
        
        // 2. Sieve-like step: count total items whose factor is a multiple of f
        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (factorFreq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                multiples[f] += factorFreq[m];
            }
        }
        
        // 3. Group valid "Buy 1 Get 1" deals by price (only if price < 2 * minPrice)
        map<long long, long long> deals;
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            if (p < 2 * minPrice) {
                long long freeCopies = multiples[f] - 1;
                if (freeCopies > 0) {
                    deals[p] += freeCopies;
                }
            }
        }
        
        // 4. Greedily take the cheapest 2-for-1 deals first
        long long totalItems = 0;
        long long remBudget = budget;
        
        for (auto& [price, count] : deals) {
            if (remBudget < price) break;
            long long canBuy = min(count, remBudget / price);
            totalItems += 2 * canBuy;
            remBudget -= canBuy * price;
        }
        
        // 5. Spend remaining budget on the single cheapest item
        totalItems += remBudget / minPrice;
        
        return totalItems;
    }
};