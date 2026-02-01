class RideSharingSystem {
public:
    queue<int> driver;
    queue<int> rider;
    set<int> s;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty())
        {
            return {-1,-1};
        }
        int a=rider.front();
        int b=driver.front();
        rider.pop();
        driver.pop();
        return {b,a};
    }
    
    void cancelRider(int riderId) {
        queue<int> temp;
        while(!rider.empty())
        {
            if(rider.front()!=riderId)
            {
                temp.push(rider.front());
            }
            rider.pop();
        }
        rider=temp;
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */