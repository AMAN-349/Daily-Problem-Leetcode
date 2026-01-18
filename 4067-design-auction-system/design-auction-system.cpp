class AuctionSystem {
public:
    unordered_map<int,set<pair<int,int>>> m;
    unordered_map<int,unordered_map<int,int>> userBids;
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto& it=m[itemId];
        int user=userId;
        int bid=userBids[userId][itemId];
        if(bid!=-1){
            it.erase({bid,user});
        }
        it.insert({bidAmount,user});
        userBids[userId][itemId]=bidAmount;

    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int bid=userBids[userId][itemId];
        if(bid!=-1){
            m[itemId].erase({bid,userId});
        }
        m[itemId].insert({newAmount,userId});
        userBids[userId][itemId]=newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int bid=userBids[userId][itemId];
        m[itemId].erase({bid,userId});
        userBids[userId][itemId]=-1;
    }
    
    int getHighestBidder(int itemId) {
        if (!m.count(itemId) || m[itemId].empty())
            return -1;
        return m[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */