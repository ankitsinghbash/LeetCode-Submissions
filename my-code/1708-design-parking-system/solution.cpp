class ParkingSystem {
public:
    unordered_map<int,int> mp;
    ParkingSystem(int big, int medium, int small) {
        mp[1]=big;
        mp[2]=medium;
        mp[3]=small;
    }
    
    bool addCar(int carType) {
        auto it = mp.find(carType);
        if(it->second!=0){
            it->second--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
