class Solution {
public:
    int hammingDistance(int x, int y) {
        
        /* Brute force */
        /*
        int res = 0, mask = 1;

        for(int i = 0; i < 32; i++)
        {
            if((x & mask) != (y & mask))
                res++;
            mask = mask << 1;
        }
        return res;
        */
        
        /* Bitset */
        /*
        bitset<32> res_set = bitset<32>(x^y);
        return res_set.count();
        */
        
        /* XOR without any built in function */
        int xor_res = x^y, dist = 0;
        
        while (xor_res) {
            if((xor_res>>1)<<1 != xor_res)
            {
                ++dist;
            }

            xor_res>>=1;
        }
        
        return dist;
    }
};