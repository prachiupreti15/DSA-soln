class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mpp; 
    RandomizedSet() {
    }

    bool insert(int val) {

        if (mpp.find(val) == mpp.end()) {
            v.push_back(val);
            mpp[val] = v.size() - 1;
            return true;
        }

        return false;
    }

    bool remove(int val) {

        if (mpp.find(val) != mpp.end()) {

            int idx = mpp[val];
            int last = v.back();

            v[idx] = last;
            mpp[last] = idx;

            v.pop_back();
            mpp.erase(val);

            return true;
        }

        return false;
    }

    int getRandom() {

        int idx = rand() % v.size();
        return v[idx];
    }
};