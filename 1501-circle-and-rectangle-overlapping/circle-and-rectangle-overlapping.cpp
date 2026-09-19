class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int l=abs(x1-x2);
        int b=abs(y1-y2);

        int currx=x1;
        int curry=y1;

        if(xCenter>=x1 && xCenter<=x2 && yCenter>=y1 && yCenter<=y2)
        {
            return true;
        }

        for(int i=0;i<=l;i++)
        {
            int npx=currx+i;
            int npy=curry;

            int curr1=(npx-xCenter);
            curr1*=curr1;
            int curr2=(npy-yCenter);
            curr2*=curr2;

            int dist=sqrt(curr1+curr2);
            if(dist<=radius) return true;
        }

        for(int i=0;i<=b;i++)
        {
            int npx=currx;
            int npy=curry+i;

            int curr1=(npx-xCenter);
            curr1*=curr1;
            int curr2=(npy-yCenter);
            curr2*=curr2;

            int dist=sqrt(curr1+curr2);
            if(dist<=radius) return true;
        }

        currx=x2;
        curry=y2;

        for(int i=0;i<=l;i++)
        {
            int npx=currx-i;
            int npy=curry;

            int curr1=(npx-xCenter);
            curr1*=curr1;
            int curr2=(npy-yCenter);
            curr2*=curr2;

            int dist=sqrt(curr1+curr2);
            if(dist<=radius) return true;
        }

        for(int i=0;i<=b;i++)
        {
            int npx=currx;
            int npy=curry-i;

            int curr1=(npx-xCenter);
            curr1*=curr1;
            int curr2=(npy-yCenter);
            curr2*=curr2;

            int dist=sqrt(curr1+curr2);
            if(dist<=radius) return true;
        }

        return false;
    }
};