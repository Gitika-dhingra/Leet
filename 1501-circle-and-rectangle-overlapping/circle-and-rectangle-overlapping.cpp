class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1, min(xCenter, x2));
        int nearestY = max(y1, min(yCenter, y2));
        
        int deltaX = xCenter - nearestX;
        int deltaY = yCenter - nearestY;
        
        return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
    }
};