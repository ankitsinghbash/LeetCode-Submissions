class FoodRatings {
public:
    //Good Question now try to implement using priority queue:
    //time compleixty of the code is n*(log(m)): Overall space complexity is O(n*m)
    unordered_map<string,set<pair<int,string>>> mp;   //space (n*m)
    unordered_map<string,string> mp2;
    unordered_map<string,int> foodrating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            for(int i=0;i<cuisines.size();i++){
                string country = cuisines[i];
                string food = foods[i];
                int rating = ratings[i];
                mp[country].insert({-rating,food});
            }

            for(int i=0;i<foods.size();i++){
                string foo = foods[i];
                string country = cuisines[i];
                mp2[foo]=country;
                foodrating[foods[i]] = -ratings[i];
            }

    }
    
    void changeRating(string food, int newRating) {
        //find the country for the food:
       string country = mp2[food];
       set<pair<int,string>> &vec = mp[country];
       auto it = vec.find({foodrating[food],food});
       vec.erase(it);
       mp[country].insert({-newRating,food}); //In set pair iterator always find the value of the first position using find:
       foodrating[food] = -newRating; //reupdating the rating:
    }
    
    string highestRated(string cuisine) {
        // set<pair<int,string>> vec = mp[cuisine];
        // auto it = vec.begin();
        // pair<int,string> highestRated = *it;
        // return highestRated.second;
        auto highestRated = *mp[cuisine].begin();
        return highestRated.second;
    }
};

